#ifndef SHAPES
#define SHAPES

#include <stdio.h>

typedef struct size_map_s
{
    int cw;
    int cx;
    int cy;
    int cz;
} size_map_t;

typedef struct ellipse_s
{
    int cx;
    int cy;
    int rx;
    int ry;
} ellipse_t;

typedef struct rectangle_s
{
    int x;
    int y;
    int width;
    int height;
    int rx;
    int ry;
} rectangle_t;

typedef struct line_s
{
    int x1;
    int y1;
    int x2;
    int y2;
} line_t;

typedef struct ListPolygone ListPolygone;

size_map_t *create_size_map(int cw, int cx, int cy, int cz);

void free_size_map(size_map_t *size_map);

void print_size_map(size_map_t *size_map);

ellipse_t *create_ellipse(int cx, int cy, int rx, int ry);

void free_ellipse(ellipse_t *ellipse);

void print_ellipse(ellipse_t *ellipse);

void write_ellipse(FILE *file, ellipse_t *ellipse);

rectangle_t *create_rectangle(int x, int y, int width, int height, int rx, int ry);

void free_rectangle(rectangle_t *rectangle);

void print_rectangle(rectangle_t *rectangle);

void write_rectangle(FILE *file, rectangle_t *rectangle);

line_t *create_line(int x1, int y1, int x2, int y2);

void free_line(line_t *line);

void print_line(line_t *line);

void write_line(FILE *file, line_t *line);

// Définition d'un booléen
typedef enum
{
    false,
    true
} Bool;

typedef enum
{
    SHAPE_ELLIPSE,
    SHAPE_RECTANGLE,
    SHAPE_LINE,
    SHAPE_POLYGONE,
    SHAPE_POLYLINE
} shape_enum_t;

typedef union
{
    ellipse_t *ellipse;
    rectangle_t *rectangle;
    line_t *line;
    ListPolygone *polygone;
} shape_union_t;

typedef struct shape_s
{
    shape_enum_t type;
    shape_union_t shape;
} shape_t;

void free_shape_enum(shape_enum_t *shape_enum);
void free_shape_union(shape_union_t *shape_union);
void free_polygone(ListPolygone *poly);
void free_shape(shape_t *shape);

shape_t *create_shape(shape_enum_t type, void *form);
void print_list(ListPolygone *polygone);

// Définition de la liste chaînée
struct ListPolygone
{
    int x;
    int y;
    struct ListPolygone *next;
};

// Prototypes
ListPolygone *new_list(void);
int list_length(ListPolygone *li);
void print_list(ListPolygone *li);
ListPolygone *push_back_list(ListPolygone *li, int x, int y);
ListPolygone *pop_back_list(ListPolygone *li);

// Définition d'un maillon de la DListe
typedef struct DListNode
{
    shape_t *choice;
    struct DListNode *back;
    struct DListNode *next;
} DListNode;

// Définition d'une DListe
typedef struct DList
{
    int length;
    struct DListNode *begin; // pointe vers le premier élément de la liste
    struct DListNode *end;   // pointe vers le dernier élément de la liste
} *DList;

// Prototypes
DList new_dlist(void);
Bool is_empty_dlist(DList li);
int dlist_length(DList li);
shape_t *dlist_first(DList li);
shape_t *dlist_last(DList li);
void print_dlist(DList li);
DList push_back_dlist(DList li, shape_t *shape); // ajouter un élément à la fin de la liste
DList push_front_dlist(DList li, shape_t *shape);
DList pop_back_dlist(DList li);
DList pop_front_dlist(DList li);
void print_shape(shape_t *shape);

#endif