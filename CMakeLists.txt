cmake_minimum_required(VERSION 4.3)
project(Mini_Projet C)

set(CMAKE_C_STANDARD 11)

add_executable(Mini_Projet main.c
        produit.c
        client.c
        commande.c
        statistique.c
        utils.c
        initialisation.c
        produit.h
        client.h
        commande.h
        statistique.h
        initialisation.h)
