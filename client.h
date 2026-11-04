//
// Created by glado on 23/10/2026.
//
#include "types.h"

#ifndef MINI_PROJET_CLIENT_H
#define MINI_PROJET_CLIENT_H

Client ajouterClient(Client *clients,  Adresse *adresse, Commande *commande);
Client modifierClient(Client * clients, Adresse * adresse);
Client supprimerClient(Client *clients, Adresse * adresse, Commande * commandes);
Client afficherListeClient(Client *client,Adresse *adresse);

#endif //MINI_PROJET_CLIENT_H
