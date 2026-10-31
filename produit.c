#include <stdio.h>
#include <stdlib.h>
#include "produit.h"
#include <string.h>
#include "types.h"

/* Fonction ajouterProduit */
Produit ajouterProduit(Produit *produits) {
    /* Variables locales */
    int nbProduit = 0;
    int i = nbProduit;

    /* Affichage du tableau */
    printf("Produits actuels :\n");
    for (i=0 ; i<nb_lig ; i++) {
        printf("%s, %s, %s, %f, %d, %d, %d\n", produits[i].reference, produits[i].designation, produits[i].categorie, produits[i].prixUnitaireHT, produits[i].quantiteStock, produits[i].seuilAlerte, produits[i].actif);
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

/* Fonction modifierProduit */
Produit modifierProduit(Produit * produits) {
    /* Variables locales */
    int nb_lig = 8;
    int i;
    int nb_produit;
    
    /* Affichage du tableau */
    printf("Produits actuels :\n");
    for (i=0 ; i<nb_lig ; i++) {
        printf("%s, %s, %s, %f, %d, %d, %d\n", produits[i].reference, produits[i].designation, produits[i].categorie, produits[i].prixUnitaireHT, produits[i].quantiteStock, produits[i].seuilAlerte, produits[i].actif);
    }

    /* Sélection du produit */
    do {
        printf("Entrez la ligne du produit à modifier (de 0 à 7) : ");
        scanf("%d",nb_produit);
    } while((nb_produit < 0) && (nb_produit > 8));
    nb_produit = i;

    /* Modification du produit */
    /* Nouveaux prix HT */
    do {
        printf("\nNouveau prix unitaire HT" );
        scanf("%.2f",&produits[i].prixUnitaireHT);
    } while (produits[i].prixUnitaireHT < 1);
    /* Mise a jour stock */
    do {
        printf("\nMise à jour du stock :" );
        scanf("%d", &produits[i].quantiteStock);
    } while (produits[i].quantiteStock < 0);
    /* Modification seuil alerte */
    do {
        printf("\nModification du seuil d'alerte :" );
        scanf("%d",&produits[i].seuilAlerte);
    } while (produits[i].seuilAlerte < 0);

    /* Réaffichage du tableau mis à jour */
    printf("\nListe des produits mise à jour :\n");
    for (i=0 ; i<nb_lig ; i++) {
        printf("%s, %s, %s, %f, %d, %d, %d", produits[i].reference, produits[i].designation, produits[i].categorie, produits[i].prixUnitaireHT, produits[i].quantiteStock, produits[i].seuilAlerte, produits[i].actif);
    }
    return *produits;
}

/* Fonction supprimerProduit */
Produit supprimerProduit(Produit *produits) {
    /* Variables locales */
    int nb_lig = 8;
    int i;
    int nbProduit = 0;

    /* Affichage du tableau */
    printf("Produits actuels :\n");
    for (i=0 ; i<nb_lig ; i++) {
        printf("%s, %s, %s, %f, %d, %d, %d", produits[i].reference, produits[i].designation, produits[i].categorie, produits[i].prixUnitaireHT, produits[i].quantiteStock, produits[i].seuilAlerte, produits[i].actif);
    }

    /* Sélection du produit à supprimer */
    do {
        printf("Entrez la ligne du produit à supprimer (de 0 à 7) : ");
        scanf("%d",nbProduit);
    } while((nbProduit < 0) && (nbProduit > 8));
    printf("Produits actuels :\n");
    nbProduit = i;
}
