#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include <string.h>
#include <stdio.h>
#include "fonction.h"
#include "callbacks.h"
#include "interface.h"
#include "support.h"



////////////////////////


    ///////////////////////////////////PARTIE SAFA///////////////////////////
char kk[200];
int trouve;
char cin[200];
int x;
 Personne ug ;

//treeview
void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{/*
GtkTreeIter iter;

gchar* nom;
gchar* prenom;
gchar* cin;
gchar* sexe;
gchar* role;
Personne p;
char temp[20];
char temp2[20];



GtkTreeModel *model = gtk_tree_view_get_model(treeview);

if (gtk_tree_model_get_iter(model, &iter, path))
{
gtk_tree_model_get (GTK_LIST_STORE(model), &iter, 0, &cin, 1, &nom,2,&prenom,3,&role,4,&classe, -1);
strcpy(p.cin,cin);
strcpy(p.nom,nom);
strcpy(p.prenom,prenom);
strcpy(p.role,role);
strcpy(p.sexe,sexe);
supprimmer_personne(p);
ug = p;
afficher_personne(treeview);

}*/
}


//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::BOUTONS
void
on_clog_clicked                        (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *choix_fenetre, *log_in;

choix_fenetre=lookup_widget(button,"choix_fenetre");

gtk_widget_destroy(choix_fenetre);
log_in=create_log_in();
gtk_widget_show(log_in);
}


void
on_csign_clicked                       (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *choix_fenetre, *sign_in;

choix_fenetre=lookup_widget(button,"choix_fenetre");

gtk_widget_destroy(choix_fenetre);
sign_in=create__sign_in();
gtk_widget_show(sign_in);
}




//////////////////////////////////////////////////////////////////tache dashboard




void
on_calendars_day_selected              (GtkCalendar     *calendar,
                                        gpointer         user_data)
{
GtkWidget *calendars;
int jj;
int mm;
int aa;
}

/*
void
on_treeview_alarmes_row_activated      (GtkTreeView     *treeview_alarmes,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

GtkTreeIter *iter;
GtkTreeIter *treeview_alarmes;

gchar* jour;
gchar* heure;
gchar* num;
gchar* val;
capteurs c;
char ug[20];
char temp[20];
char temp2[20];


//copie des valeurs du fichier et affichage dans treeview 
GtkTreeModel *model = gtk_tree_view_get_model(treeview_alarmes);

if (gtk_tree_model_get_iter(model, &iter, path))
{
gtk_tree_model_get (GTK_LIST_STORE(model), &iter, 0, &jour, 1, &heure,2,&num,3,&val,-1);
strcpy(c.jour,jour);
strcpy(c.heure,heure);
strcpy(c.num,num);
strcpy(c.val,val);




afficher_alarme(treeview_alarmes);

//ug=c
}
}     
*/

void
on_treeview_alarmes_row_activated      (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
}



void
on_retour_dash_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *admin, *liste_des_alarmes;

liste_des_alarmes=lookup_widget(button,"liste_des_alarmes");

gtk_widget_destroy(liste_des_alarmes);
admin=create_admin();
gtk_widget_show(admin);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////renames/////////////////////////////////////
void
on_SAbutton_modifier1_clicked          (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *cin , *username, *password , *nom , *prenom;
GtkWidget *SAhomme2 , *SAfemme2;
GtkWidget *fenetre_ajout,*fenetre_afficher, *aPf0, *aPf1, *aPf2, *aPf3, *aPf4;
GtkWidget *modif;

Personne p;

cin=lookup_widget(objet_graphique,"SAentry_cin2");
username=lookup_widget(objet_graphique,"SAentry_username2");
password=lookup_widget(objet_graphique,"SAentry_password2");
nom=lookup_widget(objet_graphique,"SAentry_nom2");
prenom=lookup_widget(objet_graphique,"SAentry_prenom2");




strcpy(p.cin,gtk_entry_get_text(GTK_ENTRY(cin)));
strcpy(p.username,gtk_entry_get_text(GTK_ENTRY(username)));
strcpy(p.password,gtk_entry_get_text(GTK_ENTRY(password)));
strcpy(p.nom,gtk_entry_get_text(GTK_ENTRY(nom)));
strcpy(p.prenom,gtk_entry_get_text(GTK_ENTRY(prenom)));


aPf0 = lookup_widget(objet_graphique,"SAcheckbutton_admin2");
aPf1 = lookup_widget(objet_graphique,"SAcheckbutton_technicien2");
aPf2 = lookup_widget(objet_graphique,"SAcheckbutton_foyer2");
aPf3 = lookup_widget(objet_graphique,"SAcheckbutton_resto2");
aPf4 = lookup_widget(objet_graphique,"SAcheckbutton_etudiant2");
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(aPf0))) {strcpy(p.role,"admin");}
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(aPf1))) {strcpy(p.role,"technicien");}
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(aPf2))) {strcpy(p.role,"ag.foyer");}
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(aPf3))) {strcpy(p.role,"ag.resto");}
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(aPf4))) {strcpy(p.role,"etudiant");}
strcpy(p.sexe,kk);


//message modification

modif = lookup_widget (objet_graphique, "modif");
trouve=verif(cin);
if (trouve==0)
{(gtk_label_set_text(GTK_LABEL(modif),"utilisateur modifié avec succes"));}

fenetre_afficher=create_fenetre_afficher();

gtk_widget_show(fenetre_afficher);

chercher_personne(); 

modifier(p);
}


void
on_SAhomme2_toggled                    (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{strcpy(kk,"homme");}
}


void
on_SAfemme2_toggled                    (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{strcpy(kk,"femme");}
}


void
on_SAretour_modifier_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *admin, *fenetre_modifier;

fenetre_modifier=lookup_widget(button,"fenetre_modifier");

gtk_widget_destroy(fenetre_modifier);
admin=create_admin();
gtk_widget_show(admin);
}


void
on_SArechercher_clicked                (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *CIN,*NOM,*PRENOM,*SEXE,*ROLE;
GtkWidget *SAentry_recherche ,*fenetre , *fenetre_afficher1;
GtkWidget *SAtreeview1;
char nom[100];
char prenom[100];
char cin[100];
char sexe[100];
char role[100];
CIN=lookup_widget (objet,"SAentry_recherche");
fenetre_afficher1=create_fenetre_afficher();

strcpy(nom, gtk_entry_get_text(GTK_ENTRY(NOM)));
strcpy(prenom, gtk_entry_get_text(GTK_ENTRY(PRENOM)));
strcpy(cin, gtk_entry_get_text(GTK_ENTRY(CIN)));
strcpy(sexe, gtk_entry_get_text(GTK_ENTRY(SEXE)));
strcpy(role, gtk_entry_get_text(GTK_ENTRY(ROLE)));

fenetre=lookup_widget(objet,"fenetre_afficher");
SAtreeview1=lookup_widget(fenetre_afficher1,"SAtreeview1");
if (chercher_personne(cin)==1)
{
gtk_widget_show(fenetre_afficher1);
gtk_widget_hide(fenetre);
affichage_recherche(SAtreeview1,cin,nom,prenom,sexe,role);
chercher_personne(cin);

}
}


void
on_SAretour_afficher_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *admin, *fenetre_afficher;

fenetre_afficher=lookup_widget(button,"fenetre_afficher");

gtk_widget_destroy(fenetre_afficher);
admin=create_admin();
gtk_widget_show(admin);
}


void
on_SArefresh_list_clicked              (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_afficher , *W1;
GtkWidget *SAtreeview1;
W1=lookup_widget(objet,"fenetre_afficher");
fenetre_afficher=create_fenetre_afficher();
gtk_widget_show(fenetre_afficher);
gtk_widget_hide (W1);
SAtreeview1=lookup_widget(fenetre_afficher,"SAtreeview1");
//vider(treeview1);
afficher_personne(SAtreeview1);
}


void
on_SAbutton_ajouter_clicked            (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_ajout;
GtkWidget *admin;
admin=lookup_widget(objet,"admin");


gtk_widget_destroy(admin);

fenetre_ajout=lookup_widget(objet,"fenetre_ajout");
fenetre_ajout=create_fenetre_ajout();
gtk_widget_show(fenetre_ajout);
}


void
on_SAbutton_afficher_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *admin;
GtkWidget *fenetre_afficher;
GtkWidget *SAtreeview1;

admin=lookup_widget(button,"admin");

gtk_widget_destroy(admin);
fenetre_afficher=lookup_widget(button,"fenetre_afficher");
fenetre_afficher=create_fenetre_afficher();

gtk_widget_show(fenetre_afficher);
SAtreeview1=lookup_widget(fenetre_afficher,"SAtreeview1");
afficher_personne(SAtreeview1);
}


void
on_SAbutton_modifier_clicked           (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *admin;
GtkWidget *fenetre_modifier;

admin=lookup_widget(objet,"admin");

gtk_widget_destroy(admin);
fenetre_modifier=lookup_widget(objet,"fenetre_modifier");
fenetre_modifier=create_fenetre_modifier();

gtk_widget_show(fenetre_modifier);
}


void
on_SAbutton_supprimer_clicked          (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_afficher;
GtkWidget *fenetre_supprimer;
GtkWidget *admin;
admin=lookup_widget(objet,"admin");


gtk_widget_destroy(admin);

admin=lookup_widget(objet,"fenetre_supprimer");
admin=create_fenetre_supprimer();
gtk_widget_show(admin);

fenetre_afficher=create_fenetre_afficher();
gtk_widget_show(fenetre_afficher);
}


void
on_SAalarmes_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *admin, *liste_des_alarmes,*treeview_alarmes;



gtk_widget_destroy(admin);
liste_des_alarmes=create_liste_des_alarmes();
gtk_widget_show(liste_des_alarmes);
treeview_alarmes=lookup_widget(liste_des_alarmes,"treeview_alarmes");



alarme();




afficher_alarme(treeview_alarmes);
}


void
on_SAhomme1_toggled                    (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{strcpy(kk,"homme");}
}


void
on_SAretour_ajout_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *fenetre_ajout, *admin;

fenetre_ajout=lookup_widget(button,"fenetre_ajout");

gtk_widget_destroy(fenetre_ajout);
admin=create_admin();
gtk_widget_show(admin);
}


