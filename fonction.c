#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonction.h"
#include <gtk/gtk.h>

enum
{
CIN,
NOM,
PRENOM,
ROLE,
SEXE,
COLUMNS
};




//Ajouter une personne
void 
ajouter_personne (Personne p)
{
FILE *f=NULL;
f=fopen("users.txt","a+");
if(f!=NULL)
{
fprintf(f,"%s %s %s %s %s %s %s\n",p.username,p.password,p.nom,p.prenom,p.cin,p.sexe,p.role);
fclose(f);
}
}

int verif(char username[],char password[]){
Personne p;

int trouve=0;

FILE *f=NULL;
f=fopen("users.txt","r");
if(f!=NULL){

while (fscanf(f,"%s %s\n",p.username,p.password)!=EOF)
{if((strcmp(username,p.username)==0)&&(strcmp(password,p.password)==0))
trouve=1;
}
fclose(f);}
return (trouve);}


// Afficher une personne + creation du treeview
void afficher_personne (GtkWidget *liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

char nom[30];
char prenom[30];
char cin[30];
char sexe[30];
char role[30];
char username[30];
char password[30];
store=NULL;
FILE *f=NULL;

store=gtk_tree_view_get_model(liste);

if (store==NULL)
{
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("nom", renderer, "text",NOM, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("prenom", renderer, "text",PRENOM, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("cin", renderer, "text",CIN, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("sexe", renderer, "text",SEXE, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("role", renderer, "text",ROLE, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
f=fopen("users.txt","r");

if(f==NULL)
{
return;
}
else
{ f = fopen("users.txt","a+");
while(fscanf(f,"%s %s %s %s %s %s %s\n",username,password,nom,prenom,cin,sexe,role)!=EOF)
{
gtk_list_store_append (store, &iter);
gtk_list_store_set (store, &iter, NOM, nom, PRENOM, prenom, CIN, cin,SEXE, sexe, ROLE, role,-1);
}
fclose(f);
gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
g_object_unref (store);
}
}
}

//verif par cin
int verif1(char cin[]){
Personne p;

int trouve1=0;

FILE *f=NULL;
f=fopen("users.txt","r");
if(f!=NULL){

while (fscanf(f,"%s\n",p.cin)!=EOF)
{if((strcmp(cin,p.cin)==0)==0)
trouve1=1;
}
fclose(f);}
return (trouve1);

}

//modifier une personne


void modifier(Personne p)
{
	
	
	Personne c;
	FILE *f;
	FILE *m;
     	f=fopen("users.txt","r");
	m=fopen("edit.txt","a");
	
	
		
		while(fscanf(f,"%s %s %s %s %s %s %s\n",c.username,c.password,c.nom,c.prenom,c.cin,c.sexe,c.role)!=EOF)
				if (strcmp(c.cin,p.cin)!=0)
				{
					
					fprintf(m,"%s %s %s %s %s %s %s\n",c.username,c.password,c.nom,c.prenom,c.cin,c.sexe,c.role);
				}
				else
				{
					fprintf(m,"%s %s %s %s %s %s %s\n",p.username,p.password,p.nom,p.prenom,p.cin,p.sexe,p.role);
				}
			
				
		fclose(f);
		fclose(m);
		remove("users.txt");
		rename("edit.txt","users.txt");
	

}



//Supprimer une personne
void supprimer_personne (Personne p)
{
char username[30];
char password[30];
char nom[30];
char prenom[30];
char cin[30];
char sexe[30];
char role[30];


Personne p2;
FILE *f,*g;
f=fopen("users.txt","r");
g=fopen("del.txt","w");

if(f==NULL || g==NULL)
{
return;
}
else{
while(fscanf(f,"%s %s %s %s %s %s %s\n",p2.username,p2.password,p2.nom,p2.prenom,p2.cin,p2.sexe,p2.role)!=EOF)
{
if(strcmp(p.cin,p2.cin)!=0) 
{fprintf(g,"%s %s %s %s %s %s %s\n",p2.username,p2.password,p2.nom,p2.prenom,p2.cin,p2.sexe,p2.role);}
}
fclose(f);
fclose (g);
remove("users.txt");
rename("del.txt","users.txt");
}
}



//Rechercher une personne
int chercher_personne(char cin[],char nom[], char prenom[] , char sexe[] , char role[])
{
Personne p;
int found=0;
FILE *f=fopen("users.txt","r");
if(f!=NULL)
{
while (fscanf(f,"%s %s %s %s %s %s %s\n" ,p.username,p.password,p.nom,p.prenom,p.cin,p.sexe,p.role)!=EOF)
{
if(strcmp(cin,p.cin)==0)
{

found=1;}}
fclose(f);
return found;
}

}

//affichage clic recherche
void affichage_recherche(GtkWidget *liste ,char nom1[],char prenom1[], char cin1[],char sexe1[],char role1[])
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter *iter;
GtkListStore *store;

char cin[20];
char nom[20];
char prenom[30];
char role[30];
char sexe[30];
char username[30];
char password[30];

store=NULL;
FILE *f;

store=gtk_tree_view_get_model(liste);

if (store==NULL)
{
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("nom", renderer, "text",NOM, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("prenom", renderer, "text",PRENOM, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("cin", renderer, "text",CIN, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("sexe", renderer, "text",SEXE, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("role", renderer, "text",ROLE, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
f=fopen("users.txt","r");

if(f==NULL)
{
return;
}
else
{ f = fopen("users.txt","a+");
while(fscanf(f,"%s %s %s %s %s %s %s\n",username,password,nom,prenom,cin,sexe,role)!=EOF)
{if (strcmp(cin1,cin)==0)
{

gtk_list_store_append (store, &iter);
gtk_list_store_set (store, &iter, NOM, nom, PRENOM, prenom, CIN, cin,SEXE, sexe, ROLE, role,-1);
}






}
fclose(f);
gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
g_object_unref (store);
}
}


}




/////////////////////////////////////////////////////////////////tache dashboard


enum
{
JOUR,
HEURE,
NUM,
VAL,
COLUMNS1
};

//lecture des alarmes conditions
void alarme(){
	FILE *m,*f,*a;
	capteurs c;

int valeur;	
int heure ;
	m=fopen("mouvement.txt","r");
	f=fopen("fumee.txt","r");
	a=fopen("alarme.txt","w+");
	if(m!=NULL && f!=NULL && a!=NULL){


		while(fscanf(f,"%s %s %s %d\n",c.jour,c.heure,c.num,&valeur)!=EOF){
			if(valeur==1){
				fprintf(a,"%s %s %s %d\n",c.jour,c.heure,c.num,valeur);
			}
		}







		while(fscanf(m,"%s %d %s %d",c.jour,&heure,c.num,&valeur)!=EOF){
			if(     ((heure<=6)||(heure==24)) && (valeur==1)           ) {
				fprintf(a,"%s %d %s %d\n",c.jour,heure,c.num,valeur);}
		}
	}



	fclose(m);
	fclose(f);
	fclose(a);
}





// Afficher la liste des alarmes creation du treeview
void afficher_alarme (GtkWidget *liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter *iter;
GtkListStore *store;

char jour[30];
char heure[30];
char num[30];
char val[30];
store=NULL;

FILE *a;

store=gtk_tree_view_get_model(liste);

if (store==NULL)
{
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("jour", renderer, "text",JOUR, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("heure", renderer, "text",HEURE, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("num", renderer, "text",NUM, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("val", renderer, "text",VAL, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


store=gtk_list_store_new (COLUMNS1, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);


a=fopen("alarme.txt","r");

if(a==NULL)
{
return;
}
else
{ a=fopen("alarme.txt","a+");

while(fscanf(a,"%s %s %s %s\n",jour,heure,num,val)!=EOF)
{
gtk_list_store_append (store, &iter);
gtk_list_store_set (store, &iter,JOUR, jour, HEURE, heure, NUM, num,VAL,val,-1);
}
fclose(a);
gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));

}
}
}

//////////////////////////////////////PARTIE KHALIL












////////////////////////////////////////////////////************////////////
/////////////////fonction afficher dans le treeview

void niveau_affiche(GtkWidget *liste){//1

GtkCellRenderer *renderer;

GtkTreeViewColumn *column;

GtkTreeIter iter;

GtkListStore *store;



char niveau[100];///
char nombre[100];///



enum
{Nombre,
Niveau1,COLUMNS1
};







store=NULL;

FILE *f;

store=gtk_tree_view_get_model(liste);
if(store==NULL){//2
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Niveau",renderer,"text",Niveau1,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Nombre",renderer,"text",Nombre,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);





store=gtk_list_store_new(COLUMNS1,G_TYPE_STRING,G_TYPE_STRING);
f=fopen("niveau.txt","r");
if(f==NULL){
return;
}
else
{

f=fopen("niveau.txt","a+");
while(fscanf(f,"%s %s\n",niveau,nombre)!=EOF)
{

gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,Nombre,nombre,Niveau1,niveau,-1);

}

}

fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));

}//2


}//1
























////////////////////////****************///////////////////////
void niveau(int ams,char niveauteeou[],char nvniveau[]){
char nv[100];
int vl; 
FILE *f;
FILE *g;
f=fopen("niveau.txt","r");
g=fopen("niveau1.txt","w");

if(ams==1){

while(fscanf(f,"%s %d\n",nv,&vl)!=EOF){

if(strcmp(nv,niveauteeou)==0){

fprintf(g,"%s %d\n",nv,vl+1);

}

else

fprintf(g,"%s %d\n",nv,vl);

}
}




else if(ams==3){
while(fscanf(f,"%s %d\n",nv,&vl)!=EOF){
if(strcmp(nv,niveauteeou)==0)
fprintf(g,"%s %d\n",nv,vl-1);
else
fprintf(g,"%s %d\n",nv,vl);}}



else{
while(fscanf(f,"%s %d\n",nv,&vl)!=EOF){
if(strcmp(nv,niveauteeou)==0)
fprintf(g,"%s %d\n",nv,vl-1);
else if(strcmp(nv,nvniveau)==0)
fprintf(g,"%s %d\n",nv,vl+1);
else
fprintf(g,"%s %d\n",nv,vl);
}}



fclose(f);

fclose(g);

remove("niveau.txt");

rename("niveau1.txt","niveau.txt");
}


//////verification utilisateur
int verifier_khalil(char user[],char pass[]){

int trouve=-1;
char ch1[20],ch2[20],ch3[20],ch4[20],ch5[10];
FILE *f=NULL;
f=fopen("utilisateur.txt","r");
if(f!=NULL){
while (fscanf(f,"%s %s %s %s %s",ch1,ch2,ch3,ch4,ch5)!=EOF)
{if((strcmp(ch1,user)==0)&&(strcmp(ch2,pass)==0))
trouve=1;
}
fclose(f);}
return (trouve);}






/////////////////////   ajout etudiant  
void ajouteretudiant(etudiant e)
{

  FILE *f=NULL;  

  f=fopen("etudiant.txt","a+");
fprintf(f,"%s %s %s %s %d%d %s %d/%d/%d %s %s %s\n",e.nom,
e.prenom,e.cin,e.niveau,e.chambre.etage,e.chambre.numero,e.chambre.type,e.date.jour,e.date.mois,e.date.annee,e.tel,e.mail,e.sex);
    fclose(f);
}












///////////////rechercher etudiant




int recherche_etudiant(char cin1[])
{
   
char nom[100];
char prenom[100];
char cin[100];
char niveau[100];///
char chambre[100];///
char numero[100];
char date[100];///
char tel[100];///
char mail[100];///
char sex[100];




   FILE *f=NULL;
   f=fopen("etudiant.txt","a+");


while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s\n",nom,
prenom,cin,niveau,numero,chambre,date,tel,mail,sex)!=EOF)
    {
      
        if(strcmp(cin,cin1)==0)
        {
            fclose(f);
            return 1;
        }
    }
    fclose(f);
    return 0;

}



/////////////////fonction afficher dans le treeview

void afficherpersonne_khalil(GtkWidget *liste){//1

enum
{
Nom,
Prenom,
Cin,
Niveau,
Chambre,
Numero,
Date,
Tel,
Mail,
Sex,

COLUMNS
};

GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;


char nom[100];
char prenom[100];
char cin[100];
char niveau[100];///
char chambre[100];///
char numero[100];
char date[100];///
char tel[100];///
char mail[100];///
char sex[100];








store=NULL;

FILE *f;

store=gtk_tree_view_get_model(liste);
if(store==NULL){//2
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Nom",renderer,"text",Nom,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Prenom",renderer,"text",Prenom,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Cin",renderer,"text",Cin,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Niveau",renderer,"text",Niveau,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Chambre",renderer,"text",Chambre,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);



renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Numero",renderer,"text",Numero,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Date_Naissance",renderer,"text",Date,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Tel°",renderer,"text",Tel,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Mail",renderer,"text",Mail,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Sex",renderer,"text",Sex,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);



store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
f=fopen("etudiant.txt","r");
if(f==NULL){
return;
}
else
{

f=fopen("etudiant.txt","a+");
while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s\n",nom,
prenom,cin,niveau,numero,chambre,date,tel,mail,sex)!=EOF)
{

gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,Nom,nom,Prenom,prenom,Cin,cin,Niveau,niveau,Numero,numero,Chambre,chambre,Date,date,Tel,tel,Mail,mail,Sex,sex,-1);

}

}

fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));

}//2


}//1
/////////////////////////////////////////////////////////



