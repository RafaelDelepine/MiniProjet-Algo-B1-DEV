#include <stdio.h>
#include <stdlib.h>
#include "commande.h"

#include <string.h>

#include "types.h"

Commande creerCommande(Commande *commande, LigneCommande *ligneCommande, Client *client, Date *date, Adresse *adresse, Produit *produits, int *nb_lig_commandes, int *nb_lig_clients, int *nb_lig_produit) {
    /* Variables locales */
    int i, nbCommade, numCommande, choixClient, choixProduit, qteProduit;
    char r;
    /* Affichage des commandes */
    printf("Commandes actuelles :\n");
    for (i=0 ; i < *nb_lig_commandes; i++) {
        printf("%d. %d, %d, %d/%d/%d, %s, %.2f, %.2f, %s, %s, %s, %s\n", i + 1, commande[i].numero, client[i].idClient, date[i].jour, date[i].mois, date[i].annee, commande[i].statut, commande[i].montantTTC, commande[i].fraisPort, adresse[i].rue, adresse[i].ville, adresse[i].codePostal, adresse[i].pays);
    }
    /* Question : ajout de commande ou non ? */
    do {
        printf("Souhaitez-vous ajouter une commande ? (O/N)\n");
        scanf(" %c", &r);
    }while(r != 'O' && r != 'N');
    if (r == 'O') {
        /* Incrémentation des variables */
        (*nb_lig_commandes)++;
        numCommande = *nb_lig_commandes;
        /* Affichage des clients */
        printf("Clients actuels :\n");
        for (i=0 ; i < *nb_lig_clients; i++) {
            printf("%d. %d, %s, %s, %s, %s, %s, %s, %s, %s, %d, %d, %d, %d\n", i, client[i].idClient, client[i].nom, client[i].prenom, client[i].email, client[i].telephone, adresse[i].rue, adresse[i].ville, adresse[i].codePostal, adresse[i].pays, client[i].pointsFidelite, client[i].nbCommande, client[i].capaciteCommandes, client[i].actif);
        }
        /* Choix du client concerné */
        do {
            printf("Entrez le numéro du client :\n");
            scanf(" %d", &choixClient);
        }while(choixClient < 0 && choixClient >= *nb_lig_clients);
        /* Saisie de la date de commande */
        printf("Saisir la date de commande (J/M/A) :\n");
        scanf(" %d/%d/%d", &date[numCommande].jour, &date[numCommande].mois, &date[numCommande].annee);
        /* Ajout de la commande */
        /* Saisie du nombre de produits commandés */
        do {
            printf("Entrez le nombre de produits commandés :\n");
            scanf(" %d", &nbCommade);
        }while(nbCommade < 1);
        /* Affichage de l'inventaire */
        printf("Produits actuels :\n");
        for (i=0 ; i < *nb_lig_produit; i++) {
            printf("%d. %s, %s, %s, %f, %d, %d, %d\n", i, produits[i].reference, produits[i].designation, produits[i].categorie, produits[i].prixUnitaireHT, produits[i].quantiteStock, produits[i].seuilAlerte, produits[i].actif);
        }
        /* Saisie du / des produit(s) commandé(s) */
        commande[numCommande].montantBrut = 0;
        for (int j = 0; j < nbCommade; j++) {
            do {
                printf("Entrez le numéro du produit commandé et la quantité, séparés par une virgule :\n");
                scanf(" %d, %d", &choixProduit, &qteProduit);
                commande[numCommande].nbLignes ++;
                strcpy(ligneCommande[j].refProduit, produits[choixProduit].reference);
                strcpy(ligneCommande[j].designation, produits[choixProduit].designation);
                ligneCommande[j].quantite = qteProduit;
                ligneCommande[j].prixUnitaireHT = produits[choixProduit].prixUnitaireHT;
                ligneCommande[j].sousTotalHT = ligneCommande[j].quantite * ligneCommande[j].prixUnitaireHT;
                commande[j].montantBrut += ligneCommande[j].sousTotalHT;
            }while((choixProduit < 0 && choixProduit >= *nb_lig_produit) && produits[choixProduit].quantiteStock <= 0);
        }
        /* Saisie du taux de réduction */
        do {
            printf("Entrez un taux de réduction (ou 0 si le client n'en dispose pas) :\n");
            scanf(" %d", &commande[numCommande].tauxRemise);
        }while(commande[numCommande].tauxRemise < 0);
        /* Saisie des frais de port */
        do {
            printf("Saisir les frais de port (entre 0 et 5.90 euros) :\n");
            scanf(" %f", &commande[numCommande].fraisPort);
        }while(commande[numCommande].fraisPort < 0 && commande[numCommande].fraisPort > 5.90);
        /* Calcul du montant toutes taxes comprises et aujout du statut*/
        commande[numCommande].montantRemise = commande[numCommande].tauxRemise * commande[numCommande].montantBrut;
        commande[numCommande].montantHT = commande[numCommande].montantBrut - commande[numCommande].montantRemise;
        commande[numCommande].montantTVA = 0.2 * commande[numCommande].montantHT;
        commande[numCommande].montantTTC = commande[numCommande].montantHT + commande[numCommande].montantTVA + commande[numCommande].fraisPort;
        *commande[numCommande].statut = "EN COURS";
        /* Affichage du tableau mis à jour */
        printf("Commandes mises à jour :\n");
        for (i=0; i < numCommande; i++) {
            printf("%d. %d, %d, %d/%d/%d, %s, %s, %s, %d, %.2f, %.2f, %s, %s, %s, %s\n", i + 1, commande[i].numero, client[i].idClient, date[i].jour, date[i].mois, date[i].annee, commande[i].statut, ligneCommande[i].refProduit, ligneCommande[i].designation, ligneCommande[i].quantite, commande[i].montantTTC, commande[i].fraisPort, adresse[i].rue, adresse[i].ville, adresse[i].codePostal, adresse[i].pays);
        }
    }
    return *commande;
}