void
on_SAbutton_ajouter1_clicked           (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
Personne p;
date d;

GtkWidget *input1, *input2,*input3,*input4,*input5,*input6,*output,*j,*a;
GtkWidget *fenetre_ajout, *aPf0, *aPf1, *aPf2, *aPf3, *aPf4;
GtkWidget *ajout;

char text1[200];
char text2[200];

FILE *f=NULL;
f=fopen("users.txt","a+");


fenetre_ajout=lookup_widget(objet_graphique,"fenetre_ajout");


input1=lookup_widget(objet_graphique,"SAentry_nom1");
input2=lookup_widget(objet_graphique,"SAentry_prenom1");
input3=lookup_widget(objet_graphique,"SAentry_cin1");
input4=lookup_widget(objet_graphique,"SAentry_username1");
input5=lookup_widget(objet_graphique,"SAentry_password1");
input6= lookup_widget(objet_graphique, "SAcomboboxentry_mois1");



strcpy(p.nom,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(p.prenom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(p.cin,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(p.username,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(p.password,gtk_entry_get_text(GTK_ENTRY(input5)));

strcpy(d.mois,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input6)));
aPf0 = lookup_widget(objet_graphique,"SAcheckbutton_admin1");
aPf1 = lookup_widget(objet_graphique,"SAcheckbutton_technicien1");
aPf2 = lookup_widget(objet_graphique,"SAcheckbutton_foyer1");
aPf3 = lookup_widget(objet_graphique,"SAcheckbutton_resto1");
aPf4 = lookup_widget(objet_graphique,"SAcheckbutton_etudiant1");
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(aPf0))) {strcpy(p.role,"admin");}
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(aPf1))) {strcpy(p.role,"technicien");}
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(aPf2))) {strcpy(p.role,"ag.foyer");}
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(aPf3))) {strcpy(p.role,"ag.resto");}
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(aPf4))) {strcpy(p.role,"etudiant");}
strcpy(p.sexe,kk);

j=lookup_widget(objet_graphique,"SAspinbutton_jour1");
a=lookup_widget(objet_graphique,"SAspinbutton_annee1");
d.jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (j));
d.annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (a));

fprintf(f,"%s %s %s %s %s %s %s\n",p.username,p.password,p.nom,p.prenom,p.cin,p.sexe,p.role);
fclose(f);


//message inscription
ajout = lookup_widget (objet_graphique, "ajout");
trouve=verif(cin);
if (trouve==0)
{(gtk_label_set_text(GTK_LABEL(ajout),"utilisateur ajouté avec succes"));}

chercher_personne(); 
}


void
on_SAfemme1_toggled                    (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{strcpy(kk,"femme");}
}


void
on_SAhomme_toggled                     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{strcpy(kk,"homme");}
}


void
on_SAfemme_toggled                     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{strcpy(kk,"femme");}
}


void
on_SAbutton_register_clicked           (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *windowAuth , *inscri;

Personne p;
date d;

GtkWidget *input1, *input2,*input3,*input4,*input5,*input6,*output,*j,*a;
GtkWidget *fenetre_ajout, *aPf0, *aPf1, *aPf2, *aPf3, *aPf4;

char text1[200];
char text2[200];

FILE *f=NULL;
f=fopen("users.txt","a+");

input1=lookup_widget(objet_graphique,"SAentry_nom");
input2=lookup_widget(objet_graphique,"SAentry_prenom");
input3=lookup_widget(objet_graphique,"SAentry_cin");
input4=lookup_widget(objet_graphique,"SAentry_username");
input5=lookup_widget(objet_graphique,"SAentry_password");
input6= lookup_widget(objet_graphique, "SAcomboboxentry_mois");



strcpy(p.nom,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(p.prenom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(p.cin,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(p.username,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(p.password,gtk_entry_get_text(GTK_ENTRY(input5)));

strcpy(d.mois,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input6)));
aPf0 = lookup_widget(objet_graphique,"SAcheckbutton_admin");
aPf1 = lookup_widget(objet_graphique,"SAcheckbutton_technicien");
aPf2 = lookup_widget(objet_graphique,"SAcheckbutton_foyer");
aPf3 = lookup_widget(objet_graphique,"SAcheckbutton_resto");
aPf4 = lookup_widget(objet_graphique,"SAcheckbutton_etudiant");
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(aPf0))) {strcpy(p.role,"admin");}
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(aPf1))) {strcpy(p.role,"technicien");}
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(aPf2))) {strcpy(p.role,"ag.foyer");}
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(aPf3))) {strcpy(p.role,"ag.resto");}
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(aPf4))) {strcpy(p.role,"etudiant");}
strcpy(p.sexe,kk);

j=lookup_widget(objet_graphique,"SAspinbutton_jour");
a=lookup_widget(objet_graphique,"SAspinbutton_annee");

d.jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (j));
d.annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (a));

fprintf(f,"%s %s %s %s %s %s %s\n",p.username,p.password,p.nom,p.prenom,p.cin,p.sexe,p.role);
fclose(f);

windowAuth=create_log_in();
gtk_widget_show (windowAuth);



//message inscription
inscri=lookup_widget(objet_graphique,"inscri");
trouve=verif(cin);
if (trouve==0)
{(gtk_label_set_text(GTK_LABEL(inscri),"utilisateur ajouté avec succes"));}

chercher_personne(); 
}


void
on_SAbutton_login_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *username, *password, *admin;
GtkWidget *erreur1;
char username2[200];
char password2[200];
int trouve;
username = lookup_widget (button, "SAentry_username2");
password = lookup_widget (button, "SAentry_password2");
erreur1 = lookup_widget (button, "erreur1");
strcpy(username2, gtk_entry_get_text(GTK_ENTRY(username)));
strcpy(password2, gtk_entry_get_text(GTK_ENTRY(password)));

trouve=verif(username2,password2);
if (trouve==1)
{gtk_label_set_text(GTK_LABEL(erreur1),"*******Bienvenue*******");
admin=create_admin();
gtk_widget_show (admin);}
else (gtk_label_set_text(GTK_LABEL(erreur1),"cet utilisateur n'existe pas"));

chercher_personne(); 
}


void
on_SAretour_supprimer_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *admin, *fenetre_supprimer;

fenetre_supprimer=lookup_widget(button,"fenetre_supprimer");

gtk_widget_destroy(fenetre_supprimer);
admin=create_admin();
gtk_widget_show(admin);
}


void
on_SAbutton_supprimer1_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *cin,*nom,*prenom;
GtkWidget *label_supprimer1;
GtkWidget *label_supprimer2;


int trouve;
int verif;
GtkWidget *entry;
Personne p;

nom = lookup_widget (button, "SAentry_supprimer");
prenom = lookup_widget (button, "SAentry_supprimer");
cin = lookup_widget (button, "SAentry_supprimer");
label_supprimer1= lookup_widget (button, "label_supprimer1");
label_supprimer2= lookup_widget (button, "label_supprimer2");



entry=lookup_widget(button,"SAentry_supprimer");
strcpy(p.nom,gtk_entry_get_text(GTK_ENTRY(entry)));
strcpy(p.prenom,gtk_entry_get_text(GTK_ENTRY(entry)));
strcpy(p.cin,gtk_entry_get_text(GTK_ENTRY(entry)));



trouve=verif1(cin);
if (trouve==1)
{(gtk_label_set_text(GTK_LABEL(label_supprimer1),"cet utilisateur a été supprimé\nla liste des utilisateurs a été actualisée"));
supprimer_personne(p);

}
else {(gtk_label_set_text(GTK_LABEL(label_supprimer2),"N°CIN INCORRECT\n veuillez saisir le N°cin correctement"));}

chercher_personne(); 

//message suppression
/*
if (trouve==0)
{(gtk_label_set_text(GTK_LABEL(label_supprimer1),"cet utilisateur a été supprimé\nla liste des utilisateurs a été actualisée"));


}
if (trouve==1)
{(gtk_label_set_text(GTK_LABEL(label_supprimer1),"cet utilisateur n'a pas été supprimé ou n'existe pas"));}

supprimer_personne(p);
chercher_personne();
 */
}


void
on_SAchanger_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *log_in, *redirect;

redirect=lookup_widget(button,"redirect");
log_in=lookup_widget(button,"log_in");

gtk_widget_destroy(log_in);
redirect=create_redirect();
gtk_widget_show(redirect);
}


void
on_ETUDIANT_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *os, *ns;

os=lookup_widget(objet,"redirect");

gtk_widget_destroy(os);

ns=create_EMTinscription();
gtk_widget_show(ns);
}




void
on_FOYER_clicked                       (GtkButton       *button,
                                        gpointer         user_data)
{

GtkWidget *window_agentfoyer_loula,*choix_fenetre ;

window_agentfoyer_loula=create_window_agentfoyer_loula();

gtk_widget_show(window_agentfoyer_loula);


choix_fenetre=lookup_widget(button,"choix_fenetre");


gtk_widget_destroy(choix_fenetre);





}


void
on_TECHNICIEN_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
  GtkWidget *redirect, *affichage_capteur;

  redirect=lookup_widget(objet,"redirect");

  gtk_widget_destroy(redirect);
  affichage_capteur=lookup_widget(objet,"affichage_capteur");
  affichage_capteur=create_affichage_capteur();
  gtk_widget_show (affichage_capteur);
}


void
on_ADMIN_clicked                       (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *choix_fenetre, *redirect;

redirect=lookup_widget(button,"redirect");
choix_fenetre=lookup_widget(button,"choix_fenetre");

gtk_widget_destroy(redirect);
choix_fenetre=create_choix_fenetre();
gtk_widget_show(choix_fenetre);
}


void
on_SAauth_clicked                      (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *log_in, *sign_in;

sign_in=lookup_widget(button,"sign_in");
log_in=lookup_widget(button,"log_in");

gtk_widget_destroy(sign_in);
log_in=create_log_in();
gtk_widget_show(log_in);
}


void
on_SAdec_clicked                       (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *admin, *redirect;

admin=lookup_widget(button,"admin");
redirect=lookup_widget(button,"redirect");

gtk_widget_destroy(admin);
redirect=create_redirect();
gtk_widget_show(redirect);
}


/////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////partie KHALIL/////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////







/////////////////////////////////////////////////////////////////




/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
void
on_button_agent_foyer_loula_connexion_clicked
                                        (GtkButton       *button,
                                       gpointer         user_data)


{ 
GtkWidget *windowAuth,*window_agentfoyer_loula; 



windowAuth= create_authentification ();
gtk_widget_show (windowAuth);

window_agentfoyer_loula=lookup_widget(button,"window_agentfoyer_loula");

gtk_widget_destroy(window_agentfoyer_loula);






}


void
on_button_agentfoyer_loula_inscription_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{

GtkWidget *windowinscription,
*window_agentfoyer_loula; 


windowinscription= create_windowinscription ();
gtk_widget_show (windowinscription);

window_agentfoyer_loula=lookup_widget(button,"window_agentfoyer_loula");

gtk_widget_destroy(window_agentfoyer_loula);






}






void
on_inscription_bouton_ajouter_clicked  (GtkButton       *button,
                                        gpointer         user_data)
{
FILE *f=NULL;
GtkWidget *log , *pass, *pre , *user, *rol, *windowAuth ; 
char nom[20];
char password[20];
char prenom[20];
char username[20];
char role[20];
log = lookup_widget(button,"inscriptionnom");
pass = lookup_widget(button,"inscriptionpassword");
pre = lookup_widget(button,"incriptionprenom");
user = lookup_widget(button,"inscriptionusername");
rol = lookup_widget(button,"inscriptionrole");

strcpy(nom,gtk_entry_get_text(GTK_ENTRY(log)));

strcpy(password,gtk_entry_get_text(GTK_ENTRY(pass)));


strcpy(prenom,gtk_entry_get_text(GTK_ENTRY(pre)));


strcpy(username,gtk_entry_get_text(GTK_ENTRY(user)));


strcpy(role,gtk_entry_get_text(GTK_ENTRY(rol)));


f=fopen("utilisateur.txt","a");
if(f!=NULL)
{
fprintf(f,"%s %s %s %s %s\n",username,password,nom,prenom,role);
fclose(f);}
else
printf("\n not found");
windowAuth= create_authentification ();
gtk_widget_show (windowAuth);



}


