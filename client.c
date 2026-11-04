#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"
#include "client.h"

Client ajouterClient(Client *clients,  Adresse *adresse, Commande *commande) {
    clients= (Client*) malloc(2*sizeof(Client));
    adresse = (Adresse*) malloc(2*sizeof(Adresse));
    commande = (Commande*) malloc(2*sizeof(Commande));
    int i = 0;
    int j;
    int comp;
    int longueur_adresse, longueur_ville, longueur_code_postal, longueur_pays;

    /*id client*/
    do {
        printf("Saisir l'idClient :\n");
        scanf("%s", &clients[i].idClient);
        i++;
    }while(clients[i].idClient == '\0');

    /*nom du client*/
     do {
        printf("Saisir le nom du Client :\n");
        scanf(" %s", &clients[i].nom);
    }while(clients[i].nom =='\0');

    /*prénom du client*/
    do {
        printf("Saisir le prénom du client :\n");
        scanf("%s", &clients[i].prenom);
    }while(clients[i].prenom == '\0');

   /*adresse mail du client*/
    do {
        printf("Saisir l'adresse mail du client :\n");
        scanf(" %f", &clients[i].email);
    }while(clients[i].email <= 0);
    for (j=0 ; j<5 ; j++) {
        comp = strcmp(clients[j].email, clients[i].email); // A modifier !
        if (comp == 0) {
            printf("ERREUR : addresse mail déjà existante\nAnnulation de la création du client");
        return *clients;
        }
    }

    /*numero de téléphone du client*/
    do {
        printf("Saisir le numéro de téléphone du client :\n");
        scanf(" %d", &clients[i].telephone);
    }while(clients[i].telephone < 0);

    // adresse du client
    /*rue*/
    do {
        printf("Saisir la rue du client");
        fgets(adresse[i].rue,sizeof(adresse[i]) , stdin);
        adresse[i].rue[strlen(adresse[i].rue)-1]='\0'; //supprimer le '\n'
        longueur_adresse = strlen(adresse[i].rue);
    }while(longueur_adresse < 0 && longueur_adresse > 79 );

    /*ville*/
    do {
        printf("Saisir la ville du client");
        fgets(adresse[i].ville,sizeof(adresse[i]) , stdin);
        adresse[i].ville[strlen(adresse[i].ville)-1]='\0'; // supprimer le '\n'
        longueur_ville = strlen(adresse[i].ville);
    }while(longueur_ville < 0);

    /*code postal*/
    do {
        printf("Saisir le code postal du client");
        fgets(adresse[i].codePostal,sizeof(adresse[i]) , stdin);
        adresse[i].codePostal[strlen(adresse[i].codePostal)-1]='\0'; // supprimer le '\n'
        longueur_code_postal = strlen(adresse[i].codePostal);
    }while(longueur_code_postal > 5);

    /*pays*/
    do {
        printf("Saisir le pays du client");
        fgets(adresse[i].pays,sizeof(adresse[i]) , stdin);
        adresse[i].pays[strlen(adresse[i].pays)-1]='\0'; // supprimer le '\n'
        longueur_pays = strlen(adresse[i].pays);
    }while(longueur_pays <0);

    //suite de client
    /*point de fidelite */
    do {
        printf("Saisir le nombre de point de fidélité du client :\n");
        scanf(" %d", &clients[i].pointsFidelite);
    }while(clients[i].pointsFidelite >= 0);

    /*nb de commandes*/
    do {
        printf("Saisir le nb de commandes du client :\n");
        scanf(" %d", &clients[i].nbCommandes);
    }while(clients[i].nbCommandes >= 0);

    /*capacité commande*/
    do {
        printf("Saisir la capacite de commandes du clients :\n");
        scanf(" %d", &clients[i].capaciteCommandes);
    }while (clients[i].capaciteCommandes >= clients[i].nbCommandes);

    int nb_lig_clients = 0;
    /*historique commande*/
    for (i=0 ; i<nb_lig_clients ; i++) {
        printf("%s",clients[i].commandes);
        fgets(*commande,sizeof(commande[i]) , stdin);
    };



    /*actif ou inactif ?*/
    do {
        printf(" Saisir si le client est actif : 1 ou inactif : 0 ");
        scanf("%d",&clients[i].actif);
    }while (clients[i].actif != 0 || clients[i].actif != 1);
    return *clients;
}

/* Fonction modifier client */

