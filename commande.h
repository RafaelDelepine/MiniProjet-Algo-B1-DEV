//
// Created by glado on 23/10/2026.
//

#ifndef COMMANDE_H
#define COMMANDE_H
#include "types.h"

Commande creerCommande(Commande *commande, LigneCommande *ligneCommande, Client *client, Date *date, Adresse *adresse, Produit *produits);
Commande modifierSupprimerCommande(Commande *commande, LigneCommande *ligneCommande, Client *client, Date *date, Adresse *adresse, Produit *produits, int *nb_lig_commandes, int *nb_lig_produit);


#endif