void
on_button_dejainscrit_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *authent,*inscri;
authent= create_authentification ();
gtk_widget_show (authent);
inscri = lookup_widget(button,"windowinscription");
gtk_widget_destroy(inscri);



}




//////////////////////////////////



 
/////////////////////emchi 334

//////////////////////////////MRIGLA 





void
on_authentificaion_bouton_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *login ,*treeview_niveau,*treeview, *passw,*windowerror,*windowagentfoyer,*error,*authen;
int trouve;
char username[20];
char password[20];
char errormsg[]="Username/Password invalide";

login = lookup_widget(button,"authentifactionusernamefield");
passw = lookup_widget(button,"authentificationpasswordfield");
error=lookup_widget(button,"authentificationincorrecte");

strcpy(username,gtk_entry_get_text(GTK_ENTRY(login)));
strcpy(password,gtk_entry_get_text(GTK_ENTRY(passw)));
trouve=verifier_khalil(username,password);
if(trouve==1){
windowagentfoyer= create_espaceagentfoyer ();
gtk_widget_show (windowagentfoyer);
authen=lookup_widget(button,"authentification");
gtk_widget_destroy(authen);

treeview=lookup_widget(windowagentfoyer,"treeview_etudiant");
treeview_niveau=lookup_widget(windowagentfoyer,"treeview_niveau");


afficherpersonne_khalil(treeview);
niveau_affiche(treeview_niveau);






}
else
{
gtk_label_set_text(GTK_LABEL(error),errormsg);}







}



/////////////////////////////////////////////////////////////////



etudiant e;


//////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////

void
on_radiobuttonfemme_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
strcpy(e.sex,"femme");


}


void
on_radiobuttonhomme_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
strcpy(e.sex,"homme");




}




void
on_radiobuttona2_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))

strcpy(e.chambre.type,"2pers");

}


void
on_radiobuttonindiv_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))

strcpy(e.chambre.type,"indiv");

}










////////////////////////////////////////////////////////
void
on_button_supprimer_etudiant_clicked   (GtkButton       *button,
                                        gpointer         user_data)
{

}





void
on_button_interface_ajout_etudiant_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data){
GtkWidget *ajoutet,*combobox_niveau,*espag;
ajoutet= create_ajoutetudiant ();



strcpy(e.sex,"femme");
strcpy(e.chambre.type,"2pers");
combobox_niveau=lookup_widget(ajoutet,"combobox_niveau");


gtk_combo_box_set_active(combobox_niveau,0);


gtk_widget_show (ajoutet);



espag=lookup_widget(button,"espaceagentfoyer");
gtk_widget_destroy(espag);

/////////////////////////////////////////////////


}




void
on_button_accueil_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{GtkWidget *agentfoyer,*ajout,*treeview_niveau,*treeview;
ajout=lookup_widget(button,"ajoutetudiant");
gtk_widget_destroy(ajout);
agentfoyer=create_espaceagentfoyer();

gtk_widget_show(agentfoyer);

treeview=lookup_widget(agentfoyer,"treeview_etudiant");
treeview_niveau=lookup_widget(agentfoyer,"treeview_niveau");
afficherpersonne_khalil(treeview);
niveau_affiche(treeview_niveau);
}

///////////////////////ajout etudiant
///////////////////////////////////////////////////////////////////////////////



void
on_button_ajout_etudiant_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *nomm,*prenomm,*cinn,*niveauu,*spinetage,*spinnumero,*msgvalid,*numerotel,*mail,*jour,*mois,*annee;




int check;

nomm = lookup_widget(button,"ajoutetudiantnom");

prenomm = lookup_widget(button,"ajoutetudiantprenom");

cinn = lookup_widget(button,"ajoutetudiantcin");///////////////

niveauu = lookup_widget(button,"combobox_niveau");

jour = lookup_widget(button,"spinbutton_jour");

mois = lookup_widget(button,"spinbutton_mois");

annee = lookup_widget(button,"spinbutton_annee");

numerotel = lookup_widget(button,"entry_tel");////////

mail = lookup_widget(button,"entry_mail");






msgvalid=lookup_widget(button,"label_confirmation_echec");

spinetage = lookup_widget(button,"spinbuttonetage");

spinnumero = lookup_widget(button,"spinbuttonnumero");



















strcpy(e.nom,gtk_entry_get_text(GTK_ENTRY(nomm)));

strcpy(e.prenom,gtk_entry_get_text(GTK_ENTRY(prenomm)));

strcpy(e.cin,gtk_entry_get_text(GTK_ENTRY(cinn)));

e.date.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));

e.date.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));

e.date.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));

strcpy(e.niveau,gtk_combo_box_get_active_text(GTK_COMBO_BOX(niveauu)));

strcpy(e.mail,gtk_entry_get_text(GTK_ENTRY(mail)));

strcpy(e.tel,gtk_entry_get_text(GTK_ENTRY(numerotel)));

e.chambre.etage=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinetage));

e.chambre.numero=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinnumero));




int cmpt=0;
if(strcmp(e.nom,"")==0)
cmpt+=1;
if(strcmp(e.prenom,"")==0)
cmpt+=1;
///////////////////////condition aal CIN TETZED
if(strcmp(e.cin,"")==0)
cmpt+=1;
//////////////////////////////////////////////////
if(strcmp(e.niveau,"")==0)
cmpt+=1;
if(strcmp(e.tel,"")==0)
cmpt+=1;
if(strcmp(e.mail,"")==0)
cmpt+=1;
if(cmpt>1)
gtk_label_set_text(GTK_LABEL(msgvalid),"veuillez remplir tous les champs");
else if(cmpt==1){
///////////////////////////////////////////////////////////
if((strcmp(e.nom,"")==0)&&(cmpt==1))

gtk_label_set_text(GTK_LABEL(msgvalid),"ajouter le nom");

else if((strcmp(e.prenom,"")==0)&&(cmpt==1))

gtk_label_set_text(GTK_LABEL(msgvalid),"ajouter le prenom");
///////////////////////condition aal CIN TETZED
else if((strcmp(e.cin,"")==0)&&(cmpt==1)){

////////////////////////////////////////////////////////LENA////////////
gtk_label_set_text(GTK_LABEL(msgvalid),"ajouter le N°CIN");
}




else if((strcmp(e.niveau,"")==0)&&(cmpt==1))

gtk_label_set_text(GTK_LABEL(msgvalid),"ajouter le Niveau");

else if((strcmp(e.tel,"")==0)&&(cmpt==1))

gtk_label_set_text(GTK_LABEL(msgvalid),"ajouter le N°Tel");

else if((strcmp(e.mail,"")==0)&&(cmpt==1))

gtk_label_set_text(GTK_LABEL(msgvalid),"ajouter le Mail");}


else{
check=recherche_etudiant(e.cin);
if(check==0){

ajouteretudiant(e);

niveau(1,e.niveau,"test");

gtk_label_set_text(GTK_LABEL(msgvalid),"l'etudiant(e) a été ajouté avec succès");}

else
gtk_label_set_text(GTK_LABEL(msgvalid),"l'etudiant(e) existe");
}
}





void
on_button_retour_inscription_clicked   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *inscri,*authent;
inscri= create_windowinscription ();
gtk_widget_show (inscri);
authent = lookup_widget(button,"authentification");
gtk_widget_destroy(authent);
}




/// li lfou9 
/////////////////////////////////////////////////////////////////////MRIGULIN LKOL 









//****************************************************************************//








///////////////// bouton recherche etudiant
void
on_button_recherche_etudiant_clicked   (GtkButton       *button,
                                        gpointer         user_data)
{char cin[100];

GtkWidget *input,*fenetre,*treeview_niveau,*espaceagentfoyer,*error;

GtkWidget *treeview;





input = lookup_widget(button,"recherche_etudiant_entry");

error = lookup_widget(button,"label_etudiant_introuvable");



strcpy(cin,gtk_entry_get_text(GTK_ENTRY(input)));
if (recherche_etudiant(cin)==0){
gtk_label_set_text(GTK_LABEL(error),"N°CIN introuvable");}
else{

fenetre=lookup_widget(button,"espaceagentfoyer");

espaceagentfoyer=create_espaceagentfoyer();

gtk_widget_show(espaceagentfoyer);

gtk_widget_hide(fenetre);






treeview=lookup_widget(espaceagentfoyer,"treeview_etudiant");
treeview_niveau=lookup_widget(espaceagentfoyer,"treeview_niveau");


afficherunepersonne_khalil(treeview,cin);
niveau_affiche(treeview_niveau);







}}
///*********************************************************************////////






////////////////////////MRIGLA//////////////










/////////////////////bouton actualiser/////////////////////////


///////////////////////////////TMCHI/////////


void
on_button_actualiser_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{

GtkWidget *treeview,*treeview_niveau,*fenetre,*espaceagentfoyer;


fenetre=lookup_widget(button,"espaceagentfoyer");

espaceagentfoyer=create_espaceagentfoyer();

gtk_widget_show(espaceagentfoyer);
gtk_widget_hide(fenetre);



treeview=lookup_widget(espaceagentfoyer,"treeview_etudiant");
treeview_niveau=lookup_widget(espaceagentfoyer,"treeview_niveau");
afficherpersonne_khalil(treeview);
niveau_affiche(treeview_niveau);




}
////////////////////////////////////////////////////////////////////
//////////////////////////////////////////MRIGLA////////////////////

etudiant c;
int valeurcombobox;

