//
// Created by glado on 23/10/2026.
//
#include "types.h"

#ifndef MINI_PROJET_CLIENT_H
#define MINI_PROJET_CLIENT_H

Client ajouterClient(Client *clients,  Adresse *adresse, Commande *commande, int *nb_lig_commandes, int *nb_lig_clients);
Client modifierClient(Client * clients, Adresse * adresse, int *nb_lig_clients);
Client supprimerClient(Client *clients, Adresse * adresse, Commande * commandes, int *nb_lig_clients);
Client afficherListeClient(Client *client,Adresse *adresse, int *nb_lig_clients);

#endif //MINI_PROJET_CLIENT_H
