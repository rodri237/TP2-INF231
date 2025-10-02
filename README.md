<<<<<<< HEAD
=======
# Mon projet TPINF231
>>>>>>> 776218b (Mise à jour du README)
# TP Listes Chaînées en C

Ce projet regroupe plusieurs programmes de gestion de **listes simplement chaînées**, **listes simplement chaînées circulaires**, et propose également la structure de base pour les **listes doublement chaînées**.  
Chaque fonction est écrite en C, robuste, et accompagne un menu interactif pour tester toutes les opérations principales.

---

## 1. Structure du projet

- `main.c` : Menu principal pour tester toutes les opérations sur les listes.
- `fichier.h` : Déclarations des structures et prototypes de fonctions.
- `fichier.c` : Implémentation de toutes les fonctions sur listes chaînées.

---

## 2. Explication détaillée des fonctionnalités

### **A. Opérations sur listes simplement chaînées**

- **Insertion en tête**  
  Ajoute un nouvel élément au début de la liste.

- **Insertion en queue**  
  Ajoute un nouvel élément à la fin de la liste.

- **Insertion à une position (après une valeur)**  
  Ajoute un élément juste après la première occurrence d’une valeur donnée.

- **Suppression en tête**  
  Retire le premier élément de la liste.

- **Suppression en queue**  
  Retire le dernier élément de la liste.

- **Suppression de la première occurrence d’une valeur**  
  Supprime le premier élément dont la donnée correspond à la valeur donnée.

- **Suppression de toutes les occurrences d’une valeur**  
  Parcourt toute la liste et supprime tous les éléments contenant cette valeur.

- **Tri de la liste**  
  Trie la liste de façon croissante avec un algorithme simple de tri par sélection.

- **Insertion triée**  
  Insère un élément à sa bonne place pour conserver l’ordre croissant.

---

### **B. Opérations sur listes simplement chaînées circulaires**

- **Insertion en tête circulaire**  
  Ajoute un nouvel élément juste avant le début, et adapte le chaînage pour que la liste reste circulaire.

- **Insertion en queue circulaire**  
  Fonctionnellement identique dans ce TP à l’insertion en tête circulaire (on ajoute avant le début et on adapte le chaînage).

---

### **C. Affichage**

- **Affichage de la liste**  
  Affiche tous les éléments de la liste dans l’ordre, jusqu’à la fin (NULL ou retour au début pour la circulaire).

---

## 3. Robustesse et gestion des erreurs

- Toutes les fonctions testent les cas particuliers (liste vide, allocation dynamique échouée, valeurs non trouvées).
- Les allocations mémoires sont vérifiées et un message d’erreur est affiché si `malloc` échoue.
- Le menu principal protège contre les saisies incorrectes : il redemande la saisie tant qu’elle n’est pas valide.

---

## 4. Exemple d’utilisation

Lancez le programme depuis un terminal :
```bash
gcc main.c fichier.c -o tp-liste
./tp-liste
```

Vous verrez un menu interactif :
```
==== MENU LISTE CHAINEE ====
1. Insertion en tête
2. Insertion en position (après une valeur)
3. Insertion en queue
4. Suppression en tête
5. Suppression première occurrence d'une valeur
6. Suppression en queue
7. Supprimer toutes les occurrences d'une valeur
8. Insertion triée
9. Trier la liste
10. Insertion tête circulaire
11. Insertion queue circulaire
12. Afficher la liste
0. Quitter
Votre choix:
```
Chaque opération demande les valeurs nécessaires et affiche la liste résultante.

---

## 5. Extension possible

- Il est possible d’ajouter la gestion des **listes doublement chaînées** et **listes doublement chaînées circulaires** en s’inspirant de la structure et des menus existants.
- Pour toute nouvelle fonction, il suffit de l’ajouter dans `fichier.h`, l’implémenter dans `fichier.c`, et la relier au menu de `main.c`.

---

## 6. Auteur

- TP réalisé par [Votre Nom], pour l’apprentissage des structures de données en C.
- Encadré par [Nom du professeur ou encadrant].

---

## 7. Remarques

- Ce TP illustre la manipulation de la mémoire dynamique en C et la gestion de listes chaînées classiques.
- Il est conseillé de libérer la mémoire à la fin du programme (libérer la liste avant de quitter).

---

## 8. Aide

Si vous rencontrez un problème à la compilation ou à l’exécution, vérifiez :
- Que tous les fichiers sont présents dans le même dossier.
- Que votre version de GCC est à jour.
- Que vous compilez bien tous les fichiers en même temps.
<<<<<<< HEAD
=======

>>>>>>> 776218b (Mise à jour du README)
