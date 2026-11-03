#include <stdio.h>
#include <stdlib.h>
#include "commande.h"

#include <string.h>

#include "types.h"

Commande creerCommande(Commande *commande, LigneCommande *ligneCommande, Client *client, Date *date, Adresse *adresse, Produit *produits, int *nb_lig_commandes, int *nb_lig_clients, int *nb_lig_produit) {
    /* Variables locales */
    int numCommande = *nb_lig_commandes;
    int i, nbCommade, choixClient, choixProduit, qteProduit;
    char r;
    /* Affichage des commandes */
    printf("Commandes actuelles :\n");
    for (i=0 ; i < *nb_lig_commandes; i++) {
        printf("%d. %d, %d, %d/%d/%d, %s, %s, %s, %d, %.2f, %.2f, %s, %s, %s, %s\n", i + 1, commande[i].numero, client[i].idClient, date[i].jour, date[i].mois, date[i].annee, commande[i].statut, ligneCommande[i].refProduit, ligneCommande[i].designation, ligneCommande[i].quantite, commande[i].montantTTC, commande[i].fraisPort, adresse[i].rue, adresse[i].ville, adresse[i].codePostal, adresse[i].pays);
    }
    /* Question : ajout de commande ou non ? */
    do {
        printf("Souhaitez-vous ajouter une commande ? (O/N)\n");
        scanf(" %c", &r);
    }while(r != 'O' && r != 'N');
    if (r == 'O') {
        /* Incrémentation des variables */
        nb_lig_commandes++;
        numCommande++;
        /* Affichage des clients */
        printf("Clients actuels :\n");
        for (i=0 ; i < *nb_lig_clients; i++) {
            printf("%d. %d, %s, %s, %s, %s, %s, %s, %s, %s, %d, %d, %d, %d\n", i, client[i].idClient, client[i].nom, client[i].prenom, client[i].email, client[i].telephone, adresse[i].rue, adresse[i].ville, adresse[i].codePostal, adresse[i].pays, client[i].pointsFidelite, client[i].nbCommande, client[i].capaciteCommandes, client[i].actif);
        }
        /* Choix du client concerné */
        do {
            printf("Entrez le numéro du client :\n");
            scanf(" %d", &choixClient);
        }while(choixClient < 0 || choixClient >= *nb_lig_clients);
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
                *ligneCommande[numCommande + j].refProduit = *produits[choixProduit].reference;
                *ligneCommande[numCommande + j].designation = *produits[choixProduit].designation;
                ligneCommande[numCommande + j].quantite = qteProduit;
                ligneCommande[numCommande + j].prixUnitaireHT = produits[choixProduit].prixUnitaireHT;
                ligneCommande[numCommande + j].sousTotalHT = qteProduit * ligneCommande[numCommande + j].prixUnitaireHT;
                commande[numCommande].montantBrut += ligneCommande[numCommande].sousTotalHT;
            }while((choixProduit < 0 || choixProduit >= *nb_lig_produit) && produits[choixProduit].quantiteStock <= 0);
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
        }while(commande[numCommande].fraisPort < 0 || commande[numCommande].fraisPort > 5.90);
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
    int choixCommande, choixAction, choixProduit, qteProduit;
    /* Affichage des commandes */
    printf("Commandes actuelles :\n");
    for (i=0 ; i < *nb_lig_commandes; i++) {
        printf("%d. %d, %d, %d/%d/%d, %s, %s, %s, %d, %.2f, %.2f, %s, %s, %s, %s\n", i + 1, commande[i].numero, client[i].idClient, date[i].jour, date[i].mois, date[i].annee, commande[i].statut, ligneCommande[i].refProduit, ligneCommande[i].designation, ligneCommande[i].quantite, commande[i].montantTTC, commande[i].fraisPort, adresse[i].rue, adresse[i].ville, adresse[i].codePostal, adresse[i].pays);
    }
    /* Saisie du numéro de la commande à modifier ou supprimer */
    do {
        printf("Entrez le numero de la commande que vous souhaitez modifier ou supprimer :\n");
        scanf(" %d", &choixCommande);
    }while(choixCommande < 0 || choixCommande >= *nb_lig_commandes);
    /* Choix de l'action */
    do {
        printf("Choisir une action :\n1. Ajouter une ligne de commande\n2. Supprimer une ligne de commande\n0. Revenir au menu commandes");
        scanf(" %d", &choixAction);
        switch (choixAction) {
            case 1: {
                printf("Produits actuels :\n");
                for (i=0 ; i < *nb_lig_produit; i++) {
                    printf("%d. %s, %s, %s, %f, %d, %d, %d\n", i, produits[i].reference, produits[i].designation, produits[i].categorie, produits[i].prixUnitaireHT, produits[i].quantiteStock, produits[i].seuilAlerte, produits[i].actif);
                }
                /* Saisie du / des produit(s) commandé(s) */
                do {
                    printf("Entrez le numéro du produit commandé et la quantité, séparés par une virgule :\n");
                    scanf(" %d, %d", &choixProduit, &qteProduit);
                    *ligneCommande[choixCommande].refProduit = *produits[choixProduit].reference;
                    *ligneCommande[choixCommande].designation = *produits[choixProduit].designation;
                    ligneCommande[choixCommande].quantite = qteProduit;
                    ligneCommande[choixCommande].prixUnitaireHT = produits[choixProduit].prixUnitaireHT;
                    ligneCommande[choixCommande].sousTotalHT = qteProduit * ligneCommande[choixCommande].prixUnitaireHT;
                    commande[choixCommande].montantBrut += ligneCommande[choixCommande].sousTotalHT;
                }while((choixProduit < 0 || choixProduit >= *nb_lig_produit) && produits[choixProduit].quantiteStock <= 0);
                /* Calculs du prix final */
                commande[choixCommande].montantRemise = commande[choixCommande].tauxRemise * commande[choixCommande].montantBrut;
                commande[choixCommande].montantHT = commande[choixCommande].montantBrut - commande[choixCommande].montantRemise;
                commande[choixCommande].montantTVA = 0.2 * commande[choixCommande].montantHT;
                commande[choixCommande].montantTTC = commande[choixCommande].montantHT + commande[choixCommande].montantTVA + commande[choixCommande].fraisPort;
                printf("Commandes mises à jour :\n");
                nb_lig_commandes ++;
                for (i=0; i < *nb_lig_commandes; i++) {
                    printf("%d. %d, %d, %d/%d/%d, %s, %s, %s, %d, %.2f, %.2f, %s, %s, %s, %s\n", i + 1, commande[i].numero, client[i].idClient, date[i].jour, date[i].mois, date[i].annee, commande[i].statut, ligneCommande[i].refProduit, ligneCommande[i].designation, ligneCommande[i].quantite, commande[i].montantTTC, commande[i].fraisPort, adresse[i].rue, adresse[i].ville, adresse[i].codePostal, adresse[i].pays);
                }
                break;
            }
            case 2: {
                free(&ligneCommande[choixCommande]);
                break;
            }
            case 0: {
                break;
            }
            default: {
                printf("  [!] Choix invalide.\n");
                break;
            }
        }
    }while(choixAction != 0 && commande[choixCommande].statut == "EN COURS");
}

// Commande afficherUneCommande(Commande *commande, LigneCommande *ligneCommande, Client *client, Date *date, Adresse *adresse, Produit *produits, int *nb_lig_commandes, int *nb_lig_clients, int *nb_lig_produit) {
//
// }


