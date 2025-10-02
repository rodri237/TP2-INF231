#include "fichier.h"
#include <stdio.h>
#include <stdlib.h>

/********* Liste simplement chaînée *********/
void afficherListe(Liste debut) {
    Liste temp = debut;
    printf("[ ");
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->suiv;
    }
    printf("]\n");
}

Liste insertionTete(Liste debut, int val) {
    Liste b = malloc(sizeof(Node));
    if (!b) exit(EXIT_FAILURE);
    b->data = val;
    b->suiv = debut;
    return b;
}

Liste insertionPosition(Liste debut, int val, int valR) {
    Liste temp = debut;
    while (temp && temp->data != valR) temp = temp->suiv;
    if (!temp) return debut;
    Liste b = malloc(sizeof(Node));
    if (!b) exit(EXIT_FAILURE);
    b->data = val;
    b->suiv = temp->suiv;
    temp->suiv = b;
    return debut;
}

Liste insertionQueue(Liste debut, int val) {
    Liste b = malloc(sizeof(Node));
    if (!b) exit(EXIT_FAILURE);
    b->data = val;
    b->suiv = NULL;
    if (!debut) return b;
    Liste temp = debut;
    while (temp->suiv) temp = temp->suiv;
    temp->suiv = b;
    return debut;
}

Liste suppressionTete(Liste debut) {
    if (!debut) return NULL;
    Liste temp = debut;
    debut = debut->suiv;
    free(temp);
    return debut;
}

Liste suppressionPosition(Liste debut, int valR) {
    if (!debut) return NULL;
    if (debut->data == valR) return suppressionTete(debut);
    Liste temp = debut;
    while (temp->suiv && temp->suiv->data != valR) temp = temp->suiv;
    if (temp->suiv) {
        Liste toDel = temp->suiv;
        temp->suiv = toDel->suiv;
        free(toDel);
    }
    return debut;
}

Liste suppressionQueue(Liste debut) {
    if (!debut) return NULL;
    if (!debut->suiv) { free(debut); return NULL; }
    Liste temp = debut;
    while (temp->suiv->suiv) temp = temp->suiv;
    free(temp->suiv);
    temp->suiv = NULL;
    return debut;
}

Liste supprimerOccurrence(Liste debut, int valR) {
    while (debut && debut->data == valR) {
        Liste tmp = debut;
        debut = debut->suiv;
        free(tmp);
    }
    if (!debut) return NULL;
    Liste curr = debut;
    while (curr->suiv) {
        if (curr->suiv->data == valR) {
            Liste tmp = curr->suiv;
            curr->suiv = tmp->suiv;
            free(tmp);
        } else {
            curr = curr->suiv;
        }
    }
    return debut;
}

Liste trier(Liste debut) {
    if (!debut) return NULL;
    for (Liste i = debut; i->suiv; i = i->suiv) {
        for (Liste j = i->suiv; j; j = j->suiv) {
            if (j->data < i->data) {
                int tmp = i->data;
                i->data = j->data;
                j->data = tmp;
            }
        }
    }
    return debut;
}

Liste insertionTrier(Liste debut, int val) {
    Liste b = malloc(sizeof(Node));
    if (!b) exit(EXIT_FAILURE);
    b->data = val;
    b->suiv = NULL;
    if (!debut || val < debut->data) {
        b->suiv = debut;
        return b;
    }
    Liste curr = debut;
    while (curr->suiv && curr->suiv->data < val) curr = curr->suiv;
    b->suiv = curr->suiv;
    curr->suiv = b;
    return debut;
}

/********* Liste doublement chaînée *********/
void dafficherListe(DListe debut) {
    DListe temp = debut;
    printf("[ ");
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("]\n");
}

DListe dinsertionTrier(DListe debut, int val) {
    DListe b = malloc(sizeof(DNode));
    if (!b) exit(EXIT_FAILURE);
    b->data = val;
    b->prev = b->next = NULL;
    if (!debut || val < debut->data) {
        b->next = debut;
        if (debut) debut->prev = b;
        return b;
    }
    DListe curr = debut;
    while (curr->next && curr->next->data < val) curr = curr->next;
    b->next = curr->next;
    b->prev = curr;
    if (curr->next) curr->next->prev = b;
    curr->next = b;
    return debut;
}

/********* Liste simplement chaînée circulaire *********/
void afficherListeCirculaire(Liste debut) {
    if (!debut) { printf("[]\n"); return; }
    Liste temp = debut;
    printf("[ ");
    do {
        printf("%d ", temp->data);
        temp = temp->suiv;
    } while (temp && temp != debut);
    printf("]\n");
}

Liste insertionTeteCirculaire(Liste debut, int val) {
    Liste b = malloc(sizeof(Node));
    if (!b) exit(EXIT_FAILURE);
    b->data = val;
    if (!debut) {
        b->suiv = b;
        return b;
    }
    Liste temp = debut;
    while (temp->suiv != debut) temp = temp->suiv;
    temp->suiv = b;
    b->suiv = debut;
    return b;
}

Liste insertionQueueCirculaire(Liste debut, int val) {
    return insertionTeteCirculaire(debut, val); // identique
}

/********* Liste doublement chaînée circulaire *********/
void dafficherListeCirculaire(DListe debut) {
    if (!debut) { printf("[]\n"); return; }
    DListe temp = debut;
    printf("[ ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp && temp != debut);
    printf("]\n");
}

DListe dinsertionTeteCirculaire(DListe debut, int val) {
    DListe b = malloc(sizeof(DNode));
    if (!b) exit(EXIT_FAILURE);
    b->data = val;
    if (!debut) {
        b->next = b->prev = b;
        return b;
    }
    DListe last = debut->prev;
    b->next = debut;
    b->prev = last;
    last->next = b;
    debut->prev = b;
    return b;
}

DListe dinsertionQueueCirculaire(DListe debut, int val) {
    DListe b = dinsertionTeteCirculaire(debut, val);
    return b->prev; // le nouveau "dernier"
}