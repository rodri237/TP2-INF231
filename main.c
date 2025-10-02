#include <stdio.h>
#include <stdlib.h>
#include "fichier.h"

// Fonction de saisie sécurisée
int lireInt(const char* msg) {
    int n, ok;
    do {
        printf("%s", msg);
        ok = scanf("%d", &n);
        while(getchar() != '\n'); // vide le buffer
        if (ok != 1) printf("Entrée invalide, recommencez.\n");
    } while (ok != 1);
    return n;
}

// Sous-menu pour liste simplement chaînée
void menuListeSimple() {
    Liste l = NULL;
    int choix, val, valR;

    do {
        printf("\n--- Liste simplement chaînée ---\n");
        printf("1. Insertion en tête\n");
        printf("2. Insertion après valeur\n");
        printf("3. Insertion en queue\n");
        printf("4. Suppression en tête\n");
        printf("5. Suppression d'une valeur\n");
        printf("6. Suppression en queue\n");
        printf("7. Supprimer toutes occurrences d'une valeur\n");
        printf("8. Insertion triée\n");
        printf("9. Trier la liste\n");
        printf("10. Afficher\n");
        printf("0. Retour\n");
        choix = lireInt("Votre choix: ");
        switch(choix) {
            case 1:
                val = lireInt("Entrez la valeur à insérer en tête: ");
                l = insertionTete(l, val);
                break;
            case 2:
                valR = lireInt("Après quelle valeur ? ");
                val = lireInt("Valeur à insérer: ");
                l = insertionPosition(l, val, valR);
                break;
            case 3:
                val = lireInt("Valeur à insérer en queue: ");
                l = insertionQueue(l, val);
                break;
            case 4:
                l = suppressionTete(l);
                break;
            case 5:
                val = lireInt("Valeur à supprimer (1ère occurrence): ");
                l = suppressionPosition(l, val);
                break;
            case 6:
                l = suppressionQueue(l);
                break;
            case 7:
                val = lireInt("Valeur à supprimer (toutes occurrences): ");
                l = supprimerOccurrence(l, val);
                break;
            case 8:
                val = lireInt("Valeur à insérer triée: ");
                l = insertionTrier(l, val);
                break;
            case 9:
                l = trier(l);
                break;
            case 10:
                afficherListe(l);
                break;
        }
    } while (choix != 0);
}

// Sous-menu pour liste doublement chaînée
void menuListeDouble() {
    DListe l = NULL;
    int choix, val;

    do {
        printf("\n--- Liste doublement chaînée ---\n");
        printf("1. Insertion triée\n");
        printf("2. Afficher\n");
        printf("0. Retour\n");
        choix = lireInt("Votre choix: ");
        switch(choix) {
            case 1:
                val = lireInt("Valeur à insérer triée: ");
                l = dinsertionTrier(l, val);
                break;
            case 2:
                dafficherListe(l);
                break;
        }
    } while (choix != 0);
}

// Sous-menu pour liste simplement chaînée circulaire
void menuListeSimpleCirc() {
    Liste l = NULL;
    int choix, val;

    do {
        printf("\n--- Liste simplement chaînée circulaire ---\n");
        printf("1. Insertion en tête\n");
        printf("2. Insertion en queue\n");
        printf("3. Afficher\n");
        printf("0. Retour\n");
        choix = lireInt("Votre choix: ");
        switch(choix) {
            case 1:
                val = lireInt("Valeur à insérer en tête: ");
                l = insertionTeteCirculaire(l, val);
                break;
            case 2:
                val = lireInt("Valeur à insérer en queue: ");
                l = insertionQueueCirculaire(l, val);
                break;
            case 3:
                afficherListeCirculaire(l);
                break;
        }
    } while (choix != 0);
}

// Sous-menu pour liste doublement chaînée circulaire
void menuListeDoubleCirc() {
    DListe l = NULL;
    int choix, val;

    do {
        printf("\n--- Liste doublement chaînée circulaire ---\n");
        printf("1. Insertion en tête\n");
        printf("2. Insertion en queue\n");
        printf("3. Afficher\n");
        printf("0. Retour\n");
        choix = lireInt("Votre choix: ");
        switch(choix) {
            case 1:
                val = lireInt("Valeur à insérer en tête: ");
                l = dinsertionTeteCirculaire(l, val);
                break;
            case 2:
                val = lireInt("Valeur à insérer en queue: ");
                l = dinsertionQueueCirculaire(l, val);
                break;
            case 3:
                dafficherListeCirculaire(l);
                break;
        }
    } while (choix != 0);
}

int main() {
    int choix;
    do {
        printf("\n=========== MENU PRINCIPAL ===========\n");
        printf("1. Liste simplement chaînée\n");
        printf("2. Liste doublement chaînée\n");
        printf("3. Liste simplement chaînée circulaire\n");
        printf("4. Liste doublement chaînée circulaire\n");
        printf("0. Quitter\n");
        choix = lireInt("Votre choix: ");
        switch(choix) {
            case 1: menuListeSimple(); break;
            case 2: menuListeDouble(); break;
            case 3: menuListeSimpleCirc(); break;
            case 4: menuListeDoubleCirc(); break;
        }
    } while (choix != 0);

    printf("Fin du programme.\n");
    return 0;
}