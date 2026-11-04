#include <stdio.h>
#include <stdlib.h>
#include "commande.h"
#include "client.h"
#include "initialisation.h"
#include "produit.h"
#include "statistique.h"
#include "types.h"
#include "utils.h"

int nb_lig_commandes = 6, nb_lig_lcommandes = 6, nb_lig_dates = 6, nb_lig_adresses = 5, nb_lig_clients = 5, nb_lig_produit = 8;

Produit **produits;
Commande **commande;
LigneCommande **ligneCommande;
Client **client;
Date **date;
Adresse **adresse;

void initialiserTableaux () {
    produits = (Produit**) malloc(nb_lig_produit*sizeof(Produit));
    commande = (Commande**) malloc(nb_lig_commandes*sizeof(Commande));
    ligneCommande = (LigneCommande**) malloc(nb_lig_lcommandes*sizeof(LigneCommande));
    client = (Client**) malloc(nb_lig_clients*sizeof(Client));
    date = (Date**) malloc(nb_lig_dates*sizeof(Date));
    adresse = (Adresse**) malloc(nb_lig_adresses*sizeof(Adresse));
}

static int lireChoix(void)
{
    int choix;
    printf("  Votre choix : ");
    if (scanf("%d", &choix) != 1)
    {
        exit(EXIT_FAILURE); /* entree fermee : on quitte proprement */
    }
    return choix;
}

static void menuProduits(void)
{
    int choix;
    do
    {
        printf("\n===== GESTION DES PRODUITS =====\n");
        printf("  1. Ajouter un produit\n");
        printf("  2. Modifier un produit\n");
        printf("  3. Supprimer un produit\n");
        printf("  4. Afficher le catalogue\n");
        printf("  5. Rechercher un produit\n");
        printf("  0. Retour au menu principal\n");
        choix = lireChoix();

        switch (choix)
        {
            case 1: {
                ajouterProduit(*produits);
                break;
            }
            case 2: {
                modifierProduit(*produits);
                break;
            }
            case 3: {
                supprimerProduit(*produits);
                break;
            }
            case 4: {
                afficherCatalogue(*produits);
                break;
            }
            case 5: {
                rechercherProduit(*produits);
                break;
            }
            case 0:                      break; /* retour automatique */
            default: printf("  [!] Choix invalide.\n"); break;
        }
    } while (choix != 0);
}

static void menuClients(void)
{
    int choix;
    do
    {
        printf("\n===== GESTION DES CLIENTS =====\n");
        printf("  1. Ajouter un client\n");
        printf("  2. Modifier un client\n");
        printf("  3. Supprimer un client\n");
        printf("  4. Afficher la liste des clients\n");
        printf("  0. Retour au menu principal\n");
        choix = lireChoix();

        switch (choix)
        {
            case 1: {
                ajouterClient(*client, *adresse, *commande);
                break;
            }
            case 2: {
                modifierClient(*client, *adresse);
                break;
            }
            case 3: {
                supprimerClient(*client, *adresse);
                break;
            }
            case 4: {
                afficherListeClient(*client, *adresse);
                break;
            }
            case 0:                      break; /* retour automatique */
            default: printf("  [!] Choix invalide.\n"); break;
        }
    } while (choix != 0);
}

static void menuCommandes(void)
{
    int choix;
    do
    {
        printf("\n===== GESTION DES COMMANDES =====\n");
        printf("  1. Creer une commande\n");
        printf("  2. Afficher une commande\n");
        printf("  0. Retour au menu principal\n");
        choix = lireChoix();

        switch (choix) {
            case 1: {
                creerCommande(*commande, *ligneCommande, *client, *date, *adresse, *produits, &nb_lig_commandes, &nb_lig_clients, &nb_lig_produit);
                break;
            }
            case 2: {
                modifierSupprimerCommande(*commande, *ligneCommande, *client, *date, *adresse, *produits, &nb_lig_commandes, &nb_lig_clients);
                break;
            }
            case 3: {
                changerStatut(*commande, *client, *date, *adresse, &nb_lig_commandes);
                break;
            }
            case 4: {
                annulerCommande(*commande, *client, *date, *adresse, &nb_lig_commandes);
                break;
            }
            case 5: {
                afficherUneCommande(*commande, *ligneCommande, *client, *date, *adresse, &nb_lig_commandes);
                break;
            }
            case 0:                        break;
            default: printf("  [!] Choix invalide.\n"); break;
        }
    } while (choix != 0);
}

static void menuStatistiques(void)
{
    int choix;
    do
    {
        printf("\n===== STATISTIQUES =====\n");
        printf("  1. Chiffre d'affaires global\n");
        printf("  0. Retour au menu principal\n");
        choix = lireChoix();

        switch (choix)
        {
            case 1: afficherChiffreAffaires(); break;
            case 0:                            break;
            default: printf("  [!] Choix invalide.\n"); break;
        }
    } while (choix != 0);
}

/* ==========================================================================
 * PROGRAMME PRINCIPAL
 * ========================================================================== */
int main(void)
{
    initialiserTableaux();
    int choix;

    printf("==============================================\n");
    printf("  SHOPFLOW - Boutique en ligne (squelette)\n");
    printf("==============================================\n");

    do {
        printf("\n===== MENU PRINCIPAL =====\n");
        printf("  1. Gestion des produits\n");
        printf("  2. Gestion des clients\n");
        printf("  3. Gestion des commandes\n");
        printf("  4. Statistiques\n");
        printf("  0. Quitter\n");
        choix = lireChoix();

        switch (choix)
        {
            case 1: menuProduits();     break;
            case 2: menuClients();      break;
            case 3: menuCommandes();    break;
            case 4: menuStatistiques(); break;
            case 0: printf("\n  Au revoir !\n"); break;
            default: printf("  [!] Choix invalide.\n"); break;
        }
    } while (choix != 0);

    return EXIT_SUCCESS;
}