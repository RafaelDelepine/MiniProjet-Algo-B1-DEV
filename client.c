#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "produit.h"
#include "types.h"

Client ajouterClient(Client *client) {
    clients= (Client*) malloc(2*sizeof(Client));
    int i = 0;
    do {
        printf("Saisir l'idClient :\n");
        scanf("%s", clients[i].idClient);
        i++;
    }
    while(clients[i].idClient[0] == '\0');
    do {
        printf("Saisir le prénom du client :\n");
        scanf("%s", clients[i].prenom);
    while(clients[i].prenom[0] == '\0');
    do {
        printf("Saisir le nom du Client :\n");
        scanf(" %s", clients[i].nom);
    }
    while(clients[i].nom[0]=='\0');
    do {
        printf("Saisir l'adresse mail du client :\n");
        scanf(" %f", &clients[i].mail);
    }
    while(clients[i].mail <= 0);
    do {
        printf("Saisir le numéro de téléphone du client :\n");
        scanf(" %d", &clients[i].telephone);
    }
    while(clients[i].telephone < 0);

    return *clients;
}
