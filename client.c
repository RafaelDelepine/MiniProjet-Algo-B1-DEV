#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"
#include "client.h"


Client ajouterClient(Client *client, [[maybe_unused]] Adresse *adresse) {
    client= (Client*) malloc(2*sizeof(Client));
    adresse = (Adresse*) malloc(2*sizeof(Adresse));
    int i = 0;
    do {
        printf("Saisir l'idClient :\n");
        scanf("%s", &client[i].idClient);
        i++;
    }
    while(client[i].idClient[0] == '\0');
    do {
        printf("Saisir le prénom du client :\n");
        scanf("%s", &client[i].prenom);
    }while(client[i].prenom[0] == '\0');
    do {
        printf("Saisir le nom du Client :\n");
        scanf(" %s", &client[i].nom);
    }
    while(client[i].nom[0]=='\0');
    do {
        printf("Saisir l'adresse mail du client :\n");
        scanf(" %f", &client[i].email);
    }
    while(client[i].email <= 0);
    do {
        printf("Saisir le numéro de téléphone du client :\n");
        scanf(" %d", &client[i].telephone);
    }
    while(client[i].telephone < 0);

    do {
        printf("Saisir la rue du client");
        fgets(client[i].rue,sizeof(client[i]) , stdin);
        client[i].rue[strlen(client[i].rue)-1]='\0'; # supprimer le '\n'
    }while(client[i]-> adresse.rue < 0);

    return *client;
}
