//
// Created by Nancy on 29/10/2026.
//

#ifndef MINIPROJET_ALGO_B1_DEV_MAIN_TYPES_H
#define MINIPROJET_ALGO_B1_DEV_MAIN_TYPES_H

typedef struct  {
    char nom[50];
    struct Produit* produits;
    int nbProduits;
    int capaciteProduits;
    struct Client* clients;
    int nbClients;
    int capaciteClients;
    int numeroSuivant;
    int idClientSuivant;
}Boutique;

typedef struct  {
    char reference[12];
    char designation[60];
    char categorie[30];
    float prixUnitaireHT;
    int quantiteStock;
    int seuilAlerte;
    int actif;
}Produit;

typedef struct  {
    int idClient;
    char nom[50];
    char prenom[50];
    char email[80];
    char telephone[15];
    struct Adresse* adresseLivraison;
    int pointsFidelite;
    int nbCommandes;
    int capaciteCommandes;
    struct Commande* commandes ;/* ... Commande* ... */
    int actif;
}Client;

typedef struct  {
    char rue[80];
    char ville[50];
    char codePostal[6];
    char pays[50];
} Adresse;

typedef struct  {
    int numero;
    int idClient;
    struct Date* dateCommande;
    char statut[20];
    int nbLignes;
    int capaciteLignes;
    struct LigneCommande* lignes;
    float montantBrutHT;
    float tauxRemise;
    float montantRemise;
    float montantHT;
    float montantTVA;
    float montantTTC;
    float fraisPort;
    struct Adresse* adresseLivraison;
}Commande;

typedef struct  {
    char refProduit[12];
    char designation[60];
    int quantite;
    float prixUnitaireHT;
    float sousTotalHT;
}LigneCommande;

typedef struct Date {
    int jour;
    int mois;
    int annee;
}dateCommande;

#endif //MINIPROJET_ALGO_B1_DEV_MAIN_TYPES_H
