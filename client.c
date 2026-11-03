#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"
#include "client.h"


int mail_differend;

Client ajouterClient(Client *client,  Adresse *adresse, Commande *commande) {
    client= (Client*) malloc(2*sizeof(Client));
    adresse = (Adresse*) malloc(2*sizeof(Adresse));
    commande = (Commande*) malloc(2*sizeof(Commande));
    int i = 0;

    /*id client*/
    do {
        printf("Saisir l'idClient :\n");
        scanf("%s", &client[i].idClient);
        i++;
    }while(client[i].idClient == '\0');

    /*nom du client*/
     do {
        printf("Saisir le nom du Client :\n");
        scanf(" %s", &client[i].nom);
    }while(client[i].nom =='\0');
    
    /*prénom du client*/
    do {
        printf("Saisir le prénom du client :\n");
        scanf("%s", &client[i].prenom);
    }while(client[i].prenom == '\0');
    
   /*adresse mail du client*/
    do {
        printf("Saisir l'adresse mail du client :\n");
        scanf(" %f", &client[i].email);
    }while(client[i].email <= 0);
    for (j=0 ; j<6 ; j++) {
        comp = strcmp(client[i].idClient, client[i].email); // A modifier !
        if (comp == 0) {
            printf("ERREUR : addresse mail déjà existante\nAnnulation de la suppression du client");
        return *client;
        }
    }
   
    /*numero de téléphone du client*/
    do {
        printf("Saisir le numéro de téléphone du client :\n");
        scanf(" %d", &client[i].telephone);
    }while(client[i].telephone < 0);

    // adresse du client
    /*rue*/
    do {
        printf("Saisir la rue du client");
        fgets(adresse[i].rue,sizeof(adresse[i]) , stdin);
        adresse[i].rue[strlen(adresse[i].rue)-1]='\0'; //supprimer le '\n'
    }while(adresse[i].rue < 0 && adresse[i].rue > 79 );

    /*ville*/

    do {
        printf("Saisir la ville du client");
        fgets(adresse[i].ville,sizeof(adresse[i]) , stdin);
        adresse[i].ville[strlen(adresse[i].ville)-1]='\0'; // supprimer le '\n'
    }while(adresse[i].ville < 0);

    /*code postal*/
    do {
        printf("Saisir le code postal du client");
        fgets(adresse[i].codePostal,sizeof(adresse[i]) , stdin);
        adresse[i].codePostal[strlen(adresse[i].codePostal)-1]='\0'; // supprimer le '\n'
    }while(adresse[i].codePostal >5);

    /*pays*/
    do {
        printf("Saisir le pays du client");
        fgets(adresse[i].pays,sizeof(adresse[i]) , stdin);
        adresse[i].pays[strlen(adresse[i].pays)-1]='\0'; // supprimer le '\n'
    }while(adresse[i].pays <0);

    //suite de client
    /*point de fidelite */
    do {
        printf("Saisir le nombre de point de fidélité du client :\n");
        scanf(" %d", &client[i].pointsFidelite); // NOLINT(*-err34-c)
    }while(client[i].pointsFidelite >= 0);

    /*nb de commandes*/
    do {
        printf("Saisir le nb de commandes du client :\n");
        scanf(" %d", &client[i].nbCommandes); // NOLINT(*-err34-c)
    }while(client[i].nbCommandes >= 0);

    /*capacité commande*/
    do {
        printf("Saisir la capacite de commandes du clients :\n");
        scanf(" %d", &client[i].capaciteCommandes);
    }while (client[i].capaciteCommandes >= client[i].nbCommandes);

    /*historique commande*/
    do {
        printf("Afficher l'historique des commandes du clients");
        fgets(*Commandes,sizeof(commande[i]) , stdin);
    };

    /*actif ou inactif ?*/
    do {
        printf(" Saisir si le client est actif : 1 ou inactif : 0 ");
        scanf("%d",&client[i].actif);
    };
    return *client;
}

/* Fonction modifier client */