void
on_treeview_etudiant_row_activated     (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
gchar* nom;
gchar* prenom;
gchar* cin;
gchar* numero;
gchar* sex;
gchar* niveau;
gchar* chambre;
gchar* date;
gchar* tel;
gchar* mail;




GtkWidget *modif,*nomprenom;
modif= create_window_modification ();



/////////////////
GtkWidget *label_nv,*entry_nv,*combobox_niveau_mod,*label_date_jour,*label_date_mois,*label_date_annee,*spinbutton_date_jour,
*spinbutton_date_mois,*spinbutton_date_annee,*label_chambre_etage,*label_chambre_numero,*spinbutton_chambre_etage,*spinbutton_chambre_numero;



label_nv=lookup_widget(modif,"label_nv");////label
entry_nv=lookup_widget(modif,"entry_nv");//////entry

combobox_niveau_mod=lookup_widget(modif,"combobox_niveau_mod");/////combobox_niveau/////////////MAKHDHITCH L VALEUR TEEOU 


label_date_jour=lookup_widget(modif,"label_date_jour");/////label_date_jour;
label_date_mois=lookup_widget(modif,"label_date_mois");/////label_date_mois;
label_date_annee=lookup_widget(modif,"label_date_annee");/////label_date_ane;
spinbutton_date_jour=lookup_widget(modif,"spinbutton_date_jour");/////spinbuton_date_jour;
spinbutton_date_mois=lookup_widget(modif,"spinbutton_date_mois");/////spinbuton_date_mois;
spinbutton_date_annee=lookup_widget(modif,"spinbutton_date_annee");/////spinbuton_date_annee;



label_chambre_etage=lookup_widget(modif,"label_chambre_etage");/////label_chambre_etage
label_chambre_numero=lookup_widget(modif,"label_chambre_numero");/////label_chambre_numero;
spinbutton_chambre_etage=lookup_widget(modif,"spinbutton_chambre_etage");/////spinbutton_chambre_etage
spinbutton_chambre_numero=lookup_widget(modif,"spinbutton_chambre_numero");/////spinbutton_chambre_numero;



gtk_widget_hide (label_nv);
gtk_widget_hide (entry_nv);


gtk_widget_hide (label_date_jour);
gtk_widget_hide (label_date_mois);
gtk_widget_hide (label_date_annee);
gtk_widget_hide (spinbutton_date_jour);
gtk_widget_hide (spinbutton_date_mois);
gtk_widget_hide (spinbutton_date_annee);


gtk_widget_hide (label_chambre_etage);
gtk_widget_hide (label_chambre_numero);


gtk_widget_hide (spinbutton_chambre_etage);
gtk_widget_hide (spinbutton_chambre_numero);

gtk_widget_hide (combobox_niveau_mod);




////////////////////////////

gtk_widget_show (modif);



char msg[100];

GtkTreeModel *model=gtk_tree_view_get_model(treeview);
if(gtk_tree_model_get_iter(model,&iter,path)){
gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&nom,1,&prenom,2,&cin,3,&niveau,4,&chambre,5,&numero,6,&date,7,&tel,8,&mail,9,&sex,-1);



strcpy(c.cin,cin);
strcpy(c.nom,nom);
strcpy(msg,c.nom);
strcpy(c.prenom,prenom);
strcpy(c.niveau,niveau);
strcpy(c.mail,mail);
strcpy(c.tel,tel);

////////////////////////////BADALTHA TAAWA
if(strcmp(c.niveau,"1ere")==0)
valeurcombobox=0;
else if(strcmp(c.niveau,"2eme")==0)
valeurcombobox=1;
else if(strcmp(c.niveau,"3eme")==0)
valeurcombobox=2;
else if(strcmp(c.niveau,"4eme")==0)
valeurcombobox=3;
else
valeurcombobox=4;

//////////////////////////////////
 FILE *f=NULL;
   f=fopen("etudiant.txt","r");
int numero;

while(fscanf(f,"%s %s %s %s %d %s %d/%d/%d %s %s %s\n",e.nom,
e.prenom,e.cin,e.niveau,&numero,e.chambre.type,&e.date.jour,&e.date.mois,&e.date.annee,e.tel,e.mail,e.sex)!=EOF)
    {
      
if(strcmp(c.cin,e.cin)==0)
{c.date.jour=e.date.jour;
c.date.annee=e.date.annee;
c.date.mois=e.date.mois;
if(numero>=100){
c.chambre.etage=(numero/100);
c.chambre.numero=numero%100;
}
else
{
c.chambre.etage=(numero/10);
c.chambre.numero=(numero%10);
 }     

  }
  }
 








nomprenom=lookup_widget(modif,"label_nomprenom");
gtk_label_set_text(GTK_LABEL(nomprenom),strcat(strcat(msg," "),c.prenom));

}

}





///////////////////////////////////////TMCHI///////////////////////////////

void
on_button_supprimer_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *etsupp,*input;
char confirm[100];
input=lookup_widget(button,"entry_suppression");
etsupp=lookup_widget(button,"label_suppression_confirmer");
strcpy(confirm,gtk_entry_get_text(GTK_ENTRY(input)));
if(strcmp(confirm,"CONFIRMER")==0){
supprimerpersonne(c.cin);
niveau(3,c.niveau,"test");
gtk_label_set_text(GTK_LABEL(etsupp),"l'etudiant(e) a été supprimé(e) avec succès");
}
else 
gtk_label_set_text(GTK_LABEL(etsupp),"Réessayez");
}








/////////////////////////////////////////////////////////////////////
//mezelt////////////////////////////////////////////////////////////


void
on_button_modication_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{


GtkWidget *etudmodifie;
etudmodifie=lookup_widget(button,"label_modification_etudiant_modifie");
///////////////////////////////////////////////////////////////////////



 
GtkWidget *vmodifer,*input;
 
char valeur_a_modif[100];

input=lookup_widget(button,"entry_nv");
/////input dans le cas texte



vmodifer=lookup_widget(button,"combobox2");
strcpy(valeur_a_modif,gtk_combo_box_get_active_text(GTK_COMBO_BOX(vmodifer)));
///////////////


if(strcmp(valeur_a_modif,"Nom")==0){
strcpy(c.nom,gtk_entry_get_text(GTK_ENTRY(input)));

}
else if(strcmp(valeur_a_modif,"Prenom")==0){
strcpy(c.prenom,gtk_entry_get_text(GTK_ENTRY(input)));
}
else if(strcmp(valeur_a_modif,"Tel°")==0){
strcpy(c.tel,gtk_entry_get_text(GTK_ENTRY(input)));
}
else if(strcmp(valeur_a_modif,"Mail")==0){
strcpy(c.mail,gtk_entry_get_text(GTK_ENTRY(input)));

}
else if(strcmp(valeur_a_modif,"DateNaissance")==0){

GtkWidget *nouvjour,*nouvmois,*nouvannee;
nouvjour=lookup_widget(button,"spinbutton_date_jour");
nouvmois=lookup_widget(button,"spinbutton_date_mois");
nouvannee=lookup_widget(button,"spinbutton_date_annee");
c.date.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(nouvjour));
c.date.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(nouvmois));
c.date.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(nouvannee));}


///////////////////////////
else if(strcmp(valeur_a_modif,"Num°Chambre")==0){
GtkWidget *nouvetage,*nouvnumero;
nouvetage=lookup_widget(button,"spinbutton_chambre_etage");
nouvnumero=lookup_widget(button,"spinbutton_chambre_numero");
c.chambre.etage=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(nouvetage));
c.chambre.numero=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(nouvnumero));
}




else {
GtkWidget *combobox_niveau_mod;
combobox_niveau_mod=lookup_widget(button,"combobox_niveau_mod");
char ancniveau[100];
strcpy(ancniveau,c.niveau);
strcpy(c.niveau,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox_niveau_mod)));
niveau(2,ancniveau,c.niveau);
}


modif_khalil(c,valeur_a_modif);





















gtk_label_set_text(GTK_LABEL(etudmodifie),"l'etudiant(e) a été modifié avec succès");
}







/////////////MRIGLA NE9SA LABEL ETAGE W CHAMBRE MAYBENOUCH//////////////////////



void
on_combobox2_changed                   (GtkComboBox     *combobox,
                                        gpointer         user_data)
{GtkWidget *label_nv,*entry_nv,*combobox2,*label_date_jour,*label_date_mois,*label_date_annee,*spinbutton_date_jour,*spinbutton_date_mois,*spinbutton_date_annee;


GtkWidget *label_chambre_etage,*label_chambre_numero,*combobox_niveau_mod,*spinbutton_chambre_etage,*spinbutton_chambre_numero;

char valcombo[100];


label_nv=lookup_widget(combobox,"label_nv");////label
entry_nv=lookup_widget(combobox,"entry_nv");//////entry
combobox2=lookup_widget(combobox,"combobox2");/////combobox
combobox_niveau_mod=lookup_widget(combobox,"combobox_niveau_mod");/////combobox_niveau/////////////MAKHDHITCH L VALEUR TEEOU 


label_date_jour=lookup_widget(combobox,"label_date_jour");/////label_date_jour;
label_date_mois=lookup_widget(combobox,"label_date_mois");/////label_date_mois;
label_date_annee=lookup_widget(combobox,"label_date_annee");/////label_date_ane;
spinbutton_date_jour=lookup_widget(combobox,"spinbutton_date_jour");/////spinbuton_date_jour;
spinbutton_date_mois=lookup_widget(combobox,"spinbutton_date_mois");/////spinbuton_date_mois;
spinbutton_date_annee=lookup_widget(combobox,"spinbutton_date_annee");/////spinbuton_date_annee;



label_chambre_etage=lookup_widget(combobox,"label_chambre_etage");/////label_chambre_etage
label_chambre_numero=lookup_widget(combobox,"label_chambre_numero");/////label_chambre_numero;
spinbutton_chambre_etage=lookup_widget(combobox,"spinbutton_chambre_etage");/////spinbutton_chambre_etage
spinbutton_chambre_numero=lookup_widget(combobox,"spinbutton_chambre_numero");/////spinbutton_chambre_numero;












strcpy(valcombo,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox2)));



/////////////////////////NEBDEW//////////////////////





if(strcmp(valcombo,"Nom")==0){
gtk_label_set_text(GTK_LABEL(label_nv),"Nouveau Nom :");
gtk_widget_show (label_nv);
gtk_widget_show (entry_nv);
gtk_entry_set_text(entry_nv,c.nom);
gtk_widget_hide (label_date_jour);
gtk_widget_hide (label_date_mois);
gtk_widget_hide (label_date_annee);
gtk_widget_hide (spinbutton_date_jour);
gtk_widget_hide (spinbutton_date_mois);
gtk_widget_hide (spinbutton_date_annee);///////////////////////////cbn
gtk_widget_hide (label_chambre_etage);
gtk_widget_hide (label_chambre_numero);
gtk_widget_hide (spinbutton_chambre_etage);
gtk_widget_hide (spinbutton_chambre_numero);
/////combolekher
gtk_widget_hide (combobox_niveau_mod);



}





