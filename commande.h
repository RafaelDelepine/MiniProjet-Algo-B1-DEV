//
// Created by glado on 23/10/2026.
//

#ifndef COMMANDE_H
#define COMMANDE_H
#include "types.h"

Commande creerCommande(Commande *commande, Client *client, Date *date);
Commande afficherUneCommande(Commande *commande);

#endif
