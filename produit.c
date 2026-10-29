#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonctions.h"

Produit ajouterProduit(Produit *produits) {
    produits = (Produit*) malloc(2*sizeof(Produit));
    int i = 0;
    do {
        printf("Saisir la reference commerciale du produit (SKU) :\n");
        scanf("%s", produits[i].reference);
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
        scanf(" %s", produits[i].categorie);
    }
    while(produits[i].categorie[0]=='\0');
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