Commande modifierSupprimerCommande(Commande *commande, LigneCommande *ligneCommande, Client *client, Date *date, Adresse *adresse, Produit *produits, int *nb_lig_commandes, int *nb_lig_produit) {
    /* Variables locales */
    int i;
    int choixAction, choixCommande, choixProduit, qteProduit;
    /* Affichage des commandes */
    printf("Commandes actuelles :\n");
    for (i=0 ; i < *nb_lig_commandes; i++) {
        printf("%d. %d, %d, %d/%d/%d, %s, %.2f, %.2f, %s, %s, %s, %s\n", i + 1, commande[i].numero, client[i].idClient, date[i].jour, date[i].mois, date[i].annee, commande[i].statut, commande[i].montantTTC, commande[i].fraisPort, adresse[i].rue, adresse[i].ville, adresse[i].codePostal, adresse[i].pays);
    }
    /* Saisie du numéro de la commande à modifier ou supprimer */
    do {
        printf("Entrez le numero de la commande que vous souhaitez modifier ou supprimer :\n");
        scanf(" %d", &choixCommande);
    }while(choixCommande < 1 && choixCommande >= *nb_lig_commandes);
    choixCommande --;
    /* Choix de l'action */
    do {
        printf("Choisir une action :\n1. Ajouter une ligne de commande\n2. Supprimer une ligne de commande\n0. Revenir au menu commandes");
        scanf(" %d", &choixAction);
        switch (choixAction) {
            case 1: {
                /* Incrémentation */
                printf("Produits actuels :\n");
                for (i=0 ; i < *nb_lig_produit; i++) {
                    printf("%d. %s, %s, %s, %f, %d, %d, %d\n", i, produits[i].reference, produits[i].designation, produits[i].categorie, produits[i].prixUnitaireHT, produits[i].quantiteStock, produits[i].seuilAlerte, produits[i].actif);
                }
                /* Saisie du / des produit(s) commandé(s) */
                do {
                    printf("Entrez le numéro du produit commandé et la quantité, séparés par une virgule :\n");
                    scanf(" %d, %d", &choixProduit, &qteProduit);
                    commande[choixCommande].nbLignes ++;
                    strcpy(ligneCommande[commande[choixCommande].numero].refProduit, produits[choixProduit].reference);
                    strcpy(ligneCommande[commande[choixCommande].numero].designation, produits[choixProduit].designation);
                    ligneCommande[commande[choixCommande].numero].quantite = qteProduit;
                    ligneCommande[commande[choixCommande].numero].prixUnitaireHT = produits[choixProduit].prixUnitaireHT;
                    ligneCommande[commande[choixCommande].numero].sousTotalHT = qteProduit * ligneCommande[commande[choixCommande].numero].prixUnitaireHT;
                    commande[commande[choixCommande].numero].montantBrut += ligneCommande[commande[choixCommande].numero].sousTotalHT;
                }while(choixProduit < 0 && choixProduit >= *nb_lig_produit && produits[choixProduit].quantiteStock <= 0);
                /* Calculs du prix final */
                commande[commande[choixCommande].numero].montantRemise = commande[commande[choixCommande].numero].tauxRemise * commande[commande[choixCommande].numero].montantBrut;
                commande[commande[choixCommande].numero].montantHT = commande[commande[choixCommande].numero].montantBrut - commande[commande[choixCommande].numero].montantRemise;
                commande[commande[choixCommande].numero].montantTVA = 0.2 * commande[commande[choixCommande].numero].montantHT;
                commande[commande[choixCommande].numero].montantTTC = commande[commande[choixCommande].numero].montantHT + commande[commande[choixCommande].numero].montantTVA + commande[commande[choixCommande].numero].fraisPort;
                printf("Commandes mises à jour :\n");
                /* Affichage des commandes après modification */
                for (i=0; i < *nb_lig_commandes; i++) {
                    printf("%d. %d, %d, %d/%d/%d, %s, %s, %s, %d, %.2f, %.2f, %s, %s, %s, %s\n", i + 1, commande[i].numero, client[i].idClient, date[i].jour, date[i].mois, date[i].annee, commande[i].statut, ligneCommande[i].refProduit, ligneCommande[i].designation, ligneCommande[i].quantite, commande[i].montantTTC, commande[i].fraisPort, adresse[i].rue, adresse[i].ville, adresse[i].codePostal, adresse[i].pays);
                }
                break;
            }
            case 2: {

                printf("Produits :\n");
                for(i=0; i<commande[choixCommande].nbLignes; i++) {
                    printf("%d. %s, %s, %d, %.2f", i + 1, ligneCommande[i].refProduit, ligneCommande[i].designation, ligneCommande[i].quantite, ligneCommande[i].sousTotalHT);
                }
                do {
                    printf("Choisissez la ligne à supprimer :\n");
                    scanf("%d", &choixProduit);
                } while(choixProduit < 1 && choixProduit > i);
                /* Supression d'une ligne de commande */
                free(&ligneCommande[choixProduit]);
                break;
            }
            case 0: {
                break;
            }
            default: {
                /* Sortie par défaut en cas de choix invalide */
                printf("  [!] Choix invalide.\n");
                break;
            }
        }
        /* Permet de réafficher le menu taut que l'utilisateur n'a pas décider de quitter */
    }while(choixAction != 0 && strcmp(commande[choixCommande].statut, "EN COURS") == 0);
    return *commande;
}