Client modifierClient(Client * clients, Adresse * adresse) {
    /* Variables locales */
    int nb_lig_clients = 5;
    int i;
    int nb_client;
    int longueur_rue, longueur_ville, longueur_code_postal, longueur_pays;

    /* Affichage du tableau */
    printf("Client actuel :\n");
    for (i=0 ; i<nb_lig_clients ; i++) {
        printf("%s, %s, %s, %f, %d, %d, %d\n", clients[i].idClient,clients[i].nom,clients[i].prenom,clients[i].email,clients[i].telephone, adresse[i].rue, adresse[i].ville, adresse[i].codePostal, adresse[i].pays, clients[i].pointsFidelite, clients[i].nbCommandes, clients[i].capaciteCommandes, clients[i].actif);
    }

    /* Sélection du client */
    do {
        printf("Entrez la ligne du client à modifier (de 0 à 4) : ");
        scanf("%d",nb_client);
    } while((nb_client < 0) && (nb_client > 4));
    i = nb_client;

    /* Modification du client */
    /* Nouveaux prénom */
   do {
        printf("Saisir le nouveau prénom du client :\n");
        scanf("%s", &clients[i].prenom);
    }while(clients[i].prenom == '\0');
    /*nouveaux nom*/
    do {
        printf("Saisir le nouveau nom du Client :\n");
        scanf(" %s", &clients[i].nom);
    }while(clients[i].nom =='\0');
    do {
        printf("Saisir la nouvelle adresse mail du client :\n");
        scanf(" %f", &clients[i].email);
    }while(clients[i].email <= 0);  //ATTENTION faut rajouter que l'adresse mail doit être unique
    do {
        printf("Saisir le nouveau numéro de téléphone du client :\n");
        scanf(" %d", &clients[i].telephone);
    }while(clients[i].telephone < 0);

    /* modification de l'adresse */
   do {
        printf("Saisir la nouvelle rue du client");
        fgets(adresse[i].rue,sizeof(adresse[i]) , stdin);
        adresse[i].rue[strlen(adresse[i].rue)-1]='\0'; //supprimer le '\n'
        longueur_rue = strlen(adresse[i].rue);
    }while(longueur_rue < 0 && longueur_rue > 79 );

    /*ville*/

    do {
        printf("Saisir la nouvelle ville du client");
        fgets(adresse[i].ville,sizeof(adresse[i]) , stdin);
        adresse[i].ville[strlen(adresse[i].ville)-1]='\0'; // supprimer le '\n'
        longueur_ville = strlen(adresse[i].ville);
    }while(longueur_ville < 0);

    /*code postal*/
    do {
        printf("Saisir le nouveau code postal du client");
        fgets(adresse[i].codePostal,sizeof(adresse[i]) , stdin);
        adresse[i].codePostal[strlen(adresse[i].codePostal)-1]='\0'; // supprimer le '\n'
        longueur_code_postal = strlen(adresse[i].codePostal);
    }while(longueur_code_postal > 5);

    /*pays*/
    do {
        printf("Saisir le pays mis à jour du client");
        fgets(adresse[i].pays,sizeof(adresse[i]) , stdin);
        adresse[i].pays[strlen(adresse[i].pays)-1]='\0'; // supprimer le '\n'
        longueur_pays = strlen(adresse[i].pays);
    }while(longueur_pays <0);


    /* Réaffichage du tableau mis à jour */
    printf("\nListe des clients mise à jour :\n");
    for (i=0 ; i<nb_lig_clients ; i++) {
        printf("%s, %s, %s, %f, %d, %d, %d\n", clients[i].idClient,clients[i].nom,clients[i].prenom,clients[i].email,clients[i].telephone, adresse[i].rue, adresse[i].ville, adresse[i].codePostal, adresse[i].pays, clients[i].pointsFidelite, clients[i].nbCommandes, clients[i].capaciteCommandes, clients[i].actif);
    }
    return *clients;
}

/* Fonction supprimerClient */
Client supprimerClient(Client *clients, Adresse * adresse, Commande * commandes) {
    /* Variables locales */
    int nb_lig_clients = 5;
    int i,j,comp;
    int nb_client;
    char choix;

    /* Affichage du tableau */
    printf("Clients actuels :\n");
    for (i=0 ; i<nb_lig_clients ; i++) {
        printf("%s, %s, %s, %f, %d, %d, %d\n", clients[i].idClient,clients[i].nom,clients[i].prenom,clients[i].email,clients[i].telephone, adresse[i].rue, adresse[i].ville, adresse[i].codePostal, adresse[i].pays, clients[i].pointsFidelite, clients[i].nbCommandes, clients[i].capaciteCommandes, clients[i].actif);
    }

    /* Sélection du client à supprimer */
    do {
        printf("Entrez la ligne du client à supprimer (de 0 à 7) : ");
        scanf("%d",nb_client);
    } while((nb_client < 0) && (nb_client > 5));
    i = nb_client;

    /* Annulation de la supression du client */
    for (j=0 ; j<3 ; j++) {
        if (clients[j].idClient == clients[i].idClient) {
            //manque déclaration lié les commandes au client
            printf("ERREUR : Le client commande\nAnnulation de la suppression du client");
            return *clients;
        }
    }

    /* Suppression du client après confirmation */
    printf("Voulez-vous réellement supprimer le client %s, %s, %s du catalogue ? (O/N)",clients[i].idClient, clients[i].nom,clients[i].prenom);
    scanf("%c",&choix);
    if (choix == 'N') {
        printf("Annulation de la suppression du Client");
        return *clients;
    }
    else {
        free(&clients[i]);
        clients = NULL;
        return *clients;
    }
}

/* Fonction afficherListeClient */
Client afficherListeClient(Client *client,Adresse *adresse){
    /* Variables locales */
    int nb_lig_clients = 5;
    int i;

    /* Affichage du tableau */
    printf("Client actuels :\n");
    for (i=0 ; i<nb_lig_clients ; i++) {
        printf("%s, %s, %s, %f, %d, %d, %d\n", client[i].idClient,client[i].nom,client[i].prenom,client[i].email,client[i].telephone, adresse[i].rue, adresse[i].ville, adresse[i].codePostal, adresse[i].pays, client[i].pointsFidelite, client[i].nbCommandes, client[i].capaciteCommandes, client[i].actif);
    }
    return *client;
    }
