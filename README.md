# **projet_c**

**projet_c** est une application en **C** permettant de générer un fichier **SVG** contenant différentes formes géométriques. Elle propose une interface en ligne de commande pour créer, modifier et visualiser des formes dans un fichier nommé `test.svg`.

---

## ** Fonctionnalités**

- Création de formes SVG :
  - Ellipse
  - Rectangle
  - Ligne
  - Polygone
  - Polyline
  - Groupe de formes
- Sauvegarde automatique dans `test.svg`
- Menu interactif :
  - Ajouter une forme
  - Supprimer une forme
  - Quitter le programme

---

## ** Différents fichiers **
- main.c
- shapes.c
- shapes.h
- cli.c
- cli.h

## ** Compilation**

Le projet utilise **Make** pour la compilation. Avec un compilateur `gcc`.

```bash
make