#include <stdio.h>
#include "commande.h"
#include "client.h"
#include "initialisation.h"
#include "produit.h"
#include "statistique.h"

struct Boutique {
    char nom[50];
    struct Produit* produits;
    int nbProduit;
    int capaciteProduits;
    struct Client* client;
    int nbClient;
    int capaciteClient;
    int numeroSuivant;
    int idClientSuivant;
};
int main() {

}