Client modifierClient(Client * clients, Adresse * adresse) {
    /* Variables locales */
    int nb_lig_clients = 5;
    int i;
    int nb_client;

    /* Affichage du tableau */
    printf("Client actuel :\n");
    for (i=0 ; i<nb_lig_clients ; i++) {
        printf("%s, %s, %s, %f, %d, %d, %d\n", client[i].idClient,client[i].nom,client[i].prenom,client[i].email,client[i].telephone, adresse[i].rue, adresse[i].ville, adresse[i].codePostal, adresse[i].pays, client[i].pointsFidelite, client[i].nbCommande, client[i].capaciteCommandes, client[i].actif);
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
        scanf("%s", &client[i].prenom);
    }while(client[i].prenom == '\0');
    /*nouveaux nom*/
    do {
        printf("Saisir le nouveau nom du Client :\n");
        scanf(" %s", &client[i].nom);
    }while(client[i].nom =='\0');
    do {
        printf("Saisir la nouvelle adresse mail du client :\n");
        scanf(" %f", &client[i].email);
    }while(client[i].email <= 0);  //ATTENTION faut rajouter que l'adresse mail doit être unique
    do {
        printf("Saisir le nouveau numéro de téléphone du client :\n");
        scanf(" %d", &client[i].telephone);
    }while(client[i].telephone < 0)

    /* modification de l'adresse */
   do {
        printf("Saisir la nouvelle rue du client");
        fgets(adresse[i].rue,sizeof(adresse[i]) , stdin);
        adresse[i].rue[strlen(adresse[i].rue)-1]='\0'; //supprimer le '\n'
    }while(adresse[i].rue < 0 && adresse[i].rue > 79 );

    /*ville*/

    do {
        printf("Saisir la nouvelle ville du client");
        fgets(adresse[i].ville,sizeof(adresse[i]) , stdin);
        adresse[i].ville[strlen(adresse[i].ville)-1]='\0'; // supprimer le '\n'
    }while(adresse[i].ville < 0);

    /*code postal*/
    do {
        printf("Saisir le nouveau code postal du client");
        fgets(adresse[i].codePostal,sizeof(adresse[i]) , stdin);
        adresse[i].codePostal[strlen(adresse[i].codePostal)-1]='\0'; // supprimer le '\n'
    }while(adresse[i].codePostal >5);

    /*pays*/
    do {
        printf("Saisir le pays mis à jour du client");
        fgets(adresse[i].pays,sizeof(adresse[i]) , stdin);
        adresse[i].pays[strlen(adresse[i].pays)-1]='\0'; // supprimer le '\n'
    }while(adresse[i].pays <0);


    /* Réaffichage du tableau mis à jour */
    printf("\nListe des clients mise à jour :\n");
    for (i=0 ; i<nb_lig_client ; i++) {
        printf("%s, %s, %s, %f, %d, %d, %d\n", client[i].idClient,client[i].nom,client[i].prenom,client[i].email,client[i].telephone, adresse[i].rue, adresse[i].ville, adresse[i].codePostal, adresse[i].pays, client[i].pointsFidelite, client[i].nbCommande, client[i].capaciteCommandes, client[i].actif);
    }
    return *clients;
}

/* Fonction supprimerClient */
Client supprimerClient(Client *clients, Adresse * adresse) {
    /* Variables locales */
    int nb_lig_client = 5;
    int i,j,comp;
    int nb_client;
    char choix;

    /* Affichage du tableau */
    printf("Clients actuels :\n");
    for (i=0 ; i<nb_lig ; i++) {
        printf("%s, %s, %s, %f, %d, %d, %d\n", client[i].idClient,client[i].nom,client[i].prenom,client[i].email,client[i].telephone, adresse[i].rue, adresse[i].ville, adresse[i].codePostal, adresse[i].pays, client[i].pointsFidelite, client[i].nbCommande, client[i].capaciteCommandes, client[i].actif);
    }

    /* Sélection du client à supprimer */
    do {
        printf("Entrez la ligne du client à supprimer (de 0 à 7) : ");
        scanf("%d",nb_client);
    } while((nb_client < 0) && (nb_client > 5));
    i = nb_client;

    /* Annulation de la supression du client car présent dans une commande en cours */
    for (j=0 ; j<3 ; j++) {
        comp = strcmp(client[i].idClient, commande[i].idClient);
        if (comp == 0) {
            //manque déclaration lié les commandes au client
            printf("ERREUR : Client présent dans l'une des commandes\nAnnulation de la suppression du client");
            return *clients;
        }
    }

    /* Suppression du client après confirmation */
    printf("Voulez-vous réellement supprimer le client %s, %s,%s du catalogue ? (O/N)",client[i].idClient, client[i].nom,client[i].prenom);
    scanf("%c",&choix);
    if (choix == 'N') {
        printf("Annulation de la suppression du Client");
        return *client;
    }
    else {
        free(&client[i]);
        client = NULL;
        return *client;
    }

/* Fonction afficherListeClient */
Client afficherListeClient(Client *client,Adresse *adresse){
    /* Variables locales */
    int nb_lig_client = 5;
    int i;

    /* Affichage du tableau */
    printf("Client actuels :\n");
    for (i=0 ; i<nb_lig ; i++) {
        printf("%s, %s, %s, %f, %d, %d, %d\n", client[i].idClient,client[i].nom,client[i].prenom,client[i].email,client[i].telephone, adresse[i].rue, adresse[i].ville, adresse[i].codePostal, adresse[i].pays, client[i].pointsFidelite, client[i].nbCommande, client[i].capaciteCommandes, client[i].actif);
    }
    return *client;
    }

