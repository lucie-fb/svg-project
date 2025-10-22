#ifndef SHAPES
#define SHAPES
#include <stdio.h>

/**
 * @brief Création des couleurs pour le remplissage et le contour
 * @param r composante rouge du remplissage
 * @param g composante verte du remplissage
 * @param b composante bleue du remplissage
 * @param rl composante rouge de la ligne
 * @param gl composante verte de la ligne
 * @param bl composante bleue de la ligne
 */
typedef struct
{
    int r, g, b;
    int rl, gl, bl;
} rgb_t;

/**
 * @brief Lecture d'une couleur RGB pour l'utilisateur dans le terminal
 * @return une structure rgb_t contenant les valeurs RGB saisies par l'utilisateur
 */
rgb_t read_rgb_color(void);

/**
 * @brief Création de la size map
 * @param coordonnée cw
 * @param coordonnée cx
 * @param coordonnée cy
 * @param coordonnée cz
 */
typedef struct size_map_s
{
    int cw;
    int cx;
    int cy;
    int cz;
} size_map_t;

//Création de l'ellipse avec ces 2 coordonnées et ces 2 rayons, la rotation et la couleur
/**
 * @brief Création d'une ellipse
 * @param coordonnée cx
 * @param coordonnée cy
 * @param rayon rx
 * @param rayon ry
 * @param appel de la structure pour la couleur
 */
typedef struct ellipse_s
{
    int cx;
    int cy;
    int rx;
    int ry;
    rgb_t color;
} ellipse_t;

/**
 * @brief Création d'un rectangle
 * @param coordonnée x
 * @param coordonnée y
 * @param largeur width
 * @param longeur height
 * @param rayon rx
 * @param rayon ry
 * @param appel de la structure pour la couleur
 * @param coordonnées x1 et y1
 * @param coordonnées x2 et y2
 * @param coordonnées x3 et y3
 * @param coordonnées x4 et y4
 * @param rotation du rectangle
 */
typedef struct rectangle_s
{
    int x;
    int y;
    int width;
    int height;
    int rx;
    int ry;
    rgb_t color;
    int x1, y1;
    int x2, y2;
    int x3, y3;
    int x4, y4;
    int rotated;
} rectangle_t;

/**
 * @brief Création d'une ligne
 * @param coordonnée x1
 * @param coordonnée y1
 * @param coordonnée x2
 * @param coordonnée y2
 * @param appel de la structure pour la couleur
 */
typedef struct line_s
{
    int x1;
    int y1;
    int x2;
    int y2;
    rgb_t color;
} line_t;

/**
 * @brief Création d'une liste pour faire un polygone et une polyline
 * @param liste ListPolygone
 * @param appel de la liste ListPolygone qui est défini plus bas
 */
typedef struct ListPolygone ListPolygone;

/**
 * @brief création d'une nouvelle size map vide
 * @return un pointeur vers la nouvelle size map
 */
size_map_t *create_size_map(int cw, int cx, int cy, int cz);

/**
 * @brief libération de la mémoire
 * @param size_map est la carte à libérer
 */
void free_size_map(size_map_t *size_map);

/**
 * @brief Ecriture dans le terminal des coordonnées de la size map à 0
 * @param structure de la size map défini plus haut
 * @return coordonnées de la size map après que l'utilisateur ait choisi
 */
void print_size_map(size_map_t *size_map);

/**
 * @brief création d'une nouvelle ellipse vide
 * @return un pointeur vers la nouvelle ellipse
 */
ellipse_t *create_ellipse(int cx, int cy, int rx, int ry);

/**
 * @brief libération de la mémoire
 * @param ellipse est la forme à libérer
 */
void free_ellipse(ellipse_t *ellipse);

/**
 * @brief Ecriture dans le terminal des coordonnées de l'ellipse à 0
 * @param structure de l'ellipse défini plus haut
 * @return coordonnées de l'ellipse après que l'utilisateur ait choisi
 */
void print_ellipse(ellipse_t *ellipse);

/**
 * @brief écriture de l'ellipse dans le fichier svg
 * @param file est le fichier dans lequel écrire
 * @param ellipse est l'ellipse que nous affichons dans le fichier svg
 */
void write_ellipse(FILE *file, ellipse_t *ellipse);

/**
 * @brief création d'un nouveau rectangle vide
 * @return un pointeur vers le nouveau rectangle
 */
rectangle_t *create_rectangle(int x, int y, int width, int height, int rx, int ry);

/**
 * @brief libération de la mémoire
 * @param rectangle est la forme à libérer
 */
void free_rectangle(rectangle_t *rectangle);

/**
 * @brief Ecriture dans le terminal des coordonnées du rectangle à 0
 * @param structure du rectangle défini plus haut
 * @return coordonnées du rectangle après que l'utilisateur ait choisi
 */
