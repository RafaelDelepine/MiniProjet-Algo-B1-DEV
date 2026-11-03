//
// Created by glado on 23/10/2026.
//

#ifndef MINI_PROJET_PRODUIT_H
#define MINI_PROJET_PRODUIT_H

#include "types.h"

Produit ajouterProduit(Produit *produit);
Produit modifierProduit(Produit *produits);
Produit supprimerProduit(Produit *produits, LigneCommande *lignecommande);
Produit afficherCatalogue(Produit *produits);
Produit rechercherProduit(Produit *produits);

#endif //MINI_PROJET_PRODUIT_H
