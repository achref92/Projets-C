#include <stdio.h>
#include <string.h>
#include "fonctions.h"
#include <gtk/gtk.h>


void afficher ()
{
	FILE *f;
	f=fopen("/home/achref/Bureau/skytravel19/src/users.txt","r");
	char login[20],password[20];
	int role;
	while(fscanf(f,"%s %s %d",login,password,&role) !=EOF){
		printf("%s %s %d\n", login, password,role);
	}
	fclose(f);
}

int verifier (char login [], char password [])
{
	FILE *f;
	f=fopen("/home/achref/Bureau/skytravel19/src/users.txt","r");
	int role=-1;
	int role1;
	char login1[20],password1[20];
	while (fscanf(f,"%s %s %d\n",login1, password1, &role1)!=EOF) {
		if (strcmp(login1,login)==0 && strcmp (password1,password)==0)
		{
			role = role1;
			return role;
		}
	}
	fclose(f);
	return (role);
}
// achref

enum
{
    TYPE_OFFRE, 
    LOCALITE_OFFRE,
    DATE_EXPIRATION,
    PRIX, 
    QUANTITE, 
    IDENTIFIANT_OFFRE,
    COLUMNS
};


//Ajouter

void ajouter_o(Offre o)
{

 FILE *h;
 h=fopen("/home/achref/Bureau/skytravel19/src/offre.txt","a+"); 
 if(h!=NULL)
 {
 fprintf(h,"%s %s %s %s %s %s\n",o.type_offre,o.localite_offre,o.date_expiration,o.prix,o.quantite,o.identifiant_offre); 
 fclose(h);

}
}

//Afficher


