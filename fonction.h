#include <gtk/gtk.h>


typedef struct 
{
int jour;
char mois[30];
int annee;
}date;



typedef struct 
{
char cin[20];
char nom[20];
char prenom[30];
char role[30];
char sexe[30];
char username[30];
char password[30];
date d;
}Personne;



////////////////////////////tache dashboard
typedef struct {
		char jour[20];
		char heure[20];
		char num[20];
		char val[20];}
	capteurs;
	void alarme();


////////////////////////////fonctions appel

void ajouter_personne(Personne p);
void affichage_recherche(GtkWidget *liste ,char nom1[],char prenom1[], char cin1[],char sexe1[],char role1[]);
void afficher_personne(GtkWidget *liste);
void supprimer_personne (Personne p);












/////////////////////////////////////////////////////////////









typedef struct{
int jour;
int mois;
int annee}daten;

typedef struct{
int etage;
int numero;
char type[100];
}chambree;

typedef struct{
char nom[100];
char prenom[100];
char cin[100] ;
char tel[100];
chambree chambre;
char sex[100];
char niveau[100];
char mail[100];

daten date}etudiant;



void niveau(int ams,char niveauteeou[],char nvniveau[]);

int verifier_khalil(char user[],char pass[]);


void ajouteretudiant(etudiant e);


int recherche_etudiant(char cin[]);



void supprimerpersonne(char cin1[]);


void modif_khalil(etudiant c,char valeur[]);

//lem tzid parametreout


//////fonction vider le treeview



///////////////fct_ahmed
typedef struct
{
	int jour;
	int mois;
	int annee;
}date_ahmed;
typedef struct
{
	char nom[50];
	char quantite[50];
	char prix[50];
}cordonnees;
typedef struct
{
	date_ahmed  d;
	char type[50];
	cordonnees produit;

}produit;
void afficher_produit(GtkWidget *treeview1, char ch[]);
void ajout_produit(produit p);
void supprimer_produit(int jour,int mois,int annee,char type[]);
void rechercher_produit1(char nom[]);
void rechercher_produit2(int jo,int mo,int an,char type1[]);
void modifier_produit(produit pr);
void rechercher_produit_repture_de_stock(char quantite[]);
int verifier_produit(char nom[]);
/////////////////////////////////////////////////////////////////////////////

typedef struct DATE{
int jour;
int mois;
int annee;
} DATE;
typedef struct capteur{
char marque[20];
char reference[20];
char valeur[20];
char prix[20];
char type[20];
char etat[20];
DATE datee;
} capteur;

void ajouter_capteur(capteur c);
void afficher_capteur(GtkWidget *liste);
void supprimer_capteur(capteur c); 
void vider(GtkWidget *liste);
void modification_capteur(capteur c);
void recherche_capteur(GtkWidget *liste,char comparef[20]);
void defectueux_capteur(GtkWidget *liste);

//---------------------------PARTIE EMNA----------------------


typedef struct reclamation {
char id[100];
char servicer[100];
char objetr[100];
char detailsr[100];
char dater[100];
char alerter[100];
char raisonr[100];
int noter;
}reclamation;


void ajouter_Nouv_reclamation(reclamation r);



void afficher_reclamation(GtkWidget* liste);



void alerterf(char alertee[],char msg[]);
void choisiir(int choix[],char textee[]);

int exist_reclamation(char id[]);


void modifier_reclamation(char id[],char servicer[],char objetr[],char detailsr[],char dater[],char alertem[]);
void supprimer_reclamation(char id[]);
void Chercher_reclamation(GtkWidget* liste,char ide[]);

reclamation trouver_reclamation(char*id);
void viderrecc(GtkWidget* liste);
int consulter(reclamation *r,char ide[]);

int chercher_service_reclam(char servicee[]);
int max (int i, int j);

int verifrecc (char log[], char Pw[]);