Commande changerStatut(Commande *commande, Client *client, Date *date, Adresse *adresse, int *nb_lig_commandes) {
    int i, choixCommande, choixStatut;
    /* Affichage des commandes */
    printf("Commandes actuelles :\n");
    for (i=0 ; i < *nb_lig_commandes; i++) {
        printf("%d. %d, %d, %d/%d/%d, %s, %.2f, %.2f, %s, %s, %s, %s\n", i + 1, commande[i].numero, client[i].idClient, date[i].jour, date[i].mois, date[i].annee, commande[i].statut, commande[i].montantTTC, commande[i].fraisPort, adresse[i].rue, adresse[i].ville, adresse[i].codePostal, adresse[i].pays);
    }
    do {
        printf("Saisissez la commande dont vous souhaitez changer le statut :\n");
        scanf("%d", &choixCommande);
    } while (choixCommande < 1 && choixCommande > *nb_lig_commandes);
    choixCommande --;
    do {
        printf("Choisissez le nouveau statut de la commande :\n1. EN COURS\n2. EXPEDIEE\n3. LIVREE\n");
        scanf(" %d", &choixStatut);
    } while(choixStatut < 1 && choixStatut > 3);
    switch (choixStatut) {
        case 1: {
           strcpy(commande[choixCommande].statut, "EN COURS");
            break;
        }
        case 2: {
            strcpy(commande[choixCommande].statut,"EXPEDIEE");
            break;
        }
        case 3: {
            strcpy(commande[choixCommande].statut,"LIVREE");
            break;
        }
    }
    return commande[choixCommande];
}

