#include <stdio.h>
#include <stdlib.h>
#include "commande.h"

#include <string.h>

#include "types.h"

Commande creerCommande(Commande *commande, LigneCommande *ligneCommande, Client *client, Date *date, Adresse *adresse, Produit *produits) {
/* Variables locales */
    int numCommande = 0;
    int i = numCommande, nb_lig_commandes = 6, nb_lig_clients = 5, nb_lig_produit = 8;

    /* Affichage des commandes */
    printf("Commandes actuelles :\n");
    for (i=0 ; i<nb_lig_commandes; i++) {
        printf("%d. %d, %d, %d/%d/%d, %s, %s, %s, %d, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %s, %s, %s, %s\n", i, commande[i].numero, client[i].idClient, date[i].jour, date[i].mois, date[i].annee, commande[i].statut, ligneCommande[i].refProduit, ligneCommande[i].designation, ligneCommande[i].quantite, commande[i].montantBrut, commande[i].montantHT, commande[i].montantRemise, commande[i].montantTVA, commande[i].montantTTC, commande[i].fraisPort, adresse[i].rue, adresse[i].ville, adresse[i].codePostal, adresse[i].pays);
    }
    char r;
    do {
        printf("Souhaitez-vous ajouter une commande ? (O/N)\n");
        scanf("%c", &r);
    }while(r != 'O' || r != 'N');
    if (r == 'O') {
        /* Affichage des clients */
        printf("Clients actuels :\n");
        for (i=0 ; i<nb_lig_clients; i++) {
            printf("%d. %d, %s, %s, %s, %s, %s, %s, %s, %s, %d, %d, %d, %d\n", i, client[i].idClient, client[i].nom, client[i].prenom, client[i].email, client[i].telephone, adresse[i].rue, adresse[i].ville, adresse[i].codePostal, adresse[i].pays, client[i].pointsFidelite, client[i].nbCommande, client[i].capaciteCommandes, client[i].actif);
        }
        /* Choix du client concerné */
        int choixClient;
        do {
            printf("Entrez le numéro du client :\n");
            scanf("%d", choixClient);
        }while(choixClient < 0 || choixClient > nb_lig_clients);
        /* Ajout de la commande */
        /* Saisie du nombre de produits commandés */
        nb_lig_commandes++;
        int nbCommade;
        do {
            printf("Entrez le nombre de produits commandés :\n");
            scanf("%d", nbCommade);
        }while(nbCommade < 1);
        /* Affichage de l'inventaire */
        printf("Produits actuels :\n");
        for (i=0 ; i<nb_lig_produit; i++) {
            printf("%d. %s, %s, %s, %f, %d, %d, %d\n", i, produits[i].reference, produits[i].designation, produits[i].categorie, produits[i].prixUnitaireHT, produits[i].quantiteStock, produits[i].seuilAlerte, produits[i].actif);
        }
        /* Saisie du produit commandé */
        int choixProduit;
        do {
            printf("Entrez le numéro du produit commandé :\n");
            scanf("%d", choixProduit);
        }while((choixProduit < 0 || choixProduit > nb_lig_produit) && produits[i].quantiteStock != 0);
    }

    return *commande;
}

// Commande afficherUneCommande(Commande *commande) {
//
// }