//////////////////////////////////////afficher 1seule persoonne
void afficherunepersonne_khalil(GtkWidget *liste,char cin1[]){//1

GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;


enum
{
Nom,
Prenom,
Cin,
Niveau,
Chambre,
Numero,
Date,
Tel,
Mail,
Sex,

COLUMNS
};



char nom[100];
char prenom[100];
char cin[100];
char niveau[100];///
char chambre[100];///
char numero[100];
char date[100];///
char tel[100];///
char mail[100];///
char sex[100];








store=NULL;

FILE *f;

store=gtk_tree_view_get_model(liste);
if(store==NULL){//2
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Nom",renderer,"text",Nom,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Prenom",renderer,"text",Prenom,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Cin",renderer,"text",Cin,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Niveau",renderer,"text",Niveau,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Chambre",renderer,"text",Chambre,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);



renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Numero",renderer,"text",Numero,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Date_Naissance",renderer,"text",Date,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Tel°",renderer,"text",Tel,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Mail",renderer,"text",Mail,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Sex",renderer,"text",Sex,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);



store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
f=fopen("etudiant.txt","r");
if(f==NULL){
return;
}
else
{//else

f=fopen("etudiant.txt","a+");
while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s\n",nom,
prenom,cin,niveau,numero,chambre,date,tel,mail,sex)!=EOF)
{//while

if(strcmp(cin,cin1)==0){//if

gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,Nom,nom,Prenom,prenom,Cin,cin,Niveau,niveau,Numero,numero,Chambre,chambre,Date,date,Tel,tel,Mail,mail,Sex,sex,-1);
}//if
}//while

}//else

fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));

}//2


}//1








































//////////////////////////////////fonction vider le treeview 

void vidertreeview_khalil(GtkWidget *liste){
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;


enum
{
Nom,
Prenom,
Cin,
Niveau,
Chambre,
Numero,
Date,
Tel,
Mail,
Sex,

COLUMNS
};





char nom[100];
char prenom[100];
char cin[100];
char niveau[100];///
char chambre[100];///
char numero[100];
char date[100];///
char tel[100];///
char mail[100];///
char sex[100];








store=NULL;

FILE *f;

store=gtk_tree_view_get_model(liste);
if(store==NULL){//2
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Nom",renderer,"text",Nom,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Prenom",renderer,"text",Prenom,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Cin",renderer,"text",Cin,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Niveau",renderer,"text",Niveau,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Chambre",renderer,"text",Chambre,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);



renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Numero",renderer,"text",Numero,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Date_Naissance",renderer,"text",Date,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Tel°",renderer,"text",Tel,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Mail",renderer,"text",Mail,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Sex",renderer,"text",Sex,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


}
store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);


gtk_list_store_append(store,&iter);

gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));




}//1






























////// supprimer personne
void supprimerpersonne(char cin1[]){

char nom[100];
char prenom[100];
char cin[100];
char niveau[100];///
char chambre[100];///
char numero[100];
char date[100];///
char tel[100];///
char mail[100];///
char sex[100];


FILE *f,*g;
f=fopen("etudiant.txt","r");
g=fopen("etud.txt","w");



while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s\n",nom,
prenom,cin,niveau,numero,chambre,date,tel,mail,sex)!=EOF){




if(strcmp(cin1,cin)!=0){
fprintf(g,"%s %s %s %s %s %s %s %s %s %s\n",nom,
prenom,cin,niveau,numero,chambre,date,tel,mail,sex);
}}
fclose(f);
fclose(g);
remove("etudiant.txt");
rename("etud.txt","etudiant.txt");}






////////////////  modifier personne  //////////////





void modif_khalil(etudiant c,char valeur[])

{ //fct
int etagenumero;
 
   etudiant k;
    FILE *f=NULL;
    FILE *f2=NULL;
    f2=fopen("etudiant.txt","r");
    f=fopen("ajout_etu.txt","w+");


    while(fscanf(f2,"%s %s %s %s %d %s %d/%d/%d %s %s %s\n",k.nom,
k.prenom,k.cin,k.niveau,&etagenumero,k.chambre.type,&k.date.jour,&k.date.mois,&k.date.annee,k.tel,k.mail,k.sex)!=EOF)
    {//while
        if(strcmp(k.cin,c.cin)!=0)
        {
            fprintf(f,"%s %s %s %s %d %s %d/%d/%d %s %s %s\n",k.nom,
k.prenom,k.cin,k.niveau,etagenumero,k.chambre.type,k.date.jour,k.date.mois,k.date.annee,k.tel,k.mail,k.sex);
        }

        else{
    if(strcmp(valeur,"Nom")==0){

fprintf(f,"%s %s %s %s %d %s %d/%d/%d %s %s %s\n",c.nom,
k.prenom,k.cin,k.niveau,etagenumero,k.chambre.type,k.date.jour,k.date.mois,k.date.annee,k.tel,k.mail,k.sex);
        }//

    else if (strcmp(valeur,"Prenom")==0){

fprintf(f,"%s %s %s %s %d %s %d/%d/%d %s %s %s\n",k.nom,
c.prenom,k.cin,k.niveau,etagenumero,k.chambre.type,k.date.jour,k.date.mois,k.date.annee,k.tel,k.mail,k.sex);


}//
 else if (strcmp(valeur,"Niveau")==0){
fprintf(f,"%s %s %s %s %d %s %d/%d/%d %s %s %s\n",k.nom,
k.prenom,k.cin,c.niveau,etagenumero,k.chambre.type,k.date.jour,k.date.mois,k.date.annee,k.tel,k.mail,k.sex);
}
else if (strcmp(valeur,"Mail")==0){
fprintf(f,"%s %s %s %s %d %s %d/%d/%d %s %s %s\n",k.nom,
k.prenom,k.cin,k.niveau,etagenumero,k.chambre.type,k.date.jour,k.date.mois,k.date.annee,k.tel,c.mail,k.sex);
}

else if (strcmp(valeur,"Tel°")==0){
fprintf(f,"%s %s %s %s %d %s %d/%d/%d %s %s %s\n",k.nom,
k.prenom,k.cin,k.niveau,etagenumero,k.chambre.type,k.date.jour,k.date.mois,k.date.annee,c.tel,k.mail,k.sex);
}
else if (strcmp(valeur,"DateNaissance")==0){
fprintf(f,"%s %s %s %s %d %s %d/%d/%d %s %s %s\n",k.nom,
k.prenom,k.cin,k.niveau,etagenumero,k.chambre.type,c.date.jour,c.date.mois,c.date.annee,k.tel,k.mail,k.sex);
}
else if (strcmp(valeur,"Num°Chambre")==0){
fprintf(f,"%s %s %s %s %d%d %s %d/%d/%d %s %s %s\n",k.nom,
k.prenom,k.cin,k.niveau,c.chambre.etage,c.chambre.numero,k.chambre.type,k.date.jour,k.date.mois,k.date.annee,k.tel,k.mail,k.sex);
}



}

    };//while







    fclose(f);
    fclose(f2);
    remove("etudiant.txt");
    rename("ajout_etu.txt","etudiant.txt");
}//fct