Commande annulerCommande(Commande *commande, Client *client, Date *date, Adresse *adresse, int *nb_lig_commandes) {
    int i, choixCommande;
    /* Affichage des commandes */
    printf("Commandes actuelles :\n");
    for (i=0 ; i < *nb_lig_commandes; i++) {
        printf("%d. %d, %d, %d/%d/%d, %s, %.2f, %.2f, %s, %s, %s, %s\n", i + 1, commande[i].numero, client[i].idClient, date[i].jour, date[i].mois, date[i].annee, commande[i].statut, commande[i].montantTTC, commande[i].fraisPort, adresse[i].rue, adresse[i].ville, adresse[i].codePostal, adresse[i].pays);
    }
    do {
        printf("Saisissez une commande à annuler :\n");
        scanf("%d", &choixCommande);
    } while (choixCommande < 1 && choixCommande > *nb_lig_commandes);
choixCommande --;
    strcpy(commande[choixCommande].statut, "ANNULEE");
    return commande[choixCommande];
}

void afficherUneCommande(Commande *commande, LigneCommande *ligneCommande, Client *client, Date *date, Adresse *adresse, int *nb_lig_commandes) {
    int i, j = 0, choixCommande;
    printf("Commandes actuelles :\n");
    for (i=0 ; i < *nb_lig_commandes; i++) {
        printf("%d. %d, %d/%d/%d, %s, %.2f, %.2f, %s, %s, %s, %s\n", commande[i].numero, client[i].idClient, date[i].jour, date[i].mois, date[i].annee, commande[i].statut, commande[i].montantTTC, commande[i].fraisPort, adresse[i].rue, adresse[i].ville, adresse[i].codePostal, adresse[i].pays);
    }
    do {
        printf("Saisissez le numéro de la commande que vous souhaitez afficher :\n");
        scanf("%d", &choixCommande);
    }while (choixCommande < 1 && choixCommande > *nb_lig_commandes);
    i = 0;
    while(i < choixCommande) {
        i++;
    }
    printf("Commande n°%d:\n", choixCommande);
    choixCommande --;
    printf("Identifiant du client : %d\n", client[choixCommande].idClient);
    printf("Date de commande : %d/%d/%d\n", date[choixCommande].jour, date[choixCommande].mois, date[choixCommande].annee);
    printf("Adressee de livraison : %s, %s, %s, %s\n", adresse[choixCommande].rue, adresse[choixCommande].ville, adresse[choixCommande].codePostal, adresse[choixCommande].pays);
    printf("Montant HT : %.2f\n", commande[choixCommande].montantHT);
    printf("Remise appliquée : %.2f\n", commande[choixCommande].montantRemise);
    printf("montant TVA sur la commande : %.2f\n", commande[choixCommande].montantTVA);
    printf("Frais de port : %.2f\n", commande[choixCommande].fraisPort);
    printf("Montant TTC : %.2f\n", commande[choixCommande].montantTTC);
    printf("Statut de la commande : %s\n", commande[choixCommande].statut);
    for (j = 0; j < commande[choixCommande].nbLignes; j++) {
        printf("Produit %d:\n", j+1);
        printf("Référence du produit : %s\n", ligneCommande[j].refProduit);
        printf("Designation du produit : %s\n", ligneCommande[j].designation);
        printf("Quantité : %d\n", ligneCommande[j].quantite);
        printf("Prix unitaire HT : %.2f\n", ligneCommande[j].prixUnitaireHT);
        printf("Sous-total HT : %.2f\n", ligneCommande[j].sousTotalHT);
    }
}