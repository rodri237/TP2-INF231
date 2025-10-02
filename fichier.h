#ifndef FICHIER_H
#define FICHIER_H

/********* Liste simplement chaînée *********/
typedef struct node {
    int data;
    struct node* suiv;
} Node, *Liste;

Liste insertionTete(Liste debut, int val);
Liste insertionPosition(Liste debut, int val, int valR);
Liste insertionQueue(Liste debut, int val);
Liste suppressionTete(Liste debut);
Liste suppressionPosition(Liste debut, int valR);
Liste suppressionQueue(Liste debut);
Liste supprimerOccurrence(Liste debut, int valR);
Liste trier(Liste debut);
Liste insertionTrier(Liste debut, int val);
void afficherListe(Liste debut);

/********* Liste doublement chaînée *********/
typedef struct dnode {
    int data;
    struct dnode* prev;
    struct dnode* next;
} DNode, *DListe;

DListe dinsertionTrier(DListe debut, int val);
void dafficherListe(DListe debut);

/********* Liste simplement chaînée circulaire *********/
Liste insertionTeteCirculaire(Liste debut, int val);
Liste insertionQueueCirculaire(Liste debut, int val);
void afficherListeCirculaire(Liste debut);

/********* Liste doublement chaînée circulaire *********/
DListe dinsertionTeteCirculaire(DListe debut, int val);
DListe dinsertionQueueCirculaire(DListe debut, int val);
void dafficherListeCirculaire(DListe debut);

#endif