#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "produit.h"
#include "types.h"

Produit ajouterProduit(Produit *produits) {
    produits = (Produit*) malloc(2*sizeof(Produit));
    int i = 0;
    do {
        printf("Saisir la reference commerciale du produit (SKU) :\n");
        fgets(produits[i].reference, strlen(produits[i].reference), stdin);
        i++;
    }
    while(produits[i].reference[0] == '\0');
    do {
        printf("Saisir le libele du produit :\n");
        fgets(produits[i].designation, strlen(produits[i].designation), stdin);
    }
    while(produits[i].designation[0] == '\0');
    do {
        printf("Saisir la categorie du produit :\n");
        fgets(produits[i].categorie, strlen(produits[i].categorie), stdin);
    }
    while(produits[i].categorie[0] == '\0');
    do {
        printf("Saisir le prix unitaire hors taxes du produit :\n");
        scanf(" %f", &produits[i].prixUnitaireHT);
    }
    while(produits[i].prixUnitaireHT <= 0);
    do {
        printf("Saisir le stock disponible du produit :\n");
        scanf(" %d", &produits[i].quantiteStock);
    }
    while(produits[i].quantiteStock < 0);
    do {
        printf("Saisir le seuil de réapprovisionnement du produit :\n");
        scanf(" %d", &produits[i].seuilAlerte);
    }
    while(produits[i].seuilAlerte < 0);
    do {
        printf("Le produit est-il actif (1 = oui, 0 = non) :\n");
        scanf(" %d", &produits[i].actif);
    }
    while(produits[i].actif != 0 && produits[i].actif != 1);
    return *produits;
}

/* Fonction modifierProduit */
Produit modifierProduit(Produit *produits) {
    /* Variables locales */
    int nb_lig = 8, nb_col = 7;
    int i,j;
    int nb_produit;

    /* Affichage du tableau */
    printf("Produits actuels :\n");
    for (i=0 ; i<nb_lig ; i++) {
        for(j=0 ; j<nb_col ; j++) {
             printf("%s\t",produits[i][j]);
        }
    }

    /* Sélection du produit */
    do {
        printf("Entrez la ligne du produit à modifier (de 0 à 7) : ");
        scanf("%d",nb_produit);
    } while((nb_produit < 0) && (nb_produit > 8));
    nb_produit = i;

    /* Modification du produit */
    do {
        printf("\nNouveau prix unitaire HT" );
        scanf("%.2f",&produits[i][4].prixUnitaireHT);
    } while (produits[i][4].prixUnitaireHT<1);
    do {
        printf("\nMise à jour du stock :" );
        scanf("%d", &produits[i][5].quantiteStock);
    } while (produits[i][5].quantiteStock<0);
    do {
        printf("\nModification du seuil d'alerte :" );
        scanf("%d",&produits[i][6].seuilAlerte);
    } while (produits[i][6].seuilAlerte<0);

    /* Réaffichage du tableau mis à jour */
    printf("\nListe des produits mise à jour :\n");
    for (i=0 ; i<nb_lig ; i++) {
        for(j=0 ; j<nb_col ; j++) {
             printf("%s\t",produits[i][j]);
        }
    }
    return *produits;
}