///////////////////////////////fct_ahmed///////////////////////////////



char ch[100];
enum
{
  PJOUR,
  PMOIS,
  PANNEE,
  PTYPE,
  PNOM,
  PQUANTITE,
  PPRIX,
  //COLUMNS
};
GtkListStore *adstore;
GtkTreeViewColumn *adcolumn;
GtkCellRenderer *cellad;
FILE *f;
void ajout_produit(produit p)
{
    FILE *f;

    f=fopen("produits.txt","a");
    if (f!=NULL)
{
    fprintf(f,"%d %d %d %s %s %s %s \n",p.d.jour,p.d.mois,p.d.annee,p.type,p.produit.nom,p.produit.quantite,p.produit.prix);
}
    fclose(f);
}
void supprimer_produit(int jour,int mois,int annee,char type[])
    {
        FILE *f=NULL;
        FILE *f1=NULL;
        char ch2[200],ch3[200],ch4[200],ch5[200];
        int a,b,c,x,test=0;
        f=fopen("produits.txt","r");
        f1=fopen("sup.txt","a");
        if(f!=NULL)
        {
            while(fscanf(f,"%d %d %d %s %s %s %s \n",&a,&b,&c,ch2,ch3,ch4,ch5)!=EOF)
            {
if (a!=jour||b!=mois||c!=annee||strcmp(type,ch2)!=0)
{
                    fprintf(f1,"%d %d %d %s %s %s %s \n",a,b,c,ch2,ch3,ch4,ch5);
}
else
 test=1;

            }
        }

        fclose(f);
        fclose(f1);
        remove("produits.txt");
        rename("sup.txt","produits.txt");
if (test==0)
{
printf("le produit n'existe pas\n");
}
    }

void modifier_produit(produit pr)
{
	FILE *f=NULL;
        FILE *f1=NULL;
	produit prd;
        //char ch2[200],ch3[200],ch4[200],ch5[200];
       // int a,b,c,x,test=0;
	int test=0;
        f=fopen("produits.txt","r");
        f1=fopen("sup.txt","a");
        if(f!=NULL)
        {
            //while(fscanf(f,"%d %d %d %s %s %s %s \n",&a,&b,&c,ch2,ch3,ch4,ch5)!=EOF)
            while(fscanf(f,"%d %d %d %s %s %s %s \n ",&prd.d.jour,&prd.d.mois,&prd.d.annee,prd.type,prd.produit.nom,prd.produit.quantite,prd.produit.prix)!=EOF) 
            {

//if (a!=pr.d.jour||b!=pr.d.mois||c!=pr.d.annee||strcmp(pr.type,ch2)!=0)
if (prd.d.jour!=pr.d.jour||prd.d.mois!=pr.d.mois||prd.d.annee!=pr.d.annee||strcmp(pr.type,prd.type)!=0)
{
                   // fprintf(f1,"%d %d %d %s %s %s %s \n",a,b,c,ch2,ch3,ch4,ch5);
                    fprintf(f1,"%d %d %d %s %s %s %s \n",prd.d.jour,prd.d.mois,prd.d.annee,prd.type,prd.produit.nom,prd.produit.quantite,prd.produit.prix);
}
else
{
 test=1;
//fprintf(f1,"%d %d %d %s %s %s %s \n",a,b,c,ch2,pr.produit.nom,pr.produit.quantite,pr.produit.prix);
fprintf(f1,"%d %d %d %s %s %s %s \n",pr.d.jour,pr.d.mois,pr.d.annee,pr.type,pr.produit.nom,pr.produit.quantite,pr.produit.prix);
}

            }
        }

        fclose(f);
        fclose(f1);
        remove("produits.txt");
        rename("sup.txt","produits.txt");
if (test==0)
{
printf("le produit n'existe pas\n");
}
    }
void rechercher_produit1(char nom[])
{
	FILE *f=NULL;
        FILE *f1=NULL;
        char ch2[200],ch3[200],ch4[200],ch5[200];
        int a,b,c,x;
        f=fopen("produits.txt","r");
        f1=fopen("produits1.txt","w");
        if(f!=NULL)
        {
            while(fscanf(f,"%d %d %d %s %s %s %s \n",&a,&b,&c,ch2,ch3,ch4,ch5)!=EOF)  
            {
              if (strcmp(nom,ch3)==0)
                {
                    fprintf(f1,"%d %d %d %s %s %s %s \n",a,b,c,ch2,ch3,ch4,ch5); 
                }
            }
        }

        fclose(f);
        fclose(f1);
}
void rechercher_produit2(int jo,int mo,int an,char type1[])
{
	FILE *f=NULL;
        FILE *f1=NULL;
        char ch2[200],ch3[200],ch4[200],ch5[200];
        int a,b,c,x;
        f=fopen("produits.txt","r");
        f1=fopen("produits2.txt","w");
        if(f!=NULL)
        {
            while(fscanf(f,"%d %d %d %s %s %s %s \n",&a,&b,&c,ch2,ch3,ch4,ch5)!=EOF)
            {
if (jo==a && mo==b && an==c && strcmp(type1,ch2)==0)
{
                    fprintf(f1,"%d %d %d %s %s %s %s \n",a,b,c,ch2,ch3,ch4,ch5);
}
            }
        }

        fclose(f);
        fclose(f1);
}

void afficher_produit(GtkWidget *treeview1,char ch[])
{
GtkListStore *store;
 store=NULL;
 FILE *f;
produit p;
 store=gtk_tree_view_get_model(treeview1);
adstore = gtk_list_store_new(7,
                                     G_TYPE_INT,
                                     G_TYPE_INT,
                                     G_TYPE_INT,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
				     G_TYPE_STRING,
				     G_TYPE_STRING);
f=fopen(ch,"r");
while (fscanf(f,"%d %d %d %s %s %s %s \n",&p.d.jour,&p.d.mois,&p.d.annee,p.type,p.produit.nom,p.produit.quantite,p.produit.prix)!=EOF)
{
GtkTreeIter pIter;
         gtk_list_store_append(adstore, &pIter);
gtk_list_store_set(adstore, &pIter,
                            0,p.d.jour,
                            1,p.d.mois,
			    2,p.d.annee,
                            3,p.type,
                            4,p.produit.nom,
                            5,p.produit.quantite,
                            6,p.produit.prix,-1);}
        fclose(f);
if(store==0)
	{
	cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("JOUR",  cellad,"text", 0,  NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);
	cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("MOIS",   cellad,  "text", 1, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);
	cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("ANNEE",cellad,"text", 2, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);
	cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("TYPE",cellad,"text", 3, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);
	cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("NOM",cellad,"text", 4, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);
	cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("QUANTITE", cellad,"text", 5,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);
	cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("PRIX",cellad,"text", 6, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);
       }
gtk_tree_view_set_model ( GTK_TREE_VIEW (treeview1), GTK_TREE_MODEL(adstore));

}