///////////////////////////////////li fehom input//////////////////////
else if(strcmp(valcombo,"Prenom")==0){
gtk_label_set_text(GTK_LABEL(label_nv),"Nouveau Prenom :");
gtk_widget_show (label_nv);
gtk_widget_show (entry_nv);
gtk_entry_set_text(entry_nv,c.prenom);
gtk_widget_hide (label_date_jour);
gtk_widget_hide (label_date_mois);
gtk_widget_hide (label_date_annee);
gtk_widget_hide (spinbutton_date_jour);
gtk_widget_hide (spinbutton_date_mois);
gtk_widget_hide (spinbutton_date_annee);//////////////////cbn
gtk_widget_hide (label_chambre_etage);
gtk_widget_hide (label_chambre_numero);
gtk_widget_hide (spinbutton_chambre_etage);
gtk_widget_hide (spinbutton_chambre_numero);

/////comboboxlekher



gtk_widget_hide (combobox_niveau_mod);



}
else if(strcmp(valcombo,"Tel°")==0){
gtk_label_set_text(GTK_LABEL(label_nv),"Nouveau N° Tel :");
gtk_widget_show (label_nv);
gtk_widget_show (entry_nv);
gtk_entry_set_text(entry_nv,c.tel);
gtk_widget_hide (label_date_jour);
gtk_widget_hide (label_date_mois);
gtk_widget_hide (label_date_annee);
gtk_widget_hide (spinbutton_date_jour);
gtk_widget_hide (spinbutton_date_mois);
gtk_widget_hide (spinbutton_date_annee);
gtk_widget_hide (label_chambre_etage);
gtk_widget_hide (label_chambre_numero);
gtk_widget_hide (spinbutton_chambre_etage);
gtk_widget_hide (spinbutton_chambre_numero);
////////



gtk_widget_hide (combobox_niveau_mod);


}
else if(strcmp(valcombo,"Mail")==0){
gtk_label_set_text(GTK_LABEL(label_nv),"Nouveau Mail :");
gtk_widget_show (label_nv);
gtk_widget_show (entry_nv);
gtk_entry_set_text(entry_nv,c.mail);
gtk_widget_hide (label_date_jour);
gtk_widget_hide (label_date_mois);
gtk_widget_hide (label_date_annee);
gtk_widget_hide (spinbutton_date_jour);
gtk_widget_hide (spinbutton_date_mois);
gtk_widget_hide (spinbutton_date_annee);///////////////////////////cbn
gtk_widget_hide (label_chambre_etage);
gtk_widget_hide (label_chambre_numero);
gtk_widget_hide (spinbutton_chambre_etage);
gtk_widget_hide (spinbutton_chambre_numero);
/////

gtk_widget_hide (combobox_niveau_mod);
}
///////////////////////////////////////////////spinbutton///////////////





/////////////////////date naissance//////////////////

else if(strcmp(valcombo,"DateNaissance")==0){
gtk_label_set_text(GTK_LABEL(label_nv),"Nouvelle Date de Naissance  :");
gtk_widget_show (label_nv);
gtk_widget_hide (entry_nv);

gtk_widget_show (label_date_jour);

gtk_widget_show (label_date_mois);

gtk_widget_show (label_date_annee);
gtk_widget_show (spinbutton_date_jour);
gtk_spin_button_set_value(spinbutton_date_jour,c.date.jour);

gtk_widget_show (spinbutton_date_mois);
gtk_spin_button_set_value(spinbutton_date_mois,c.date.mois);
gtk_widget_show (spinbutton_date_annee);
gtk_spin_button_set_value(spinbutton_date_annee,c.date.annee);
//////////////////////////cbn
gtk_widget_hide (label_chambre_etage);
gtk_widget_hide (label_chambre_numero);
gtk_widget_hide (spinbutton_chambre_etage);
gtk_widget_hide (spinbutton_chambre_numero);

///////


gtk_widget_hide (combobox_niveau_mod);

}

/////////////////////chambre////////////////////////////

else if(strcmp(valcombo,"Num°Chambre")==0){
gtk_label_set_text(GTK_LABEL(label_nv),"Nouvelle Chambre :");
gtk_widget_show (label_nv);
gtk_widget_hide (entry_nv);
gtk_widget_show (label_chambre_etage);

gtk_widget_show (label_chambre_numero);

gtk_widget_show (spinbutton_chambre_etage);
gtk_spin_button_set_value(spinbutton_chambre_etage,c.chambre.etage);
gtk_widget_show (spinbutton_chambre_numero);
gtk_spin_button_set_value(spinbutton_chambre_numero,c.chambre.numero);//////////////////////////cbn

gtk_widget_hide (label_date_jour);
gtk_widget_hide (label_date_mois);
gtk_widget_hide (label_date_annee);
gtk_widget_hide (spinbutton_date_jour);
gtk_widget_hide (spinbutton_date_mois);
gtk_widget_hide (spinbutton_date_annee);
///////


gtk_widget_hide (combobox_niveau_mod);






}

else {
gtk_label_set_text(GTK_LABEL(label_nv),"NV Niveau :");
gtk_widget_show (label_nv);
gtk_widget_hide (entry_nv);
gtk_widget_hide (label_chambre_etage);
gtk_widget_hide (label_chambre_numero);
gtk_widget_hide (spinbutton_chambre_etage);
gtk_widget_hide (spinbutton_chambre_numero);//////////////////////////cbn

gtk_widget_hide (label_date_jour);
gtk_widget_hide (label_date_mois);
gtk_widget_hide (label_date_annee);
gtk_widget_hide (spinbutton_date_jour);
gtk_widget_hide (spinbutton_date_mois);
gtk_widget_hide (spinbutton_date_annee);
///////
gtk_widget_show (combobox_niveau_mod);
gtk_combo_box_set_active(combobox_niveau_mod,valeurcombobox);









}
}




/////////////////////////////////////////////////////////////////////////TOUFAAAAAA///////////////////









/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////partie AHMED/////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////

int x=1;
int t[2]={0,0};
char ch[100];
produit pr;










void
on_RESTO_clicked                       (GtkButton       *button,
                                        gpointer         user_data)
{




GtkWidget *window_ahmed_loula,*choix_fenetre ;

window_ahmed_loula=create_window_ahmed_loula();

gtk_widget_show(window_ahmed_loula);


choix_fenetre=lookup_widget(button,"choix_fenetre");


gtk_widget_destroy(choix_fenetre);



}








void
on_button_ahmed_loula_connexion_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowAuth,*window_ahmed_loula; 



windowAuth= create_affichage_produit ();
gtk_widget_show (windowAuth);

window_ahmed_loula=lookup_widget(button,"window_ahmed_loula_loula");

gtk_widget_destroy(window_ahmed_loula);
}


void
on_button_ahmed_loula_inscription_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowAuth,*window_ahmed_loula; 



windowAuth= create_ajout_produit ();
gtk_widget_show (windowAuth);

window_ahmed_loula=lookup_widget(button,"window_ahmed_loula_loula");

gtk_widget_destroy(window_ahmed_loula);
}


void
on_button1_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
if (t[0]==1)
{
GtkWidget *entry_nom;
char r[100];
entry_nom=lookup_widget(button,"entry1_at");
strcpy(r,gtk_entry_get_text(GTK_ENTRY(entry_nom) ) );
rechercher_produit1(r);
GtkWidget *affiche;
affiche=lookup_widget(button,"affichage_produit");
strcpy(ch,"produits1.txt");
afficher_produit(lookup_widget(affiche,"treeview1_at"),ch);
}
if (t[1]==1)
{
GtkWidget *Jour1,*Mois1,*Annee1,*Combobox1;
int jo,mo,an;
char type1[100];
Jour1=lookup_widget(button,"entry_jour1_at");
Mois1=lookup_widget(button,"entry_mois1_at");
Annee1=lookup_widget(button,"entry_annee1_at");
Combobox1=lookup_widget(button,"combobox1_at");
jo= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Jour1));
mo= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Mois1));
an= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Annee1));
strcpy(type1,gtk_combo_box_get_active_text(GTK_COMBO_BOX(Combobox1)));
rechercher_produit2(jo,mo,an,type1);
GtkWidget *affiche;
affiche=lookup_widget(button,"affichage_produit");
strcpy(ch,"produits2.txt");
afficher_produit(lookup_widget(affiche,"treeview1_at"),ch);



}
}


void
on_button3_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *ajouter;
ajouter= create_ajout_produit();
gtk_widget_show (ajouter);
}


void
on_button2_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
supprimer_produit(pr.d.jour,pr.d.mois,pr.d.annee,pr.type);

GtkWidget *confirmesupprimer,*msg;

msg=lookup_widget(button,"label132_at");
confirmesupprimer=lookup_widget(button,"affichage_produit");
gtk_label_set_text(GTK_LABEL(msg),"supression faite avec succès");
strcpy(ch,"produits.txt");

afficher_produit(lookup_widget(confirmesupprimer,"treeview1_at"),ch);

}


void
on_button4_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *modif;
char chj[10],chm[10],cha[10];
modif = create_modifier_produit();
  gtk_widget_show (modif);

GtkWidget* msgjour=lookup_widget(modif,"label21_at");
sprintf(chj,"%d",pr.d.jour);
gtk_label_set_text(GTK_LABEL(msgjour),chj);
gtk_widget_show(msgjour);

GtkWidget* msgmois=lookup_widget(modif,"label23_at");
sprintf(chm,"%d",pr.d.mois);
gtk_label_set_text(GTK_LABEL(msgmois),chm);
gtk_widget_show(msgmois);


GtkWidget* msgannee=lookup_widget(modif,"label25_at");
sprintf(cha,"%d",pr.d.annee);
gtk_label_set_text(GTK_LABEL(msgannee),cha);
gtk_widget_show(msgannee);

gtk_entry_set_text(GTK_ENTRY(lookup_widget(modif,"entry4_at")),pr.produit.nom);
gtk_entry_set_text(GTK_ENTRY(lookup_widget(modif,"entry5_at")),pr.produit.quantite);
gtk_entry_set_text(GTK_ENTRY(lookup_widget(modif,"entry6_at")),pr.produit.prix);
}


void
on_button5_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *affiche;
affiche=lookup_widget(button,"affichage_produit");
strcpy(ch,"produits.txt");
afficher_produit(lookup_widget(affiche,"treeview1_at"),ch);
}


void
on_button6_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *entry_quant;
char r[100];
entry_quant=lookup_widget(button,"entry2_at");
strcpy(r,gtk_entry_get_text(GTK_ENTRY(entry_quant) ) );
rechercher_produit_repture_de_stock(r);
GtkWidget *affiche;
affiche=lookup_widget(button,"affichage_produit");
strcpy(ch,"produits_hors_stock.txt");
afficher_produit(lookup_widget(affiche,"treeview1_at"),ch);
}


void
on_button8_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
produit p;
int verifier;
GtkWidget *affichage;
GtkWidget *input1, *input2, *input3, *entry_type ,*Jour,*Mois,*Annee,*msg;
GtkWidget *Ajout;
Ajout=lookup_widget(button,"ajout_produit");

input1=lookup_widget(button,"entry_nom_at");
input2=lookup_widget(button,"entry_quant_at");
input3=lookup_widget(button,"entry_prix_at");
Jour=lookup_widget(button,"entry_jour_at");
Mois=lookup_widget(button,"entry_mois_at");
Annee=lookup_widget(button,"entry_annee_at");

msg=lookup_widget(button,"label130");

strcpy(p.produit.nom,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(p.produit.quantite,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(p.produit.prix,gtk_entry_get_text(GTK_ENTRY(input3)));
 if (x==1)
 {
   strcpy(p.type,"legumes");
 }
else if (x==2)
 {
   strcpy(p.type,"fruits");
 }


 p.d.jour = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Jour));
 p.d.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Mois));
 p.d.annee = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Annee));



ajout_produit(p);
gtk_label_set_text(GTK_LABEL(msg),"produit ajouté avec succès");
 


verifier=verifier_produit(p.produit.nom);
if(verifier==1)
{
  gtk_label_set_text(GTK_LABEL(msg),"Ce produit existe deja");
}
//gtk_widget_destroy(Ajout);
}


