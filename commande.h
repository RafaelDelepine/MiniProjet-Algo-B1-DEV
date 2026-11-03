//
// Created by glado on 23/10/2026.
//

#ifndef COMMANDE_H
#define COMMANDE_H
#include "types.h"

Commande creerCommande(Commande *commande, LigneCommande *ligneCommande, Client *client, Date *date, Adresse *adresse, Produit *produits, int *nb_lig_commandes, int *nb_lig_clients, int *nb_lig_produit);
Commande modifierSupprimerCommande(Commande *commande, LigneCommande *ligneCommande, Client *client, Date *date, Adresse *adresse, Produit *produits, int *nb_lig_commandes, int *nb_lig_produit);
Commande changerStatut(Commande *commande, Client *client, Date *date, Adresse *adresse, int *nb_lig_commandes);
Commande annulerCommande(Commande *commande, Client *client, Date *date, Adresse *adresse, int *nb_lig_commandes);
void afficherUneCommande(Commande *commande, LigneCommande *ligneCommande, Client *client, Date *date, Adresse *adresse, int *nb_lig_commandes);

#endif