void rechercher_produit_repture_de_stock(char quantite[])
{
	FILE *f=NULL;
        FILE *f1=NULL;
        char ch2[200],ch3[200],ch4[200],ch5[200];
        int a,b,c,x;
	quantite="0kg";
        f=fopen("produits.txt","r");
        f1=fopen("produits_hors_stock.txt","w");
        if(f!=NULL)
        {
            while(fscanf(f,"%d %d %d %s %s %s %s \n",&a,&b,&c,ch2,ch3,ch4,ch5)!=EOF)
            {
if (strcmp(quantite,ch4)==0)
{
                    fprintf(f1,"%d %d %d %s %s %s %s \n",a,b,c,ch2,ch3,ch4,ch5);
}
            }
        }

        fclose(f);
        fclose(f1);
}	


int verifier_produit(char nom[])
{
   
        char ch2[200],ch3[200],ch4[200],ch5[200];
        int a,b,c,x;




   FILE *f=NULL;
   f=fopen("produits.txt","a+");


while(fscanf(f,"%d %d %d %s %s %s %s \n",&a,&b,&c,ch2,ch3,ch4,ch5)!=EOF)
    {
      
        if(strcmp(ch2,nom)==0)
        {
            fclose(f);
            return 1;
        }
    }
    fclose(f);
    return 0;

}

//////////////////////////////////////////////////////////////////////////
///////////////****capteur***////////////////////////////