void
on_button7_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Ajout;
Ajout=lookup_widget(button,"ajout_produit");
gtk_widget_destroy(Ajout);
}


void
on_button10_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *mod;
mod=lookup_widget(button,"modifier_produit");
gtk_widget_destroy(mod);
}


void
on_button9_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *entry_nom, *entry_quantite, *entry_prix,*Jour,*Mois,*Annee,*mod;
mod=lookup_widget(button,"modifier_produit");
entry_nom=lookup_widget(button,"entry4_at");
entry_quantite=lookup_widget(button,"entry5_at");
entry_prix=lookup_widget(button,"entry6_at");

strcpy(pr.produit.nom,gtk_entry_get_text(GTK_ENTRY(entry_nom) ) );
strcpy(pr.produit.quantite,gtk_entry_get_text(GTK_ENTRY(entry_quantite) ) );
strcpy(pr.produit.prix,gtk_entry_get_text(GTK_ENTRY(entry_prix) ) );

modifier_produit(pr);
gtk_widget_destroy(mod);
}


void
on_checkbutton4_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{t[0]=1;}
}


void
on_checkbutton3_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{t[1]=1;}
}


/*void
on_radiobutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{
  x=2;
}

}*/


void
on_radiobutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)

{

  x=1;

 
}

produit pr;

void
on_treeview1_at_row_activated          (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
        gint *j;
        gint *m;
        gint *a;
        gchar  *type;
	gchar  *nom;
        gchar *quantite;
	gchar *prix;
	

      
       GtkTreeIter iter;
	
	

	GtkTreeModel *model =gtk_tree_view_get_model(treeview);

	if (gtk_tree_model_get_iter(model, &iter , path))
	{ 
	  gtk_tree_model_get (GTK_LIST_STORE(model), &iter,  0, &j,1,&m,2,&a,3,&type,4,&nom,5,&quantite,6,&prix,-1);
	  pr.d.jour=j;
	  pr.d.mois=m;
	  pr.d.annee=a;
	  strcpy(pr.type,type);
	  strcpy(pr.produit.nom,nom);
	  strcpy(pr.produit.quantite,quantite);
	  strcpy(pr.produit.prix,prix);


	}
}


void
on_radiobutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

  x=2;

}


void
on_button11_at_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window_ahmed_loula,*choix_fenetre ;

window_ahmed_loula=create_window_ahmed_loula();

gtk_widget_show(window_ahmed_loula);


choix_fenetre=lookup_widget(button,"affichage_produit");


gtk_widget_destroy(choix_fenetre);
}


void
on_button12_at_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window_ahmed_loula,*choix_fenetre ;

window_ahmed_loula=create_redirect();

gtk_widget_show(window_ahmed_loula);


choix_fenetre=lookup_widget(button,"window_ahmed_loula");


gtk_widget_destroy(choix_fenetre);
}
///////////////////////////////////////////////////////////////////
////****capteur****////////////////////////////////

void
on_button12_affich_pg_capt_ajout_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
  GtkWidget *ajout_capteur,*affichage_capteur;
  GtkWidget *treeview1_couli;

  ajout_capteur=lookup_widget(objet,"ajout_capteur");

  gtk_widget_destroy(ajout_capteur);
  
  affichage_capteur=create_affichage_capteur();
  
  gtk_widget_show(affichage_capteur);

  treeview1_couli=lookup_widget(affichage_capteur,"treeview1_couli");

  afficher_capteur(treeview1_couli);

}


void
on_button11_ajouter_capteur_pg_clicked (GtkWidget       *objet,
                                        gpointer         user_data)
{
   capteur c;
  DATE datee;
  GtkWidget *input1,*input2, *input3, *input4, *input5, *input6,*jour, *mois,*annee,*sortie;
  GtkWidget *ajout_capteur;
   char texte[50];
  ajout_capteur=lookup_widget(objet,"ajout_capteur");
  
  input1=lookup_widget(objet,"entry1_couli");
  input2=lookup_widget(objet,"entry2_couli");
  input3=lookup_widget(objet,"entry3_couli");
  input4=lookup_widget(objet,"entry4_couli");
  input5=lookup_widget(objet,"combobox3_couli");
  input6=lookup_widget(objet,"radiobutton3_couli");
  jour=lookup_widget(objet,"spinbutton4_couli");
  mois=lookup_widget(objet,"spinbutton5_couli");
  annee=lookup_widget(objet,"spinbutton6_couli");
  sortie=lookup_widget(objet,"label149");

  strcpy(texte,"le capteur a été ajouter avec succè");
  strcpy(c.marque,gtk_entry_get_text(GTK_ENTRY(input1)));
  strcpy(c.reference,gtk_entry_get_text(GTK_ENTRY(input2)));
  strcpy(c.valeur,gtk_entry_get_text(GTK_ENTRY(input3)));
  strcpy(c.prix,gtk_entry_get_text(GTK_ENTRY(input4)));
  strcpy(c.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input5)));
   if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(input6)))        
    strcpy(c.etat, "fonctionnel");
  c.datee.jour = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
  c.datee.mois = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
  c.datee.annee = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
  gtk_label_set_text(GTK_LABEL(sortie),texte);

  ajouter_capteur(c);
}


void
on_treeview1_couli_row_activated       (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
   GtkTreeIter iter;
  gchar* marque;
  gchar* reference;
  gchar* valeur;
  gchar* prix;
  gchar* type;
  gchar* etat;
  gchar* date;
  capteur c;

  GtkTreeModel *model = gtk_tree_view_get_model(treeview);

  if(gtk_tree_model_get_iter(model, &iter, path)){
	
	gtk_tree_model_get (GTK_LIST_STORE(model), &iter,0,&marque,1,&reference,2,&valeur,3,&prix,4,&type,5,&etat,6,&date, -1);
	 
	strcpy(c.marque,marque);
	strcpy(c.reference,reference);
	strcpy(c.valeur,valeur);
	strcpy(c.prix,prix);
	strcpy(c.type,type);
	strcpy(c.etat,etat);
	strcpy(c.datee.jour,date);
	strcpy(c.datee.mois,date);
	strcpy(c.datee.annee,date);
	

	supprimer_capteur(c);
	afficher_capteur(treeview);
	modification_capteur(c);
}

}


void
on_button14_ajout_pg_affich_clicked    (GtkWidget       *objet,
                                        gpointer         user_data)
{
  GtkWidget *ajout_capteur, *affichage_capteur;

  affichage_capteur=lookup_widget(objet,"affichage_capteur");

  gtk_widget_destroy(affichage_capteur);
  ajout_capteur=lookup_widget(objet,"ajout_capteur");
  ajout_capteur=create_ajout_capteur();
  gtk_widget_show (ajout_capteur);
}


void
on_button15_modif_capt_pg_affich_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
  GtkWidget *modifier_capteur, *affichage_capteur;

  affichage_capteur=lookup_widget(objet,"affichage_capteur");

  gtk_widget_destroy(affichage_capteur);
  modifier_capteur=lookup_widget(objet,"modifier_capteur");
  modifier_capteur=create_modifier_capteur();
  gtk_widget_show (modifier_capteur);
}


void
on_button17_cap_defectueux_clicked     (GtkWidget       *objet,
                                        gpointer         user_data)
{
  GtkWidget *capteur_defectueux, *affichage_capteur;

  affichage_capteur=lookup_widget(objet,"affichage_capteur");

  gtk_widget_destroy(affichage_capteur);
  capteur_defectueux=lookup_widget(objet,"capteur_defectueux");
  capteur_defectueux=create_capteur_defectueux();
  gtk_widget_show (capteur_defectueux);
}


void
on_button11_actu_pg_affich_clicked     (GtkWidget       *objet,
                                        gpointer         user_data)
{
  GtkWidget *c1,*affichage_capteur;
  GtkWidget *treeview1_couli;

  c1=lookup_widget(objet,"affichage_capteur");
  
  affichage_capteur=create_affichage_capteur();
  
  gtk_widget_show(affichage_capteur);
  gtk_widget_hide(c1);

  treeview1_couli=lookup_widget(affichage_capteur,"treeview1_couli");
  
  vider(treeview1_couli);
  afficher_capteur(treeview1_couli);
}


void
on_button12_acceuil_pg_cap_clicked     (GtkWidget       *objet,
                                        gpointer         user_data)
{
  GtkWidget *redirect, *affichage_capteur;

  affichage_capteur=lookup_widget(objet,"affichage_capteur");

  gtk_widget_destroy(affichage_capteur);
 
  redirect=create_redirect();
  gtk_widget_show (redirect);
}


void
on_button16_supp_pg_affich_clicked     (GtkWidget       *objet,
                                        gpointer         user_data)
{
  GtkWidget *supprimer_capteur, *affichage_capteur;
 
  affichage_capteur=lookup_widget(objet,"affichage_capteur");

  gtk_widget_destroy(affichage_capteur);
  supprimer_capteur=lookup_widget(objet,"supprimer_capteur");
  supprimer_capteur=create_supprimer_capteur();
  gtk_widget_show (supprimer_capteur);
}


void
on_button11_supp_capteur_pg_clicked    (GtkWidget       *objet,
                                        gpointer         user_data)
{
  capteur c;
   GtkWidget *input8;
   GtkWidget *treeview1_couli;
   GtkWidget *supprime_capteur;
   supprime_capteur=lookup_widget(objet,"supprimer_capteur");
   input8=lookup_widget(objet,"entry1_scouli");
   strcpy(c.reference,gtk_entry_get_text(GTK_ENTRY(input8)));
   supprimer_capteur(c);
   treeview1_couli=lookup_widget(objet,"treeview1_couli");
   afficher_capteur(treeview1_couli);

}


void
on_button12_retour_pg_supcap_clicked   (GtkWidget       *objet,
                                        gpointer         user_data)
{
  GtkWidget *supprimer_capteur,*affichage_capteur;

  supprimer_capteur=lookup_widget(objet,"supprimer_capteur");

  gtk_widget_destroy(supprimer_capteur);
  
  affichage_capteur=create_affichage_capteur();
  
  gtk_widget_show(affichage_capteur);
}


void
on_button12_actu_pg_capdef_clicked     (GtkWidget       *objet,
                                        gpointer         user_data)
{
   GtkWidget *c1,*capteur_defectueux;
  GtkWidget *treeview1_coulib;

  c1=lookup_widget(objet,"capteur_defectueux");
  
  capteur_defectueux=create_capteur_defectueux();
  
  gtk_widget_show(capteur_defectueux);
  gtk_widget_hide(c1);

  treeview1_coulib=lookup_widget(capteur_defectueux,"treeview1_coulib");
  
  vider(treeview1_coulib);
  defectueux_capteur(treeview1_coulib); 
}


void
on_button11_retour_pg_def_clicked      (GtkWidget       *objet,
                                        gpointer         user_data)
{
  GtkWidget *capteur_defectueux,*affichage_capteur;

  capteur_defectueux=lookup_widget(objet,"capteur_defectueux");

  gtk_widget_destroy(capteur_defectueux);
  
  affichage_capteur=create_affichage_capteur();
  
  gtk_widget_show(affichage_capteur);
}


