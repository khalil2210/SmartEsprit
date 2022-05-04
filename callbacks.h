#include <gtk/gtk.h>

void
on_button_register_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_login_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_ajouter_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_ajouter1_clicked             (GtkButton       *objet_graphique,
                                        gpointer         user_data);

void
on_button_modifier_clicked             (GtkButton       *objet,
                                        gpointer         user_data);

void
on_button_afficher_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_supprimer_clicked            (GtkButton       *objet,
                                        gpointer         user_data);

void
on_button_supprimer1_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_homme_toggled                       (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_femme_toggled                       (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_homme1_toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_femme1_toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_retour_modifier_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_retour_ajout_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_retour_afficher_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_supprimer1_clicked           (GtkButton       *button,
                                        gpointer         user_data);


void
on_rechercher_clicked                  (GtkButton       *button,
                                        gpointer         user_data);


void
on_rechercher_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_supprimer1_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_homme2_toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_femme2_toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button_modifier1_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_clog_clicked                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_csign_clicked                       (GtkButton       *button,
                                        gpointer         user_data);

void
on_retour_supprimer_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_refresh_list_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_alarmes_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_calendars_day_selected              (GtkCalendar     *calendar,
                                        gpointer         user_data);

void
on_treeview_alarmes_row_activated      (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_retour_dash_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_SAbutton_modifier1_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_SAhomme2_toggled                    (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_SAfemme2_toggled                    (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_SAretour_modifier_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_SArechercher_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_SAretour_afficher_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_SArefresh_list_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_SAbutton_ajouter_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_SAbutton_afficher_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_SAbutton_modifier_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_SAbutton_supprimer_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_SAalarmes_clicked                   (GtkButton       *button,
                                        gpointer         user_data);

void
on_SAhomme1_toggled                    (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_SAretour_ajout_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_SAbutton_ajouter1_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_SAfemme1_toggled                    (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_SAhomme_toggled                     (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_SAfemme_toggled                     (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_SAbutton_register_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_SAbutton_login_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_SAretour_supprimer_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_SAbutton_supprimer1_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_SAchanger_clicked                   (GtkButton       *button,
                                        gpointer         user_data);

void
on_ETUDIANT_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_RESTO_clicked                       (GtkButton       *button,
                                        gpointer         user_data);

void
on_FOYER_clicked                       (GtkButton       *button,
                                        gpointer         user_data);

void
on_TECHNICIEN_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_ADMIN_clicked                       (GtkButton       *button,
                                        gpointer         user_data);

void
on_SAauth_clicked                      (GtkButton       *button,
                                        gpointer         user_data);

void
on_SAdec_clicked                       (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_agent_foyer_loula_connexion_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_agentfoyer_loula_inscription_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_inscription_bouton_ajouter_clicked  (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_dejainscrit_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_authentificaionbouton_clicked       (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_retour_inscription_clicked   (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_recherche_etudiant_clicked   (GtkButton       *button,
                                        gpointer         user_data);

void
on_treeview_etudiant_row_activated     (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_button_recherche_etudiant_clicked   (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_interface_ajout_etudiant_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_actualiser_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_radiobuttonhomme_clicked            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonfemme_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonindiv_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttona2_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button_ajout_etudiant_clicked       (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_accueil_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_authentificaion_bouton_clicked      (GtkButton       *button,
                                        gpointer         user_data);

void
on_radiobuttonhomme_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button_supprimer_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_combobox2_changed                   (GtkComboBox     *combobox,
                                        gpointer         user_data);

void
on_button_supprimer_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_modication_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_ahmed_loula_connexion_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_ahmed_loula_inscription_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_button1_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_button3_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_button2_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_button4_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_button5_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_button6_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_button8_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_button7_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_button10_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_button9_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_checkbutton4_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton3_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_treeview1_at_row_activated          (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_radiobutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button11_at_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_button12_at_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

////////////////////////////////////////////////////////////////////////
////////////////////***capteur***///////////////////////////////////////

void
on_button12_affich_pg_capt_ajout_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button11_ajouter_capteur_pg_clicked (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_treeview1_couli_row_activated       (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_button14_ajout_pg_affich_clicked    (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button15_modif_capt_pg_affich_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button17_cap_defectueux_clicked     (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button11_actu_pg_affich_clicked     (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button12_acceuil_pg_cap_clicked     (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button16_supp_pg_affich_clicked     (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button11_supp_capteur_pg_clicked   (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button12_retour_pg_supcap_clicked   (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button12_actu_pg_capdef_clicked     (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button11_retour_pg_def_clicked      (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button13_rech_capteur_clicked       (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_treeview1_coulib_row_activated      (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_button11_enregister_mod_pg_clicked  (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button12_retour_pg_modif_clicked    (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_radiobutton3_couli_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton6_baly_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton5_baly_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data);
//-----------------------PARTIE EMNA----------------------
void
on_EMTbutton1II_clicked                (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_EMTbutton1_insc_clicked             (GtkWidget       *objet,
                                        gpointer         user_data);


void
on_EMTbutton10_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_EMTbutton21m_clicked                (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_EMTbutton20_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_EMTtreeview1_row_activated          (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_EMTbuttonAA_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_EMTbuttoncherch_clicked             (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_EMTbutton30_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_EMTbutton1_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_EMTbutton2_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_EMTradiobutton81_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_EMTradiobutton82_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_EMTcheckbutton91_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_EMTcheckbutton92_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_EMTcheckbutton93_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_EMTradiobutton81m_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_EMTradiobutton82m_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_EMTbutton3r_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_EMTbutton2r_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button2_auth_clicked                (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_EMTbutton1PP_clicked                (GtkWidget       *objet,
                                        gpointer         user_data);
