#include <stdio.h>
#include <stdlib.h>
#include "commande.h"

#include <string.h>

#include "types.h"

Commande creerCommande(Commande *commande, LigneCommande *ligneCommande, Client *client, Date *date) {
/* Variables locales */
    int numCommande = 0;
    int i = numCommande, nb_lig = 6;

    /* Affichage du tableau */
    printf("Commande actuelles :\n");
    for (i=0 ; i<nb_lig; i++) {
        printf("%d. %d, %d, %d/%d/%d, %s, %s, %s, %d\n", i, commande[i].numero, client[i].idClient, date[i].jour, date[i].mois, date[i].annee, commande[i].statut, ligneCommande[i].refProduit, ligneCommande[i].designation, ligneCommande[i].quantite, commande[i].montantBrut, commande[i].tauxRemise, commande[i].montantRemise, commande[i].montantHT, commande[i].);
    }

    /* Ajout du produit */
    /* Reference commerciale */
    do {
        printf("Saisir la reference commerciale du produit (SKU) :\n");
        scanf("%s", produits[i].reference);
    }while(produits[i].reference[0]=='\0');
    /* Libele du produit */
    do {
        printf("Saisir le libele du produit :\n");
        fgets(produits[i].designation, strlen(produits[i].designation), stdin);
    }while(produits[i].designation[0]=='\0');
    /* Categorie du produit */
    do {
        printf("Saisir la categorie du produit :\n");
        scanf("%s", produits[i].categorie);
    }while(produits[i].categorie[0]=='\0');
    /* Prix unitaire HT */
    do {
        printf("Saisir le prix unitaire hors taxes du produit :\n");
        scanf("%f", &produits[i].prixUnitaireHT);
    }while(produits[i].prixUnitaireHT <= 0);
    /* Stock restant */
    do {
        printf("Saisir le stock disponible du produit :\n");
        scanf("%d", &produits[i].quantiteStock);
    }while(produits[i].quantiteStock < 0);
    /* Seuil alerte */
    do {
        printf("Saisir le seuil de réapprovisionnement du produit :\n");
        scanf("%d", &produits[i].seuilAlerte);
    }while(produits[i].seuilAlerte < 0);
    /* Actif ou non */
    do {
        printf("Le produit est-il actif (1 = oui, 0 = non) ?\n");
        scanf("%d", &produits[i].actif);
    }while(produits[i].actif != 0 && produits[i].actif != 1);

    /* Réaffichage du tableau mis à jour */
    printf("\nListe des produits mise à jour :\n");
    for (i=0 ; i<nb_lig ; i++) {
        printf("%s, %s, %s, %f, %d, %d, %d", produits[i].reference, produits[i].designation, produits[i].categorie, produits[i].prixUnitaireHT, produits[i].quantiteStock, produits[i].seuilAlerte, produits[i].actif);
    }
    return *produits;
}

Commande afficherUneCommande(Commande *commande) {

}