void
on_button13_rech_capteur_clicked       (GtkWidget       *objet,
                                        gpointer         user_data)
{
   capteur c;
GtkWidget *input0;
char tempo[20];
input0=lookup_widget(objet,"entry_coulis");
strcpy(tempo,gtk_entry_get_text(GTK_ENTRY(input0) ) );
GtkWidget *c1,*affichage_capteur;
  GtkWidget *treeview1_couli;

  c1=lookup_widget(objet,"affichage_capteur");
  
  affichage_capteur=create_affichage_capteur();
  
  gtk_widget_show(affichage_capteur);
  gtk_widget_hide(c1);

  treeview1_couli=lookup_widget(affichage_capteur,"treeview1_couli");
  
  vider(treeview1_couli);
   recherche_capteur(treeview1_couli,tempo);
}


void
on_treeview1_coulib_row_activated      (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
  GtkTreeIter iter;
  gchar* marque;
  gchar* reference;
  gchar* valeur;
  gchar* prix;
  gchar* type;
  gchar* etat;
  gchar* date;
  capteur c;

  GtkTreeModel *model = gtk_tree_view_get_model(treeview);

  if(gtk_tree_model_get_iter(model, &iter, path)){
	
	gtk_tree_model_get (GTK_LIST_STORE(model), &iter,0,&marque,1,&reference,2,&valeur,3,&prix,4,&type,5,&etat,6,&date, -1);
	
	strcpy(c.marque,marque);
	strcpy(c.reference,reference);
	strcpy(c.valeur,valeur);
	strcpy(c.prix,prix);
	strcpy(c.type,type);
	strcpy(c.etat,etat);
	strcpy(c.datee.jour,date);
	strcpy(c.datee.mois,date);
	strcpy(c.datee.annee,date);
	
 	
	supprimer_capteur(c);
	defectueux_capteur(treeview);
	modification_capteur(c);

}

}


void
on_button11_enregister_mod_pg_clicked  (GtkWidget       *objet,
                                        gpointer         user_data)
{
  capteur c;
  DATE datee;
 GtkWidget *input9,*input10,*input11,*input12,*input13,*input14,*input15,*jour1,*mois1,*annee1,*output;
GtkWidget *modifier_capteur;
char text[100];

modifier_capteur=lookup_widget(objet,"modifier_capteur");

input9 = lookup_widget(objet, "entry2_baly") ;
input10= lookup_widget(objet, "entry1_baly") ;
input11= lookup_widget(objet, "entry3_baly");
input12=lookup_widget(objet, "entry4_baly");
input13= lookup_widget(objet, "combobox3_baly");
input14=lookup_widget(objet, "checkbutton5_baly");
input15=lookup_widget(objet, "checkbutton6_baly");
jour1=lookup_widget(objet, "spinbutton4_baly");
mois1=lookup_widget(objet, "spinbutton5_baly");
annee1= lookup_widget(objet, "spinbutton6_baly");
output=lookup_widget(objet,"label169_baly");

strcpy(text,"vos modifications ont été enregistrer");
strcpy(c.marque,gtk_entry_get_text(GTK_ENTRY(input9)));
strcpy(c.reference,gtk_entry_get_text(GTK_ENTRY(input10)));
strcpy(c.valeur,gtk_entry_get_text(GTK_ENTRY(input11)));
strcpy(c.prix,gtk_entry_get_text(GTK_ENTRY(input12)));
strcpy(c.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input13)));
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(input14)))
strcpy(c.etat,"fonctionnel");
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(input15)))
strcpy(c.etat,"défectueux");
 
c.datee.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour1));
c.datee.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois1));
c.datee.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee1));
 gtk_label_set_text(GTK_LABEL(output),text);

modification_capteur(c);

}


void
on_button12_retour_pg_modif_clicked    (GtkWidget       *objet,
                                        gpointer         user_data)
{
  GtkWidget *modifier_capteur,*affichage_capteur;

  modifier_capteur=lookup_widget(objet,"modifier_capteur");

  gtk_widget_destroy(modifier_capteur);
  
  affichage_capteur=create_affichage_capteur();
  
  gtk_widget_show(affichage_capteur);
}


void
on_radiobutton3_couli_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
  capteur c;
  if (gtk_toggle_button_get_active (GTK_RADIO_BUTTON(togglebutton)))         strcpy(c.etat, "fonctionnel");
}


void
on_checkbutton6_baly_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
  capteur c;
   if (gtk_toggle_button_get_active (togglebutton))         strcpy(c.etat, "défectueux");
}


void
on_checkbutton5_baly_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
   capteur c;
   if (gtk_toggle_button_get_active (togglebutton))         strcpy(c.etat, "fonctionnel");
}
// -------------------------------------------PARTIE EMNA----------------------------------------



char alerte[]="faible",raisonn[]="--",alertem[200]="--";

//-------------------------------------BOUTTON Ajouter--------------------
void
on_EMTbutton10_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
reclamation r;


GtkWidget *entryID;

GtkWidget *entryDetails;

GtkWidget *comboService;

GtkWidget *comboObjet;

GtkWidget *calendar;

GtkWidget *spinnote;

int jj,mm,aa,b=1;

char msg[50];







char textee[100];

GtkWidget *p;

p=lookup_widget(objet,"EMTtreeview1");

entryID=lookup_widget(objet,"EMTentry11");

entryDetails=lookup_widget(objet,"EMTentry7");


comboService=lookup_widget(objet,"EMTcombobox5");

comboObjet=lookup_widget(objet,"EMTcombobox6");


calendar=lookup_widget(objet,"EMTcalendar10");


spinnote=lookup_widget(objet,"EMTspinbutton11");

//hide  label ajoute avec succes
gtk_widget_hide (lookup_widget(objet,"EMTlabel100"));


/*Controle saisie*/

strcpy(r.id,gtk_entry_get_text(GTK_ENTRY(entryID)));




/*
if(strcmp(r.id,"")==0){
		  gtk_widget_show(lookup_widget(objet,"EMTlabel111"));
b=0;
}
else {
		  gtk_widget_hide(lookup_widget(objet,"EMTlabel111"));
b=1;
}*/
int y=0;

if((exist_reclamation(r.id)!=0)||(strcmp(r.id,"")==0)){
gtk_widget_hide(lookup_widget(objet,"EMTlabel100"));
gtk_widget_hide (lookup_widget(objet,"EMTlabel51"));
gtk_widget_hide (lookup_widget(objet,"EMTlabel61"));
y=1;
	if(strcmp(r.id,"")==0){
		  gtk_widget_show(lookup_widget(objet,"EMTlabel111"));
			gtk_widget_hide(lookup_widget(objet,"EMTlabel112"));}
	else{
		  gtk_widget_show(lookup_widget(objet,"EMTlabel112"));
		  gtk_widget_hide(lookup_widget(objet,"EMTlabel111"));}
b=0;
}
else {
		  gtk_widget_hide(lookup_widget(objet,"EMTlabel112"));
		 gtk_widget_hide(lookup_widget(objet,"EMTlabel111"));
b=1;
}

if(y==0){
if(gtk_combo_box_get_active (GTK_COMBO_BOX(comboService))==-1){
                gtk_widget_show (lookup_widget(objet,"EMTlabel51"));
b=0;
}
else{

           gtk_widget_hide (lookup_widget(objet,"EMTlabel51"));
	b=1;
}

if(gtk_combo_box_get_active (GTK_COMBO_BOX(comboObjet))==-1){
                gtk_widget_show (lookup_widget(objet,"EMTlabel61"));
b=0;
}
else{

           gtk_widget_hide(lookup_widget (objet,"EMTlabel61"));
b=1;
}
}
if(b==1){




//strcpy(r.id,gtk_entry_get_text(GTK_ENTRY(entryID)));

strcpy(r.detailsr,gtk_entry_get_text(GTK_ENTRY(entryDetails)));
if (strcmp(r.detailsr,"")==0)
{
strcpy(r.detailsr,"--");
}


strcpy(r.servicer,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboService)));

strcpy(r.objetr,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboObjet)));


strcpy(r.alerter,alerte);

strcpy(r.raisonr,raisonn);
if (strcmp(r.raisonr,"")==0)
{
strcpy(r.raisonr,"--");
}



// fonction GTK pour recuperer la date du calendrier 
gtk_calendar_get_date (GTK_CALENDAR(calendar),
                       &aa,
                       &mm,
                       &jj);
//convertion int => chaine

sprintf(r.dater,"%d/%d/%d",jj,mm+1,aa);

r.noter=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (spinnote));

ajouter_Nouv_reclamation(r);
gtk_widget_show (lookup_widget(objet,"EMTlabel100"));


///mise a jour treeView

afficher_reclamation(p);
        
 		
     }
}




//*RADIO BUTTON ******Fort****
void
on_EMTradiobutton81_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
/*
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
strcpy(alerte,"fort");*/
}

//*RADIO BUTTON ******Faible****
void
on_EMTradiobutton82_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

/*if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
strcpy(alerte,"faible");*/
}


// choix 1 de check button1  
void
on_EMTcheckbutton91_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
{strcpy(raisonn,"A");}
}


void
on_EMTcheckbutton92_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
{strcpy(raisonn,"B");}
}


void
on_EMTcheckbutton93_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
{strcpy(raisonn,"C");}
}


// bouton suivant de l'espace recla ==> service le plus reclamé

void
on_EMTbutton1_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *ol, *ne;

ol=lookup_widget(objet,"espace_reclamation");
gtk_widget_destroy(ol);

ne=create_serviceleplusrecla();
gtk_widget_show(ne);
}


// passage de window service recla à la page precedente d authentification

void
on_EMTbutton2_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *oo, *nn;

oo=lookup_widget(objet,"serviceleplusrecla");
gtk_widget_destroy(oo);

nn=create_EMTauthen();
gtk_widget_show(nn);

}








void
on_EMTradiobutton81m_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
//if(gtk_toggle_button_get_active (GTK_RADIO_BUTTON(togglebutton))){
strcpy(alertem,"fort");}



void
on_EMTradiobutton82m_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

//if(gtk_toggle_button_get_active (GTK_RADIO_BUTTON(togglebutton))){
strcpy(alertem,"faible");//}

}






//-------------------------------------BOUTTON Consulter --------------------
void
on_EMTbutton21m_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *entryID;

GtkWidget *entryDetails;

GtkWidget *comboService,*lbl;

GtkWidget *comboObjet,*s1,*s2,*s3;
char id[200],combos[200][200]={"Hebergement","Restauration"},comboo[200][200]={"Staff","Amenagement","Services","Autres"};
int b=1,l,x1,x2,jj,mm,aa,i=0,j=0;

reclamation r;

lbl=lookup_widget(objet,"EMTlabel112m");

entryID=lookup_widget(objet,"EMTentry11m");

