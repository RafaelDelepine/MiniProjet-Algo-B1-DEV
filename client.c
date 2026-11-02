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
    while(client[i].idClient == '\0');
    do {
        printf("Saisir le prénom du client :\n");
        scanf("%s", &client[i].prenom);
    }while(client[i].prenom == '\0');
    do {
        printf("Saisir le nom du Client :\n");
        scanf(" %s", &client[i].nom);
    }
    while(client[i].nom =='\0');
    do {
        printf("Saisir l'adresse mail du client :\n");
        scanf(" %f", &client[i].email);
    }
    while(client[i].email <= 0);
    do {
        printf("Saisir le numéro de téléphone du client :\n");
        scanf(" %d", &client[i].telephone);
    }while(client[i].telephone < 0);

    // adresse du clients
    do {
        printf("Saisir la rue du client");
        fgets(adresse[i].rue,sizeof(adresse[i]) , stdin);
        adresse[i].rue[strlen(adresse[i].rue)-1]='\0'; //supprimer le '\n'
    }while(adresse[i].rue < 0 && adresse[i].rue > 79 );


    do {
        printf("Saisir la ville du client");
        fgets(adresse[i].ville,sizeof(adresse[i]) , stdin);
        adresse[i].ville[strlen(adresse[i].ville)-1]='\0'; // supprimer le '\n'
    }while(adresse[i].ville < 0);

    do {
        printf("Saisir le code postal du client");
        fgets(adresse[i].codePostal,sizeof(adresse[i]) , stdin);
        adresse[i].codePostal[strlen(adresse[i].codePostal)-1]='\0'; // supprimer le '\n'
    }while(adresse[i].codePostal >5);

    do {
        printf("Saisir le pays du client");
        fgets(adresse[i].pays,sizeof(adresse[i]) , stdin);
        adresse[i].pays[strlen(adresse[i].pays)-1]='\0'; // supprimer le '\n'
    }while(adresse[i].pays <0);

    //suite de client
    do {
        printf("Saisir le nombre de point de fidélité du client :\n");
        scanf(" %d", &client[i].pointsFidelite);
    }while(client[i].pointsFidelite >= 0);

    do {
        printf("Saisir le nb de commandes du client :\n");
        scanf(" %d", &client[i].nbCommandes);
    }while(client[i].nbCommandes >= 0);
    return *client;
}
