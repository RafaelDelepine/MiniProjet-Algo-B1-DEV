//
// Created by glado on 23/10/2026.
//

#ifndef MINI_PROJET_CLIENT_H
#define MINI_PROJET_CLIENT_H

struct Client {
    int idClient;
    char nom[50];
    char prenom[50];
    char email[80];
    char telephone[15];
    struct Adresse {
        char rue[80];
        char ville[50];
        char codePostal[6];
        char pays[50];
    } adresse;
    int pointsFidelite;
    int nbCommande;
    int capaciteCommandes;
    /* ... Commande* ... */
    int actif;
};

#endif //MINI_PROJET_CLIENT_H
