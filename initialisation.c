
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "initialisation.h"
#include "types.h"
#include "utils.c"

#define MAX_LIG 100

void initialiserDonnees(Boutique *boutique, Client *client) {
    /* Catalogue produits */
    boutique->capaciteProduits = 8;
    if (boutique-> produits == NULL) {
        printf("Erreur : Catalogue vide\nVeuillez ajouter des produits dans le catalogue \n");
    }

    boutique->nbProduits = 0;
    Produit listeProduits[] = {
        {"INF-0001", "Barrette de RAM", "Informatique", 90.90, 12, 8, 1},
        {"INF-0002", "Ecran OLED", "Informatique", 220.90, 7, 4, 1},
        {"INF-0003", "Ordinateur portable", "Informatique", 590.90, 12, 8, 1},
        {"ACC-0001", "Adaptateur USB-C vers Jack", "Accesssoire", 15.00, 85, 25, 1},
        {"ACC-0002", "Clé USB 32 Go", "Accessoire", 10.90, 18, 10, 1},
        {"ACC-0003","Tablette graphique", "Accessoire", 300.90, 6, 5, 1},
        {"AUD-0001", "Enceinte bluetooth", "Audio", 79.90, 9, 5, 1},
        {"AUD-0002", "Écouteurs sans fil", "Audio", 60.90, 15, 10, 1}
    };

    for (int i = 0; i<8; i++) {
       boutique->produits[boutique->nbProduits++] = listeProduits[i];
    }

    /* Clients */
    boutique->capaciteClients = 5;
    boutique->clients = (Client *)malloc(boutique->capaciteClients * sizeof(Client));
    if (boutique->clients == NULL) {
        printf("Erreur : Liste des clients vide\nVeuillez renseigner les inforamtions des clients dans la liste\n");
    }
    boutique->nbClients = 0;
    Client listeClients[] = {
        {1, "Pupon", "Paul", "paul.pupon.3689@gamil.fr",  "0625447154", client->adresseLivraison, 0, 0, 0, NULL,1},
        {2, "Doufri", "Sylvie", "s.doufri@gamil.fr",  "0714222690", client->adresseLivraison, 0, 0, 0, NULL,1},
        {3, "Bruinz", "Adaan", "adaan.bruinz.01.05.2005@gamil.fr",  "0703614968", client->adresseLivraison, 0, 0, 0, NULL,1},
        {4, "Franchet", "Carole", "franchet.1991@gamil.fr",  "0671147031", client->adresseLivraison, 0, 0, 0, NULL,1},
        {5, "Virontes-Martinez", "Johnny", "johnny.vm@gamil.fr",  "0788045362", client->adresseLivraison, 0, 0, 0, NULL,1}
    };

    /* Commandes */
    Commande c1;
    c1.numero = 1001;
    c1.idClient = 1;
    c1.dateCommande = (Date) {6, 2, 2026};
    c1.capaciteLignes = 3;
    c1.lignes = (LigneCommande *)malloc(c1.capaciteLignes * sizeof(LigneCommande));
    c1.nbLignes = 1;
    c1.lignes[1] = {"AUD-0002", "Écouteurs sans fil", 1, 60.90, 60.90};
    





}