void afficher_o(GtkWidget *liste)
{
   GtkCellRenderer *renderer; 

   GtkTreeViewColumn *column;

   GtkTreeIter iter;

   GtkListStore *store;

   char type_offre[20]; 
   char localite_offre[20]; 
   char date_expiration[30];
   char prix[30];
   char quantite[10];
   char identifiant_offre[10];
   store=NULL;

   FILE *h;
   store = gtk_tree_view_get_model(liste);
   if (store==NULL)


      renderer = gtk_cell_renderer_text_new ();  
      column = gtk_tree_view_column_new_with_attributes(" type_offre", renderer, "text",TYPE_OFFRE, NULL); 
      gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes(" localite_offre", renderer, "text",LOCALITE_OFFRE, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column); 

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes(" date_expiration", renderer, "text",DATE_EXPIRATION, NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes(" prix", renderer, "text",PRIX, NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes(" quantite", renderer, "text",QUANTITE, NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes(" identifiant_offre", renderer, "text",IDENTIFIANT_OFFRE, NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

  h = fopen("/home/achref/Bureau/skytravel19/src/offre.txt", "r"); 

  if(h==NULL)
  {
    return;
  }
  else

  { h = fopen("/home/achref/Bureau/skytravel19/src/offre.txt", "a+");
  while((fscanf(h,"%s %s %s %s %s %s \n",type_offre,localite_offre,date_expiration,prix,quantite,identifiant_offre)!= EOF))
    {
  gtk_list_store_append (store, &iter);

  gtk_list_store_set (store, &iter, TYPE_OFFRE, type_offre, LOCALITE_OFFRE, localite_offre, DATE_EXPIRATION, date_expiration,PRIX,prix,QUANTITE,quantite,IDENTIFIANT_OFFRE,identifiant_offre, -1);
    }
    fclose(h);
  gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store)); 
  g_object_unref (store);
  }
}

// achref terminer
//wassim
//remplir tableau de structure
int tableau_Offre(Offre tab[])
 {
int n=0;
FILE* f=fopen("/home/achref/Bureau/skytravel19/src/offre.txt","r");
if(f!=NULL)
{
while(fscanf(f,"%s %s %s %s %s %s\n",tab[n].type_offre,tab[n].localite_offre,tab[n].date_expiration,tab[n].prix,tab[n].quantite,tab[n].identifiant_offre)!=EOF)
{ n++;}
fclose(f);
} 
return n;
} 
//fin remplir tab

//ajout a un tableau
enum
{
IDENTIFIANTDEOFFRE,
DATERESERVER,
NBREPERSONNE,
COLS
};

//affiche
void affiche_client(GtkWidget *lista)
{
   GtkCellRenderer *renderer; 

   GtkTreeViewColumn *column;

   GtkTreeIter iter;

   GtkListStore *store;

  char identifiantdeoffre[20]; 
   char datereserver[20]; 
   char nbrepersonne[30];

   store=NULL;

   FILE *h;
   store = gtk_tree_view_get_model(lista);
   if (store==NULL)


      renderer = gtk_cell_renderer_text_new ();  
      column = gtk_tree_view_column_new_with_attributes(" identifiantdeoffre", renderer, "text",IDENTIFIANTDEOFFRE, NULL); 
      gtk_tree_view_append_column (GTK_TREE_VIEW (lista), column);


renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes(" datereserver", renderer, "text",DATERESERVER, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (lista), column); 

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes(" nbrepersonne", renderer, "text",NBREPERSONNE, NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (lista), column);




store=gtk_list_store_new (COLS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

  h = fopen("/home/achref/Bureau/skytravel19/src/client.txt", "r"); 

  if(h==NULL)
  {
    return;
  }
  else

  { h = fopen("/home/achref/Bureau/skytravel19/src/client.txt", "a+");
  while((fscanf(h,"%s %s %s\n",identifiantdeoffre,datereserver, nbrepersonne)!= EOF))
    {
  gtk_list_store_append (store, &iter);

  gtk_list_store_set (store, &iter,IDENTIFIANTDEOFFRE,identifiantdeoffre,DATERESERVER,datereserver,NBREPERSONNE, nbrepersonne, -1);
    }
    fclose(h);
  gtk_tree_view_set_model (GTK_TREE_VIEW (lista), GTK_TREE_MODEL (store)); 
  g_object_unref (store);
  }
}
//fin ajout tableau
// taille tbleau client
//ajouter
void ajouter_offre1(Client c)
{

 FILE *f;
 f=fopen("/home/achref/Bureau/skytravel19/src/client.txt","a+"); 
 if(f!=NULL)
 {
 fprintf(f,"%s %s %s\n",c.identifiantdeoffre,c.datereserver,c.nbrepersonne); 
 fclose(f);
}
}
//
int tableau_Client(Client u[200])
 {
int n=0;
FILE* f=fopen("/home/achref/Bureau/skytravel19/src/client.txt","r");
if(f!=NULL)
{
while(fscanf(f,"%s %s %s\n",u[n].identifiantdeoffre,u[n].datereserver,u[n].nbrepersonne)!=EOF)
{ n++;}
fclose(f);
} 
return n;
} 

//test
int test(char ch[20],char ch1[20])
{int i;
if (strlen(ch)!=strlen(ch1))
return 0;
for(i=0;i<strlen(ch);i++)
if(ch[i]!=ch1[i])
return 0;
return 1;
}

//recherche
int recherche(Offre tab[200],char ch[20])
{int i;
int n;
n=tableau_Offre(tab);
for(i=0;i<n;i++)
if(test(tab[i].identifiant_offre,ch)==1)
return 1;
return 0;
}

//rechercheplace
int rechercheplace(Offre tab[200],char ch[20])
{int i;
int n=tableau_Offre(tab);
for(i=0;i<n;i++)
if(test(tab[i].identifiant_offre,ch)==1)
{return i;}
return -1;

}


//decrementation
void decrementation(Offre tab[200],char ch[20],char ch1[20])
{int a,b;
int n=tableau_Offre(tab);
int i=rechercheplace(tab,ch1);
if(i!=-1)
{sscanf(tab[i].quantite,"%d",&a);
sscanf(ch,"%d",&b);
if(a>0)
{
a=a-b;

}
}
sprintf(tab[i].quantite,"%d",a);
reecriver1(tab,n);
}



void reecriver1(Offre tab[200],int n)
{int i;
 FILE *f;
 f=fopen("/home/achref/Bureau/skytravel19/src/offre.txt","w"); 

for(i=0;i<n;i++)
 {
 fprintf(f,"%s %s %s %s %s %s\n",tab[i].type_offre,tab[i].localite_offre,tab[i].date_expiration,tab[i].prix,tab[i].quantite,tab[i].identifiant_offre); 
 
}
fclose(f);
}





//modifier
void modifind(Client u[200],char ch[20],char ch1[20],char ch2[20])

{int n=tableau_Client(u);
Client c;
int i=rechercheplace1(u,ch2,n);
if(i!=-1)
{strcpy(u[i].nbrepersonne,ch);

strcpy(u[i].datereserver,ch1);


}
reecriver(u,n);

}

//recherche
int recherche1(Client u[200],char ch[20])
{int i;
int n;
n=tableau_Client(u);
printf("n=%d",n);
for(i=0;i<n;i++)
if(test(u[i].identifiantdeoffre,ch)==1)
return 1;
return 0;
}

//rechercheplace1
int rechercheplace1(Client u[200],char ch[20],int n)
{int i;

for(i=0;i<n;i++)
if(test(u[i].identifiantdeoffre,ch)==1)
{return i;}
return -1;
}

void reecriver(Client u[200],int n)
{int i;
 FILE *f;
 f=fopen("/home/achref/Bureau/skytravel19/src/client.txt","w"); 

for(i=0;i<n;i++)
 {
 fprintf(f,"%s %s %s\n",u[i].identifiantdeoffre,u[i].datereserver,u[i].nbrepersonne); 
 
}
fclose(f);
}
//supression
void supprime(Client u[200],char ch[20])
{int n=tableau_Client(u);
int i=rechercheplace1(u,ch,n);
Client x;
if(i!=-1)
{x=u[i];
u[i]=u[n-1];
u[n-1]=x;
reecriver(u,n-1);
}
}

//fin wassim
//achref

int verifier_o (Offre o1)
{
Offre o;
FILE *k1;
int testeur =0;
k1=fopen("/home/achref/Bureau/skytravel19/src/offre.txt","r");
while (fscanf(k1,"%s %s %s %s %s %s\n",o.type_offre,o.localite_offre,o.date_expiration,o.prix,o.quantite,o.identifiant_offre)!=EOF) 
  {
if (strcmp(o.identifiant_offre,o1.identifiant_offre)==0)
testeur =1;
   }
fclose(k1);
return testeur;
}


void modifier_o (Offre o1)
{
	Offre o;
	FILE *f1, *tmp;
	f1=fopen("/home/achref/Bureau/skytravel19/src/offre.txt","r");
	tmp=fopen("/home/achref/Bureau/skytravel19/src/offre.tmp","a+");
	while(fscanf(f1,"%s %s %s %s %s %s\n",o.type_offre,o.localite_offre,o.date_expiration,o.prix,o.quantite,o.identifiant_offre)!=EOF){
		if(strcmp(o.identifiant_offre,o1.identifiant_offre)==0){fprintf(tmp,"%s %s %s %s %s %s\n",o1.type_offre,o1.localite_offre,o1.date_expiration,o1.prix,o1.quantite,o1.identifiant_offre);}
		else fprintf(tmp,"%s %s %s %s %s %s\n",o.type_offre,o.localite_offre,o.date_expiration,o.prix,o.quantite,o.identifiant_offre);
}
fclose(f1);
fclose(tmp);
rename("/home/achref/Bureau/skytravel19/src/offre.tmp","/home/achref/Bureau/skytravel19/src/offre.txt");
}

int verifier_os (char id_o[])
{
Offre o;
FILE *k1;
int testeur1 =0;
k1=fopen("/home/achref/Bureau/skytravel19/src/offre.txt","r");
while (fscanf(k1,"%s %s %s %s %s %s\n",o.type_offre,o.localite_offre,o.date_expiration,o.prix,o.quantite,o.identifiant_offre)!=EOF) 
  {
if (strcmp(o.identifiant_offre,id_o)==0)
testeur1 =1;
   }
fclose(k1);
return testeur1;
}


void supprimer_o (char identifiant[])
{
	Offre o;
	FILE *f2, *tmp;
	f2=fopen("/home/achref/Bureau/skytravel19/src/offre.txt","r");
	tmp=fopen("/home/achref/Bureau/skytravel19/src/offre.tmp","a+");
	while(fscanf(f2,"%s %s %s %s %s %s\n",o.type_offre,o.localite_offre,o.date_expiration,o.prix,o.quantite,o.identifiant_offre)!=EOF){
		if(strcmp(o.identifiant_offre,identifiant)==0) {continue;}
else fprintf(tmp,"%s %s %s %s %s %s\n",o.type_offre,o.localite_offre,o.date_expiration,o.prix,o.quantite,o.identifiant_offre);
}
fclose(f2);
fclose(tmp);
rename("/home/achref/Bureau/skytravel19/src/offre.tmp","/home/achref/Bureau/skytravel19/src/offre.txt");
}

// mouad

void ajouter(char nom[],char prenom[],char username[],char password[],char CIN[],char adresse[],char date[])
{	FILE *f,*g;
	f=fopen("/home/achref/Bureau/skytravel19/src/uses.txt","a+");
	g=fopen("/home/achref/Bureau/skytravel19/src/users.txt","a+");
	if(f!=NULL) {
		fprintf(f,"%s %s %s %s %s %s %s \n",nom,prenom,username,password,CIN,adresse,date);
	fprintf(g,"%s %s %d \n",username,password,3);
	}
	fclose(f);
	fclose(g);
	}


void supprimer(char CIN[])
{
	char nomm[20],prenomm[20],usernamem[20],passwordm[20],CINm[20],adressem[20],datem[20];
	FILE *f, *g,*h,*k;
	f=fopen("/home/achref/Bureau/skytravel19/srcc/uses.txt","r");
	g=fopen("/home/achref/Bureau/skytravel19/src/uses1.txt","w");
	h=fopen("/home/achref/Bureau/skytravel19/src/users.txt","r");
	k=fopen("/home/achref/Bureau/skytravel19/src/users1.txt","w");
	while(fscanf(f,"%s %s %s %s %s %s %s \n",nomm,prenomm,usernamem,passwordm,CINm,adressem,datem)!=EOF){
		if(!strcmp(CIN,CINm)) {continue;}
else {fprintf(g,"%s %s %s %s %s %s %s\n",nomm,prenomm,usernamem,passwordm,CINm,adressem,datem);
fprintf(k,"%s %s %d \n",usernamem,passwordm,2);

}
}
fclose(f);
fclose(g);
fclose(h);
fclose(k);
remove("/home/achref/Bureau/skytravel19/src/uses.txt");
remove("/home/achref/Bureau/skytravel19/src/users.txt");
rename("/home/achref/Bureau/skytravel19/src/uses1.txt","/home/achref/Bureau/skytravel19/src/uses.txt");
rename("/home/achref/Bureau/skytravel19/src/users1.txt","/home/achref/Bureau/skytravel19/src/users.txt");
}



void modifier(char nom[],char prenom[],char username[],char password[],char CIN[],char adresse[],char date[])
{
	char nomm[20],prenomm[20],usernamem[20],passwordm[20],CINm[20],adressem[20],datem[20];
	FILE *f, *g,*h,*k;
	f=fopen("/home/achref/Bureau/skytravel19/src/uses.txt","r");
	g=fopen("/home/achref/Bureau/skytravel19/src/uses1.txt","w+");
	h=fopen("/home/achref/Bureau/skytravel19/src/users.txt","r");
	k=fopen("/home/achref/Bureau/skytravel19/src/users1.txt","w+");
	while(fscanf(f,"%s %s %s %s %s %s %s \n",nomm,prenomm,usernamem,passwordm,CINm,adressem,datem)!=EOF){
		if(!strcmp(CIN,CINm)) {fprintf(g,"%s %s %s %s %s %s %s\n",nom,prenom,username,password,CIN,adresse,date);
fprintf(k,"%s %s %d \n",username,password,2);
}
		else {fprintf(g,"%s %s %s %s %s %s %s\n",nomm,prenomm,usernamem,passwordm,CINm,adressem,datem);
fprintf(k,"%s %s %d \n",usernamem,passwordm,2);
}
}
fclose(f);
fclose(g);
fclose(h);
fclose(k);
remove("/home/achref/Bureau/skytravel19/src/uses.txt");
remove("/home/achref/Bureau/skytravel19/src/users.txt");
rename("/home/achref/Bureau/skytravel19/src/uses1.txt","/home/achref/Bureau/skytravel19/src/uses.txt");
rename("/home/achref/Bureau/skytravel19/src/users1.txt","/home/achref/Bureau/skytravel19/src/users.txt");

}
void afficher_client(GtkWidget *liste)
{	
	enum { NOM,
       PRENOM,
       USERNAME,
       PASSWORD,CIN,ADRESSE,DATE,
       COLUMNS
      };
  	GtkCellRenderer *renderer; 

	GtkTreeViewColumn *column;

	GtkTreeIter iter;

   	GtkListStore *store;

   	char nom [30];
  	char prenom [30]; 
   	char username [30];
   	char password [30]; 
   	char cin[30];
   	char adresse[30];
   	char date[30];
   	store=NULL;
	FILE *f;
   store = gtk_tree_view_get_model(liste);
   if (store==NULL)


      renderer = gtk_cell_renderer_text_new ();  
      column = gtk_tree_view_column_new_with_attributes(" nom", renderer, "text",NOM, NULL); 
      gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes(" prenom", renderer, "text",PRENOM, NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes(" username", renderer, "text",USERNAME, NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes(" password", renderer, "text",PASSWORD, NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes(" cin", renderer, "text",CIN, NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes(" adresse", renderer, "text",ADRESSE, NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes(" date", renderer, "text",DATE, NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

  f = fopen("/home/achref/Bureau/skytravel19/src/uses.txt", "r"); 

  if(f==NULL)
  {
    return 0 ;
  }
  else

  { f = fopen("/home/achref/Bureau/skytravel19/src/uses.txt", "a+");
       while((fscanf(f,"%s %s %s %s %s %s %s \n",nom,prenom,username,password,cin,adresse,date)!= EOF))
    {
  gtk_list_store_append (store, &iter);

  gtk_list_store_set (store, &iter, NOM, nom, PRENOM, prenom, USERNAME, username,PASSWORD,password,CIN,cin,ADRESSE,adresse,DATE,date, -1);
    }
    fclose(f);
  gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store)); 
  g_object_unref (store);
  }
}
//fin mouadh
