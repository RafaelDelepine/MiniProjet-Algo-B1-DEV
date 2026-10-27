//
// Created by glado on 23/10/2026.
//

#ifndef COMMANDE_H
#define COMMANDE_H
#include "client.h"

struct Commande {
    int numero;
    int idClient;
    struct Date {
        int jour;
        int mois;
        int annee;
    }dateCommande;
    char statut[20];
    int nbLignes;
    int capaciteLignes;
    struct LigneCommande {
        char refProduit[12];
        char designation[60];
        int quantite;
        float prixUnitaireHT;
        float sousTatalHT;
    };
    float montantBrut;
    float tauxRemise;
    float montantRemise;
    float montantHT;
    float montantTVA;
    float montantTTC;
    float fraisPort;
    struct Adresse adresseLivraison;
};



#endif
