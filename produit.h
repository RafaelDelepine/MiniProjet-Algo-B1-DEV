//
// Created by glado on 23/10/2026.
//

#ifndef MINI_PROJET_PRODUIT_H
#define MINI_PROJET_PRODUIT_H

#endif //MINI_PROJET_PRODUIT_H

struct Produit {
    char reference[12];
    char designation[60];
    char categorie[30];
    float prixUnitaireHT;
    int quantiteStock;
    int seuilAlerte;
    int actif;
};