gtk_widget_hide(lookup_widget(objet,"EMTlabel111m"));
strcpy(id,gtk_entry_get_text(GTK_ENTRY(entryID)));

if(consulter(&r,id)!=1)
{gtk_widget_show(lbl);}
else
{
	gtk_widget_hide(lbl);
	gtk_entry_set_text(GTK_ENTRY(entryID),id);
	entryDetails=lookup_widget(objet,"EMTentry7m");
	gtk_entry_set_text(GTK_ENTRY(entryDetails),r.detailsr);

	comboService=lookup_widget(objet,"EMTcombobox5m");

	comboObjet=lookup_widget(objet,"EMTcombobox6m");

	while ((i<2)&&(strcmp(combos[i],r.servicer)!=0))
	{i=i+1;}
	while ((j<4)&&(strcmp(comboo[j],r.objetr)!=0))
	{j=j+1;}
	gtk_combo_box_set_active(GTK_COMBO_BOX(comboService),i);
	gtk_combo_box_set_active(GTK_COMBO_BOX(comboObjet),j);


	
	int m,p;
	char dater[200],c1[200],c2[200],c3[200];
	
	strcpy(dater,r.dater);
	l=strlen(dater);
	for(i=0;i<l;i++)
	{
		if(dater[i]=='/')
		{
		    m=i;
		}

	}
	for(i=l;i>0;i--)
	{
		    if(dater[i]=='/')
		{
		    p=i;
		}

	}
	if(p==2)
		{sprintf(c1,"%c%c",dater[0],dater[1]);}
	else
		{sprintf(c1,"%c",dater[i]);}
	if(m-p-1==2)
		{sprintf(c2,"%c%c",dater[p+1],dater[p+2]);}
	else
		{sprintf(c2,"%c",dater[p+1]);}
	sprintf(c3,"%c%c%c%c",dater[m+1],dater[m+2],dater[m+3],dater[m+4]);

	int m1,m2,m3;
	m1=atoi(c1);
	m3=atoi(c3);
	m2=atoi(c2);

	s1=lookup_widget(objet,"EMTspinbutton101m");
	gtk_spin_button_set_value(s1,m1);
	s2=lookup_widget(objet,"EMTspinbutton102m");
	gtk_spin_button_set_value(s2,m2);
	s3=lookup_widget(objet,"EMTspinbutton103m");
	gtk_spin_button_set_value(s3,m3);


}
}



//-------------------------------------BOUTTON Modifier --------------------
void
on_EMTbutton20_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{

char id[200];
char servicer[200];
char objetr[200];
char detailsr[200];
char dater[200];
char alerter[200];

int b=0,x1,jj,mm,aa;
reclamation r; 

GtkWidget *entryID;
GtkWidget *entryDetails;

GtkWidget *radiobutt1;
GtkWidget *radiobutt2;

GtkWidget *combo1;
GtkWidget *combo2;


GtkWidget *p;
p=lookup_widget(objet,"EMTtreeview1");


entryID=lookup_widget(objet,"EMTentry11m");
entryDetails=lookup_widget(objet,"EMTentry7m");

/*
radiobutt1=lookup_widget(objet,"EMTradiobutton81m");
radiobutt2=lookup_widget(objet,"EMTradiobutton82m");*/


combo1=lookup_widget(objet,"EMTcombobox5m");
combo2=lookup_widget(objet,"EMTcombobox6m");



strcpy(id,gtk_entry_get_text(GTK_ENTRY(entryID)));





if((exist_reclamation(id)==0)){
	if(strcmp(id,"")==0){
		  gtk_widget_show(lookup_widget(objet,"EMTlabel111m"));
			gtk_widget_hide(lookup_widget(objet,"EMTlabel112m"));}
	else{
		  gtk_widget_show(lookup_widget(objet,"EMTlabel112m"));
		  gtk_widget_hide(lookup_widget(objet,"EMTlabel111m"));}
b=0;
}
else {
		  gtk_widget_hide(lookup_widget(objet,"EMTlabel112m"));
b=1;
}

if(b==1)
{
	strcpy(detailsr,gtk_entry_get_text(GTK_ENTRY(entryDetails)));
	if (strcmp(detailsr,"")==0)
	{strcpy(detailsr,"--");};

	strcpy(servicer,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combo1)));
	strcpy(objetr,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combo2)));



	jj =gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (lookup_widget(objet,"EMTspinbutton101m")));
	mm =gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (lookup_widget(objet,"EMTspinbutton102m")));
	aa =gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (lookup_widget(objet,"EMTspinbutton103m")));
	sprintf(dater,"%d/%d/%d",jj,mm,aa);





	//hide success label modifié avec succes
	gtk_widget_hide(lookup_widget(objet,"EMTlabel230"));

	modifier_reclamation(id,servicer,objetr,detailsr,dater,alertem);

	//show success label
	gtk_widget_show(lookup_widget(objet,"EMTlabel230"));

	//mise a jour treeView
	afficher_reclamation(p);
        
}
}









//-------------------------------------BOUTTON Supprimer --------------------
void
on_EMTbutton30_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{


        GtkWidget* p,*en;
        GtkWidget *label,*label2;
	
	char ch[200];
	en=lookup_widget(objet,"EMTentry500");
        label=lookup_widget(objet,"EMTlabels"); //label supprimé succes
	label2=lookup_widget(objet,"EMTlabels2");
	strcpy(ch,gtk_entry_get_text(GTK_ENTRY(en)));
	gtk_widget_hide (label);
	gtk_widget_hide (label2);
	//supprimer la ligne du treeView
	if(exist_reclamation(ch)==1)
	{
	supprimer_reclamation(ch);// supprimer la ligne du fichier
	gtk_widget_show (label);
	}
      	else
	{
      	gtk_widget_show (label2);
        }
}





void
on_EMTbuttoncherch_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{


GtkWidget *r1;
GtkWidget *entry;
GtkWidget *labelID;
GtkWidget *nbResultat;
GtkWidget *message,*espace;
char ide[200];
char chnb[200];
int b=0,nb;
entry=lookup_widget(objet,"EMTentry500"); //entry du id à chercher 
labelID=lookup_widget(objet,"EMTlabels2");


strcpy(ide,gtk_entry_get_text(GTK_ENTRY(entry)));

if(exist_reclamation(ide)!=1)
{
r1=lookup_widget(objet,"EMTtreeview1");
viderrecc(r1);
gtk_widget_show (labelID);
 }
else{
gtk_widget_hide (labelID);
r1=lookup_widget(objet,"EMTtreeview1");
viderrecc(r1);
Chercher_reclamation(r1,ide);
 }
}


void
on_EMTradiobutton1r_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_EMTradiobutton2r_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


//button Précedent de la page du service le plus reclamé ==> espace recla
void
on_EMTbutton2r_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{

GtkWidget *oo, *nn;

oo=lookup_widget(objet,"serviceleplusrecla");
gtk_widget_destroy(oo);

nn=create_espace_reclamation();
gtk_widget_show(nn);

}



void
on_EMTbutton1r_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{


}

//-------------------------------------BOUTTON rcherche du service le plus reclamé --------------------
void
on_EMTbutton3r_clicked                 (GtkWidget      *objet,
                                        gpointer         user_data)
{
GtkWidget* output1;
GtkWidget* output2;
GtkWidget* spinannee;


int anneerecla;
spinannee=lookup_widget(objet,"EMTspinbutton3r");
anneerecla=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (spinannee));

char servicerecla[200];
char aarr [200];
sprintf(aarr,"%d",anneerecla);

output1=lookup_widget(objet,"EMTlabel5000");

output2=lookup_widget(objet,"EMTlabel6000");

gtk_label_set_text(GTK_LABEL(output1),aarr);




int h;
h=chercher_service_reclam(aarr); //appel de la fonction
if(h==1)
strcpy(servicerecla,"Le service le plus réclamé est le Service : Restauration");
else if(h==0)
strcpy(servicerecla,"Le service le plus réclamé est le Service : Hebergement");

else
strcpy(servicerecla,"Aucune Réclamation n'est enregistrée à cette Année donnée");



gtk_label_set_text(GTK_LABEL(output2),servicerecla);

}


//-------------------------------------BOUTTON Actualiser--------------------

void
on_EMTbuttonAA_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *principale,*w1;
GtkWidget *EMTtreeview1;
EMTtreeview1=lookup_widget(objet,"EMTtreeview1");
afficher_reclamation(EMTtreeview1);
}


//row activated for suprimer
void
on_EMTtreeview1_row_activated          (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
reclamation r;
char ch[200];
GtkTreeIter iter;
gchar* id;
gchar* servicer;
gchar* objetr;
gchar* detailsr;
gchar* dater;
gchar* alerter;
gchar* raisonr;
gchar* noter;
GtkTreeModel *model = gtk_tree_view_get_model(treeview);
if (gtk_tree_model_get_iter(model,&iter,path))
{
gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&id,1,&servicer,2,&objetr,3,&detailsr,4,&dater,5,&alerter,6,&raisonr,7,&noter,-1);
strcpy(r.id,id);
supprimer_reclamation(r.id);

afficher_reclamation(treeview);
}
}






void
on_button2_auth_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *username, * password, *windowespace_reclamation, *msg;
char user[20];
char pasw[20];
char msge[200];
int trouve; 
username = lookup_widget (objet, "EMTentry3_log");
password = lookup_widget (objet,"EMTentry4_Pw");

strcpy(user,gtk_entry_get_text(GTK_ENTRY(username)));
strcpy(pasw,gtk_entry_get_text(GTK_ENTRY(password)));
trouve=verifrecc(user,pasw);

if (trouve==1)
{
windowespace_reclamation=create_espace_reclamation ();
gtk_widget_show (windowespace_reclamation);
}

else {
gtk_widget_show(lookup_widget (objet,"EMTlabel1msg"));
}

}


void
on_EMTbutton1_insc_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
FILE *f=NULL;
GtkWidget *login, *pw, *windowAuth;
char login1 [20];
char passw [20];
login=lookup_widget (objet, "EMTentry1_nom");
pw = lookup_widget (objet, "EMTentry2_Mot");
strcpy (login1, gtk_entry_get_text(GTK_ENTRY(login)));
strcpy(passw,gtk_entry_get_text (GTK_ENTRY (pw)));
//ouvrir le fichier 
f=fopen("utilisateur1.txt","a");
if (f!=NULL)
{
//ecrire dans le fichier 
fprintf(f,"%s %s \n",login1, passw);
fclose(f);

}
else
printf("\n not found");

windowAuth=create_EMTauthen ();
gtk_widget_show (windowAuth);

}



//passage de la page d authif à la page d inscri (precedent)
void
on_EMTbutton1PP_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *ol, *ne;

ol=lookup_widget(objet,"EMTauthen");
gtk_widget_destroy(ol);

ne=create_EMTinscription();
gtk_widget_show(ne);
}


void
on_EMTbutton1II_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *ol, *ne;

ol=lookup_widget(objet,"EMTinscription");
gtk_widget_destroy(ol);

ne=create_EMTauthen();
gtk_widget_show(ne);
}