void print_rectangle(rectangle_t *rectangle);

/**
 * @brief écriture du rectangle dans le fichier svg
 * @param file est le fichier dans lequel écrire
 * @param rectangle est le rectangle que nous affichons dans le fichier svg
 */
void write_rectangle(FILE *file, rectangle_t *rectangle);

/**
 * @brief Rotation de chaque point et conversion des radians en degrés
 * @param x pointeur vers la coordonée x du point à modifier
 * @param y pointeur vers la coordonée y du point à modifier
 * @param cx coordonée x du centre de rotation
 * @param cy coordonée y du centre de rotation
 * @param angle_rad angle de rotation en radians
 * @return
 */
void rotate_point(int *x, int *y, int cx, int cy, double angle_rad);

/**
 * @brief Calcul des 4 coins du rectangle, calcul du centre du rectangle, rotation des 4 coins et stockage des résultats 
 * @param appel de la structure du rectangle
 * @param ajout d'un angle en degré
 */
void rotate_rectangle(rectangle_t *rectangle, double angle_deg);

/**
 * @brief création d'une nouvelle ligne vide
 * @return un pointeur vers la nouvelle ligne
 */
line_t *create_line(int x1, int y1, int x2, int y2);

/**
 * @brief libération de la mémoire
 * @param line est la forme à libérer
 */
void free_line(line_t *line);

/**
 * @brief Ecriture dans le terminal des coordonnées de la ligne à 0
 * @param structure de la ligne défini plus haut
 * @return coordonnées de la ligne après que l'utilisateur ait choisi
 */
void print_line(line_t *line);

/**
 * @brief écriture d'une ligne dans le fichier svg
 * @param file est le fichier dans lequel écrire
 * @param line est la ligne que nous affichons dans le fichier svg
 */
void write_line(FILE *file, line_t *line);

/**
 * @brief type booléen pour représenter vrai ou faux
 * @return le résultat vrai ou faux
 */
typedef enum
{
    false,
    true
} Bool;

/**
 * @brief création d'un nouveau polygone vide
 * @return un pointeur vers le nouveau polygone
 */
ListPolygone *create_polygone(int x, int y, rgb_t color);

/**
 * @brief libération de la mémoire
 * @param polygone est la forme à libérer
 */
void free_polygone(ListPolygone *polygone);

/**
 * @brief Ecriture dans le terminal des informations de la liste à 0
 * @param structure de la liste
 * @return informations de la liste après que l'utilisateur ait choisi
 */
void print_list(ListPolygone *polygone);

/**
 * @brief Définition d'un point dans la liste de polygone
 * @param x coordonnée du polygone
 * @param y coordonnée du polygone
 * @param appel de la structure couleur
 * @param pointeur vers le prochain de la liste
 */
struct ListPolygone
{
    int x;
    int y;
    rgb_t color;
    struct ListPolygone *next;
};

// Prototypes
/**
 * @brief initialisation d'une nouvelle liste vide
 * @return un pointeur vers le début de la nouvelle liste
 */
ListPolygone *new_list(void);

/**
 * @brief affiche les points de la liste dans le terminal
 * @param li pointe vers le début de la liste
 * @return
 */
void print_list(ListPolygone *li);

/**
 * @brief écriture du polygone dans le fichier svg
 * @param file est le fichier dans lequel écrire
 * @param polygone est le polygone que nous affichons dans le fichier svg
 */
void write_polygone(FILE *file, ListPolygone *polygone);

/**
 * @brief Création d'un groupe de forme
 * @param structure groupe
 * @param appel de la structure qui est défini plus bas
 */
typedef struct group_s group_t;

/**
 * @brief énumération des différentes formes
 * @param SHAPE_ELLIPSE forme de type ellipse
 * @param SHAPE_RECTANGLE forme de type rectangle
 * @param SHAPE_LINE forme de type ligne
 * @param SHAPE_POLYGONE forme de type polygone
 * @param SHAPE_POLYLINE forme de type polyline
 * @param SHAPE_GROUPE forme de type groupe
 * @return
 */
typedef enum
{
    SHAPE_ELLIPSE,
    SHAPE_RECTANGLE,
    SHAPE_LINE,
    SHAPE_POLYGONE,
    SHAPE_POLYLINE,
    SHAPE_GROUP,
} shape_enum_t;

/**
 * @brief stockage de toutes les formes dans un seul endroit dans la mémoire
 * @param appel de la structure de l'ellipse
 * @param appel de la structure du rectangle
 * @param appel de la structure de la ligne
 * @param appel de la structure de la liste du polygone
 * @param appel de la structure du groupe
 */
typedef union
{
    ellipse_t *ellipse;
    rectangle_t *rectangle;
    line_t *line;
    ListPolygone *polygone;
    group_t *group;
} shape_union_t;