////////////////////////////////////////////
void ajouter_capteur(capteur c)
{


  FILE *f;
  f=fopen("capteur.txt","a+");
  if(f!=NULL)
   {
    fprintf(f,"%s %s %s %s %s %s %d %d %d \n",c.marque,c.reference,c.valeur,c.prix,c.type,c.etat,c.datee.jour,c.datee.mois,c.datee.annee);
    fclose(f);
   }

}
////////////////////////////////////////////
void afficher_capteur(GtkWidget *liste)
{

 enum
{
  EMARQUE,
  EREFERENCE,
  EVALEUR,
  EPRIX,
  ETYPE,
  EETAT,
  EDATE,
  COLUMNS
};
 GtkCellRenderer *renderer;
 GtkTreeViewColumn *column;
 GtkTreeIter iter;
 GtkListStore *store;

 char marque[20];
 char reference[20];
 char valeur[20];
 char prix[20];
 char type[20];
 char etat[20];
 char date_ajout[20];
 DATE datee;
 capteur c;
 store=NULL;
  FILE *f;
  store=gtk_tree_view_get_model(liste);

 if(store==NULL)
  {
    renderer = gtk_cell_renderer_text_new();
    column= gtk_tree_view_column_new_with_attributes("marque",renderer,"text",EMARQUE,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

    renderer= gtk_cell_renderer_text_new();
    column= gtk_tree_view_column_new_with_attributes("reference",renderer,"text",EREFERENCE,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

    renderer= gtk_cell_renderer_text_new();
    column= gtk_tree_view_column_new_with_attributes("valeur",renderer,"text",EVALEUR,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

    renderer= gtk_cell_renderer_text_new();
    column= gtk_tree_view_column_new_with_attributes("prix",renderer,"text",EPRIX,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

    renderer= gtk_cell_renderer_text_new();
    column= gtk_tree_view_column_new_with_attributes("type",renderer,"text",ETYPE,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

    renderer= gtk_cell_renderer_text_new();
    column= gtk_tree_view_column_new_with_attributes("etat",renderer,"text",EETAT,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);
    renderer= gtk_cell_renderer_text_new();
    column= gtk_tree_view_column_new_with_attributes("date",renderer,"text",EDATE,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

  }
  store= gtk_list_store_new (COLUMNS, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

 f=fopen("capteur.txt","r");
 if(f==NULL)
  {

    return;
  }
 else
  { f=fopen("capteur.txt","a+");
    
    while(fscanf(f,"%s %s %s %s %s %s %d %d %d \n",marque,reference,valeur,prix,type,etat,&c.datee.jour,&c.datee.mois,&c.datee.annee)!=EOF)
    {
      sprintf(date_ajout, "%d %d %d", c.datee.jour,c.datee.mois,c.datee.annee);
      gtk_list_store_append(store,&iter);
      gtk_list_store_set(store,&iter,EMARQUE,marque,EREFERENCE,reference,EVALEUR,valeur,EPRIX,prix,ETYPE,type,EETAT,etat,EDATE,date_ajout, -1);
    }
    fclose(f);
    gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
    g_object_unref (store);
  }

}
////////////////////////////////////////////
void defectueux_capteur(GtkWidget *liste)
{

 enum
{
  EMARQUE,
  EREFERENCE,
  EVALEUR,
  EPRIX,
  ETYPE,
  EETAT,
  EDATE,
  COLUMNS
};

  GtkCellRenderer *renderer;
 GtkTreeViewColumn *column;
 GtkTreeIter iter;
 GtkListStore *store;

 char marque[20];
 char reference[20];
 char valeur[20];
 char prix[20];
 char type[20];
 char etat[20];
 char date_ajout[20];
 DATE datee;
 capteur c;
 store=NULL;
  FILE *f;
  store=gtk_tree_view_get_model(liste);

 if(store==NULL)
  {
    renderer = gtk_cell_renderer_text_new();
    column= gtk_tree_view_column_new_with_attributes("marque",renderer,"text",EMARQUE,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

    renderer= gtk_cell_renderer_text_new();
    column= gtk_tree_view_column_new_with_attributes("reference",renderer,"text",EREFERENCE,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

    renderer= gtk_cell_renderer_text_new();
    column= gtk_tree_view_column_new_with_attributes("valeur",renderer,"text",EVALEUR,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

    renderer= gtk_cell_renderer_text_new();
    column= gtk_tree_view_column_new_with_attributes("prix",renderer,"text",EPRIX,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

    renderer= gtk_cell_renderer_text_new();
    column= gtk_tree_view_column_new_with_attributes("type",renderer,"text",ETYPE,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

    renderer= gtk_cell_renderer_text_new();
    column= gtk_tree_view_column_new_with_attributes("etat",renderer,"text",EETAT,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);
    renderer= gtk_cell_renderer_text_new();
    column= gtk_tree_view_column_new_with_attributes("date",renderer,"text",EDATE,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

  }
  store= gtk_list_store_new (COLUMNS, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

 f=fopen("capteur.txt","r");
 if(f==NULL)
  {

    return;
  }
 else
  { f=fopen("capteur.txt","a+");
    
    while(fscanf(f,"%s %s %s %s %s %s %d %d %d \n",marque,reference,valeur,prix,type,etat,&c.datee.jour,&c.datee.mois,&c.datee.annee)!=EOF)
    {
        if(strcmp(etat,"défectueux")==0){
      sprintf(date_ajout, "%d %d %d", c.datee.jour,c.datee.mois,c.datee.annee);
      gtk_list_store_append(store,&iter);
      gtk_list_store_set(store,&iter,EMARQUE,marque,EREFERENCE,reference,EVALEUR,valeur,EPRIX,prix,ETYPE,type,EETAT,etat,EDATE,date_ajout, -1);
   }
    }
    fclose(f);
    gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
    g_object_unref (store);
  }



}



////////////////////////////////////////////
void supprimer_capteur(capteur c)
{
 capteur c2;
 FILE *f,*g;
   f=fopen("capteur.txt","r");
   g=fopen("capteur2.txt","w");

   if((f==NULL)||(g==NULL))
      return;
   else
    {
      while(fscanf(f,"%s %s %s %s %s %s %d %d %d \n",c2.marque,c2.reference,c2.valeur,c2.prix,c2.type,c2.etat,&c2.datee.jour,&c2.datee.mois,&c2.datee.annee)!=EOF)
        {
           if(strcmp(c.reference,c2.reference)!=0)
           fprintf(g,"%s %s %s %s %s %s %d %d %d \n",c2.marque,c2.reference,c2.valeur,c2.prix,c2.type,c2.etat,c2.datee.jour,c2.datee.mois,c2.datee.annee);
         }
      fclose(f);
      fclose(g);
 remove("capteur.txt");
 rename("capteur2.txt","capteur.txt");
    }
  
}
//////////////////////////////////////////// 
void vider(GtkWidget *liste)
{
 
 enum
{
  EMARQUE,
  EREFERENCE,
  EVALEUR,
  EPRIX,
  ETYPE,
  EETAT,
  EDATE,
  COLUMNS
};
GtkCellRenderer *renderer;
 GtkTreeViewColumn *column;
 GtkTreeIter iter;
 GtkListStore *store;

 char marque[20];
 char reference[20];
 char valeur[20];
 char prix[20];
 char type[20];
 char etat[20];
 char date_ajout[20];
 DATE datee;
 capteur c;
 store=NULL;
  FILE *f;
  store=gtk_tree_view_get_model(liste);

 if(store==NULL)
  {
    renderer = gtk_cell_renderer_text_new();
    column= gtk_tree_view_column_new_with_attributes("marque",renderer,"text",EMARQUE,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

    renderer= gtk_cell_renderer_text_new();
    column= gtk_tree_view_column_new_with_attributes("reference",renderer,"text",EREFERENCE,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

    renderer= gtk_cell_renderer_text_new();
    column= gtk_tree_view_column_new_with_attributes("valeur",renderer,"text",EVALEUR,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

    renderer= gtk_cell_renderer_text_new();
    column= gtk_tree_view_column_new_with_attributes("prix",renderer,"text",EPRIX,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

    renderer= gtk_cell_renderer_text_new();
    column= gtk_tree_view_column_new_with_attributes("type",renderer,"text",ETYPE,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

    renderer= gtk_cell_renderer_text_new();
    column= gtk_tree_view_column_new_with_attributes("etat",renderer,"text",EETAT,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);
    renderer= gtk_cell_renderer_text_new();
    column= gtk_tree_view_column_new_with_attributes("date",renderer,"text",EDATE,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

  }
  store= gtk_list_store_new (COLUMNS, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
  gtk_list_store_append(store,&iter);
  gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
}
/////////////////////////////////////////////////////////////////////////
void modification_capteur(capteur c)
{
  capteur c3;
 FILE *f,*g;
   f=fopen("capteur.txt","r");
   g=fopen("capteur3.txt","w");

   if((f==NULL)||(g==NULL))
      return;
   else
    {
      while(fscanf(f,"%s %s %s %s %s %s %d %d %d \n",c3.marque,c3.reference,c3.valeur,c3.prix,c3.type,c3.etat,&c3.datee.jour,&c3.datee.mois,&c3.datee.annee)!=EOF)
        {
           if(strcmp(c.reference,c3.reference)!=0)
             {
           fprintf(g,"%s %s %s %s %s %s %d %d %d \n",c3.marque,c3.reference,c3.valeur,c3.prix,c3.type,c3.etat,c3.datee.jour,c3.datee.mois,c3.datee.annee);
             }
	   else
	    {
 fprintf(g,"%s %s %s %s %s %s %d %d %d \n",c.marque,c.reference,c.valeur,c.prix,c.type,c.etat,c.datee.jour,c.datee.mois,c.datee.annee);
            }
         }
      fclose(f);
      fclose(g);
 remove("capteur.txt");
 rename("capteur3.txt","capteur.txt");
    }
}
//////////////////////////////////////////////////////
void recherche_capteur(GtkWidget *liste,char comparef[20])
{

enum
{
  EMARQUE,
  EREFERENCE,
  EVALEUR,
  EPRIX,
  ETYPE,
  EETAT,
  EDATE,
  COLUMNS
};
  GtkCellRenderer *renderer;
 GtkTreeViewColumn *column;
 GtkTreeIter iter;
 GtkListStore *store;

 char marque[20];
 char reference[20];
 char valeur[20];
 char prix[20];
 char type[20];
 char etat[20];
 char date_ajout[20];
 DATE datee;
 capteur c;
 store=NULL;
  FILE *f;
  store=gtk_tree_view_get_model(liste);

 if(store==NULL)
  {
    renderer = gtk_cell_renderer_text_new();
    column= gtk_tree_view_column_new_with_attributes("marque",renderer,"text",EMARQUE,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

    renderer= gtk_cell_renderer_text_new();
    column= gtk_tree_view_column_new_with_attributes("reference",renderer,"text",EREFERENCE,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

    renderer= gtk_cell_renderer_text_new();
    column= gtk_tree_view_column_new_with_attributes("valeur",renderer,"text",EVALEUR,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

    renderer= gtk_cell_renderer_text_new();
    column= gtk_tree_view_column_new_with_attributes("prix",renderer,"text",EPRIX,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

    renderer= gtk_cell_renderer_text_new();
    column= gtk_tree_view_column_new_with_attributes("type",renderer,"text",ETYPE,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

    renderer= gtk_cell_renderer_text_new();
    column= gtk_tree_view_column_new_with_attributes("etat",renderer,"text",EETAT,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);
    renderer= gtk_cell_renderer_text_new();
    column= gtk_tree_view_column_new_with_attributes("date",renderer,"text",EDATE,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

  }
  store= gtk_list_store_new (COLUMNS, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

 f=fopen("capteur.txt","r");
 if(f==NULL)
  {

    return;
  }
 else
  { f=fopen("capteur.txt","a+");
    
    while(fscanf(f,"%s %s %s %s %s %s %d %d %d \n",marque,reference,valeur,prix,type,etat,&c.datee.jour,&c.datee.mois,&c.datee.annee)!=EOF)
    {
 	if(strcmp(reference,comparef)==0){
      sprintf(date_ajout, "%d %d %d", c.datee.jour,c.datee.mois,c.datee.annee);
      gtk_list_store_append(store,&iter);
      gtk_list_store_set(store,&iter,EMARQUE,marque,EREFERENCE,reference,EVALEUR,valeur,EPRIX,prix,ETYPE,type,EETAT,etat,EDATE,date_ajout, -1);
	}
    }
    fclose(f);
    gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
    g_object_unref (store);
  }

}
//---------------------------------PARTIE EMNA--------------------------------




void ajouter_Nouv_reclamation(reclamation r){
FILE*f;

f=fopen("reclamations.txt","a+");//(+) creation du fichier sil nexsite pas

fprintf(f,"%s %s %s %s %s %s %s %d\n",r.id,r.servicer,r.objetr,r.detailsr,r.dater,r.alerter,r.raisonr,r.noter);
fclose(f);

}






void alerterf(char alertee[], char msg[]) {/*

	if(strcpy(alertee,"1")==0) 
		strcpy(msg,"fort");

	else if(strcpy(alertee,"2")==0) 
		strcpy(msg,"faible");*/

}



void choisiir(int choix[],char textee[] ) {/*

	if(choix[0]==1) {
		strcpy(textee,"S");
	}
	if(choix[1]==1){
		strcpy(textee,"C");
	}
	if(choix[2]==1){
		strcpy(textee,"Q");
	}*/
}



int exist_reclamation(char id[]){
FILE*f=NULL;
int b=0;
 reclamation r;
f=fopen("reclamations.txt","r");
while(fscanf(f,"%s %s %s %s %s %s %s %d\n",r.id,r.servicer,r.objetr,r.detailsr,r.dater,r.alerter,r.raisonr,&r.noter)!=EOF){
if(strcmp(r.id,id)==0){b=1;}
}
fclose(f);
return b;
}







	


void afficher_reclamation(GtkWidget *liste)
{

enum
		{

			ID,
			SERVICE,
			OBJET,
			DETAILS,
			DATE,
			RAISON,
			ALERTE,
			NOTE,
			
			COLUMNS,



		};
FILE *f;
//reclamation r;
GtkListStore *store;
//creation du modele de type liste
GtkTreeViewColumn *column;//visualisation des colonnes
GtkCellRenderer *renderer;//afficheur de cellule(text,image..)
GtkTreeIter iter;
char id[300];
char service[300];
char objet[300];
char details[300];
char date[300];
char alerte[300];
char raison[300];
int note;

store=NULL;


store=gtk_tree_view_get_model(liste);   
	
if(store==NULL) {
	renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("ID",
                                                            renderer,
                                                            "text",ID,
                                                            NULL);
 	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


	renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Service",
                                                            renderer,
                                                            "text",SERVICE,
                                                            NULL);
 	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Objet de la reclamation",
                                                            renderer,
                                                            "text",OBJET,
                                                            NULL);
 	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	
	renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("+ de détails ",
                                                            renderer,
                                                            "text",DETAILS,
                                                            NULL);
 	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


	renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Date ",
                                                            renderer,
                                                            "text",DATE,
                                                            NULL);
 	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


	renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Niveau Alerte ",
                                                            renderer,
                                                            "text",ALERTE,
                                                            NULL);
 	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Raison de reclamer ",
                                                            renderer,
                                                            "text",RAISON,
                                                            NULL);
 	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);




	renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Note/10 ",
                                                            renderer,
                                                            "text",NOTE,
                                                            NULL);
 	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	}
		

store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

char noteeee[50];
f=fopen("reclamations.txt","r");
if (f!=NULL) 
{
  



	while(fscanf(f,"%s %s %s %s %s %s %s %d\n",id,service,objet,details,date,alerte,raison,&note)!=EOF) {
	sprintf(noteeee,"%d",note);
	gtk_list_store_append(store,&iter);
	gtk_list_store_set(store,&iter,ID,id,SERVICE,service,OBJET,objet,DETAILS,details,DATE,date,ALERTE,alerte,RAISON,raison,NOTE,noteeee,-1);
	}
}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store);


      
}






void modifier_reclamation(char id[],char servicer[],char objetr[],char detailsr[],char dater[],char alertem[]){


FILE*f=NULL;
FILE*f1=NULL;
reclamation r ;
f=fopen("reclamations.txt","r");

f1=fopen("firstone.txt","a");
while(fscanf(f,"%s %s %s %s %s %s %s %d \n",r.id,r.servicer,r.objetr,r.detailsr,r.dater,r.alerter,r.raisonr,&r.noter)!=EOF)
{
	if(strcmp(id,r.id)!=0){fprintf(f1,"%s %s %s %s %s %s %s %d \n",r.id,r.servicer,r.objetr,r.detailsr,r.dater,r.alerter,r.raisonr,r.noter);
	}
	else{
	fprintf(f1,"%s %s %s %s %s %s %s %d \n",id,servicer,objetr,detailsr,dater,alertem,r.raisonr,r.noter);
	}
}
fclose(f);
fclose(f1);
remove("reclamations.txt");
rename("firstone.txt","reclamations.txt");


}

void supprimer_reclamation(char id[]){
FILE*f=NULL;
FILE*f1=NULL;
reclamation r ;
f=fopen("reclamations.txt","r");

f1=fopen("firstone.txt","a");
while(fscanf(f,"%s %s %s %s %s %s %s %d \n",r.id,r.servicer,r.objetr,r.detailsr,r.dater,r.alerter,r.raisonr,&r.noter)!=EOF){
if(strcmp(id,r.id)!=0){fprintf(f1,"%s %s %s %s %s %s %s %d \n",r.id,r.servicer,r.objetr,r.detailsr,r.dater,r.alerter,r.raisonr,r.noter);}
}
fclose(f);
fclose(f1);
remove("reclamations.txt");
rename("firstone.txt","reclamations.txt");



}







reclamation trouver_reclamation (char*id){/*

FILE*f=NULL;
reclamation r ;
reclamation r1 ;
int b=0;
f=fopen("reclamations.txt","r");
while(fscanf(f,"%s %s %s %s %s %s %s %d \n",r.id,r.servicer,r.objetr,r.detailsr,r.dater,r.alerter,r.raisonr,&r.noter)!=EOF){
if (strcmp(r.id,id)==0)
{
r1=r;
b=1;
}

}
fclose(f);
if(b==0){
strcpy(r1.id,"notFound");
}

return  r1;


*/



}

void viderrecc(GtkWidget* liste)
{

enum
		{

			ID,
			SERVICE,
			OBJET,
			DETAILS,
			DATE,
			RAISON,
			ALERTE,
			NOTE,
			
			COLUMNS,



		};
FILE *f;
//reclamation r;
GtkListStore *store;
//creation du modele de type liste
GtkTreeViewColumn *column;//visualisation des colonnes
GtkCellRenderer *renderer;//afficheur de cellule(text,image..)
GtkTreeIter iter;
char id[300];
char service[300];
char objet[300];
char details[300];
char date[300];
char alerte[300];
char raison[300];
int note;

store=NULL;


store=gtk_tree_view_get_model(liste);   
	
if(store==NULL) {
	renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("ID",
                                                            renderer,
                                                            "text",ID,
                                                            NULL);
 	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


	renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Service",
                                                            renderer,
                                                            "text",SERVICE,
                                                            NULL);
 	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Objet de la reclamation",
                                                            renderer,
                                                            "text",OBJET,
                                                            NULL);
 	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	
	renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("+ de détails ",
                                                            renderer,
                                                            "text",DETAILS,
                                                            NULL);
 	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


	renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Date ",
                                                            renderer,
                                                            "text",DATE,
                                                            NULL);
 	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


	renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Niveau Alerte ",
                                                            renderer,
                                                            "text",ALERTE,
                                                            NULL);
 	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Raison de reclamer ",
                                                            renderer,
                                                            "text",RAISON,
                                                            NULL);
 	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);




	renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Note/10 ",
                                                            renderer,
                                                            "text",NOTE,
                                                            NULL);
 	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	}
		

store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store);
	
        
}


void Chercher_reclamation(GtkWidget* liste,char ide[])
{

          enum
		{

			ID,
			SERVICE,
			OBJET,
			DETAILS,
			DATE,
			RAISON,
			ALERTE,
			NOTE,
			
			COLUMNS,



		};                 
FILE *f;
//reclamation r;
GtkListStore *store;
//creation du modele de type liste
GtkTreeViewColumn *column;//visualisation des colonnes
GtkCellRenderer *renderer;//afficheur de cellule(text,image..)
GtkTreeIter iter;
char id[300];
char service[300];
char objet[300];
char details[300];
char date[300];
char alerte[300];
char raison[300];
int note;

store=NULL;


store=gtk_tree_view_get_model(liste);   
	
if(store==NULL) {
	renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("ID",
                                                            renderer,
                                                            "text",ID,
                                                            NULL);
 	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


	renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Service",
                                                            renderer,
                                                            "text",SERVICE,
                                                            NULL);
 	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Objet de la reclamation",
                                                            renderer,
                                                            "text",OBJET,
                                                            NULL);
 	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	
	renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("+ de détails ",
                                                            renderer,
                                                            "text",DETAILS,
                                                            NULL);
 	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


	renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Date ",
                                                            renderer,
                                                            "text",DATE,
                                                            NULL);
 	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


	renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Niveau Alerte ",
                                                            renderer,
                                                            "text",ALERTE,
                                                            NULL);
 	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Raison de reclamer ",
                                                            renderer,
                                                            "text",RAISON,
                                                            NULL);
 	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);




	renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Note/10 ",
                                                            renderer,
                                                            "text",NOTE,
                                                            NULL);
 	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	}
		

store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

char noteeee[50];
f=fopen("reclamations.txt","r");
if (f!=NULL) 
{
  



	while(fscanf(f,"%s %s %s %s %s %s %s %d\n",id,service,objet,details,date,alerte,raison,&note)!=EOF) {
	if(strcmp(id,ide)==0)
	{
	sprintf(noteeee,"%d",note);
	gtk_list_store_append(store,&iter);
	gtk_list_store_set(store,&iter,ID,id,SERVICE,service,OBJET,objet,DETAILS,details,DATE,date,ALERTE,alerte,RAISON,raison,NOTE,noteeee,-1);
	}
	}
}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store);
	
        
}



int consulter(reclamation *r,char ide[])
{
FILE *f;
char id[300];
char service[300];
char objet[300];
char details[300];
char date[300];
char alerte[300];
char raison[300];
int note,b=0;

f=fopen("reclamations.txt","r");
if (f!=NULL) 
{
  

	while(fscanf(f,"%s %s %s %s %s %s %s %d\n",id,service,objet,details,date,alerte,raison,&note)!=EOF)
	{
		if(strcmp(id,ide)==0)
		{
   			strcpy((*r).servicer,service);
   			strcpy((*r).objetr,objet);
   			strcpy((*r).detailsr,details);
   			strcpy((*r).dater,date);
   			strcpy((*r).alerter,alerte);
   			strcpy((*r).raisonr,raison);
   			(*r).noter=note;
			b=1;
		}

	}
}
fclose(f);
return b;
}



int chercher_service_reclam(char servicee[]){

char id[300];
char service[300];
char objet[300];
char details[300];
char date[300];
char alerte[300];
char raison[300];
int note;


FILE *f=NULL;
f=fopen("reclamations.txt","r");
char S1[200];
char S2[200];
char annee[100];
int mois;
int jour;
char a[200];
char b[200];
int i=0,j=0,x,y;

strcpy(S1,"Hebergement");
strcpy(S2,"Restauration");
while (fscanf(f,"%s %s %s %s %d/%d/%s %s %s %d\n",id,service,objet,details,&jour,&mois,annee,alerte,raison,&note)!=EOF) {
		if((strcmp(service,S1)==0)&&(strcmp(annee,servicee)==0)){
		i=i+1;
	  	
		}

		else if((strcmp(service,S2)==0)&&(strcmp(annee,servicee)==0)) {

		j=j+1;
		
		
	}
	int N;
	//N=max(i,j);
	if (i<j){
	
	return 1;
	}
	else if (i>j)
	{


	return 0;
	}


}
}



// partie inscri at authentif
int verifrecc (char log[], char Pw[])
{
int trouve=-1;
FILE *f=NULL;
char ch1[20];
char ch2[20];
f=fopen("utilisateur1.txt","r");
if (f!=NULL);
{
while (fscanf(f, "%s %s", ch1,ch2)!=EOF)
{
if((strcmp(ch1,log)==0)&&(strcmp(ch2,Pw)==0))
trouve=1;

}
fclose(f);
}
return (trouve); 
}







