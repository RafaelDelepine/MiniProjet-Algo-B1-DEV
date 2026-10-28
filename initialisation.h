//
// Created by glado on 23/10/2026.
//
#ifndef MINI_PROJET_INITIALISATION_H
#define MINI_PROJET_INITIALISATION_H

struct Boutique {
    char nom[50];
    Produit* produits = NULL;
    int nbProduit;
    int capaciteProduits;
    Client* clients = NULL;
    int nbClient;
    int capaciteClient;
    int numeroSuivant;
    int idClientSuivant;
};

void initialiserDonneesTest(struct Boutique *b);

void detruireBoutique(struct Boutique *b);

#endif //MINI_PROJET_INITIALISATION_H