/**
 * @brief Création de la structure shape pour assembler l'enum et l'union
 * @param appel de la structure de l'énumération des formes
 * @param appel de la structure de l'union des formes
 */
typedef struct shape_s
{
    shape_enum_t type;
    shape_union_t shape;
} shape_t;

/**
 * @brief libération de la mémoire
 * @param shape_enum est la forme à libérer
 */
void free_shape_enum(shape_enum_t *shape_enum);

/**
 * @brief Libération de la mémoire
 * @param shape_union est la forme à libérer
 */
void free_shape_union(shape_union_t *shape_union);

/**
 * @brief libération de la mémoire
 * @param shape est la forme à libérer
 */
void free_shape(shape_t *shape);

/**
 * @brief création d'une nouvelle forme vide
 * @return un pointeur vers la nouvelle forme
 */
shape_t *create_shape(shape_enum_t type, void *form);

/**
 * @brief Création et définition d'un maillon de la liste doublement chaînée
 * @param appel de la structure des formes
 * @param pointeur vers le noeud précédent de la liste (back)
 * @param pointeur vers le noeud suivant de la liste (next)
 */
typedef struct DListNode
{
    shape_t *choice;
    struct DListNode *back;
    struct DListNode *next;
} DListNode;

/**
 * @brief Définition de la DList
 * @param création d'une variable int pour calculer la longueur de la liste
 * @param pointe vers le premier élément de la liste (begin)
 * @param pointe vers le dernier élément de la liste (end)
 */
typedef struct DList
{
    int length;
    struct DListNode *begin;
    struct DListNode *end;
} *DList;

/**
 * @brief initilisation de la liste à vide
 * @return une nouvelle liste vide
 */
DList new_dlist(void);

/**
 * @brief on vérifie si la liste est vide
 * @param test de la liste (li)
 * @return return true si la liste est vide et false si il y a quelque chose dedans
 */
Bool is_empty_dlist(DList li);

/**
 * @brief calcule de la longueur de la liste
 * @param li pour connaître la taille de la liste
 * @return le nombre d'éléments de la liste
 */
int dlist_length(DList li);

/**
 * @brief retourne la première forme de la liste
 * @param li la liste à examiner
 * @return un pointeur vers la première forme
 */
shape_t *dlist_first(DList li);

/**
 * @brief retourne la dernière forme de la liste
 * @param li la liste à examiner
 * @return un pointeur vers la dernière forme
 */
shape_t *dlist_last(DList li);

/**
 * @brief affichage du nombre d'éléments de la liste dans le terminal
 * @param li la liste à examiner
 * @return la liste 
 */
void print_dlist(DList li);

/**
 * @brief ajout d'un élément à la fin de la liste
 * @param li la liste à modifier
 * @param shape la forme à ajouter
 * @return liste mise à jour avec le nouvel élément
 */
DList push_back_dlist(DList li, shape_t *shape); // ajouter un élément à la fin de la liste

/**
 * @brief ajout d'un élément au début de la liste
 * @param li la liste à modifier
 * @param shape la forme à ajouter
 * @return liste mise à jour avec le nouvel élément
 */
DList push_front_dlist(DList li, shape_t *shape);

/**
 * @brief suppression d'un élément à la fin de la liste
 * @param li la liste à modifier
 * @param shape la forme à supprimer
 * @return liste mise à jour sans le dernier élément
 */
DList pop_back_dlist(DList li);

/**
 * @brief suppression d'un élément au début de la liste
 * @param li la liste à modifier
 * @param shape la forme à supprimer
 * @return liste mise à jour sans le premier élément
 */
DList pop_front_dlist(DList li);

/**
 * @brief affichage de la forme choisie
 * @param shape la forme à afficher
 */
void print_shape(shape_t *shape);

/**
 * @brief Création de la structure groupe
 * @param Liste de formes
 */
struct group_s
{
    DList shapes;
};

/**
 * @brief affichage des formes du groupe dans le terminal
 * @param group est un pointeur qui pointe vers le groupe affiché
 */
void print_group(group_t *group);

/**
 * @brief écriture du groupe dans le fichier svg
 * @param file est le fichier dans lequel écrire
 * @param group est le groupe que nous affichons dans le fichier svg
 */
void write_group(FILE *file, group_t *group);

/**
 * @brief création d'un nouveau groupe vide
 * @return un pointeur vers le nouveau groupe
 */
group_t *create_group(void);

/**
 * @brief libération de la mémoire
 * @param group est le groupe à libérer
 */
void free_group(group_t *group);

/**
 * @brief écriture d'une forme dans le fichier svg
 * @param file est le fichier dans lequel écrire
 * @param shape est la forme que nous affichons dans le fichier svg
 */
void write_shape(FILE *file, shape_t *shape);

#endif