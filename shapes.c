#include "shapes.h"
#include <stdlib.h>
#include <stdio.h>

size_map_t *create_size_map(int cw, int cx, int cy, int cz)
{
    size_map_t *size_map = malloc(sizeof(size_map_t));
    size_map->cw = cw;
    size_map->cx = cx;
    size_map->cy = cy;
    size_map->cz = cz;
    return size_map;
}

void free_size_map(size_map_t *size_map)
{
    free(size_map);
}

void print_size_map(size_map_t *size_map)
{
    printf("SIZE_MAP : CW=%d, CX=%d, CY=%d, CZ=%d\n",
           size_map->cw,
           size_map->cx,
           size_map->cy,
           size_map->cz);
}

void write_ellipse(FILE *file, ellipse_t *ellipse)
{
    fprintf(file,
            "<ellipse cx='%d' cy='%d' rx='%d' ry='%d' />\n",
            ellipse->cx,
            ellipse->cy,
            ellipse->rx,
            ellipse->ry);
}

ellipse_t *create_ellipse(int cx, int cy, int rx, int ry)
{
    ellipse_t *ellipse = malloc(sizeof(ellipse_t));
    ellipse->cx = cx;
    ellipse->cy = cy;
    ellipse->rx = rx;
    ellipse->ry = ry;
    return ellipse;
}

void free_ellipse(ellipse_t *ellipse)
{
    free(ellipse);
}

void print_ellipse(ellipse_t *ellipse)
{
    printf("ELLIPSE : CX=%d, CY=%d, RX=%d, RY=%d\n",
           ellipse->cx,
           ellipse->cy,
           ellipse->rx,
           ellipse->ry);
}

void write_rectangle(FILE *file, rectangle_t *rectangle)
{
    fprintf(file,
            "<rect x='%d' y='%d' width='%d' height='%d' rx='%d' ry='%d' />\n",
            rectangle->x,
            rectangle->y,
            rectangle->width,
            rectangle->height,
            rectangle->rx,
            rectangle->ry);
}

rectangle_t *create_rectangle(int x, int y, int width, int height, int rx, int ry)
{
    rectangle_t *rectangle = malloc(sizeof(rectangle_t));
    rectangle->x = x;
    rectangle->y = y;
    rectangle->width = width;
    rectangle->height = height;
    rectangle->rx = rx;
    rectangle->ry = ry;
    return rectangle;
}

void free_rectangle(rectangle_t *rectangle)
{
    free(rectangle);
}

void print_rectangle(rectangle_t *rectangle)
{
    printf("RECTANGLE : X=%d, Y=%d, WIDTH=%d, HEIGHT=%d, RX=%d, RY=%d\n",
           rectangle->x,
           rectangle->y,
           rectangle->width,
           rectangle->height,
           rectangle->rx,
           rectangle->ry);
}

void write_line(FILE *file, line_t *line)
{
    fprintf(file,
            "<line x1='%d' y1='%d' x2='%d' y2='%d' />\n",
            line->x1,
            line->y1,
            line->x2,
            line->y2);
}

line_t *create_line(int x1, int y1, int x2, int y2)
{
    line_t *line = malloc(sizeof(line_t));
    line->x1 = x1;
    line->y1 = y1;
    line->x2 = x2;
    line->y2 = y2;
    return line;
}

void free_line(line_t *line)
{
    free(line);
}

void print_line(line_t *line)
{
    printf("LINE : X1=%d, Y1=%d, X2=%d, Y2=%d\n",
           line->x1,
           line->y1,
           line->x2,
           line->y2);
}

ListPolygone *new_list(void)
{
    return NULL;
}

void print_list(ListPolygone *li)
{
    while (li != NULL)
    { // Tant que nous ne sommes pas en dehors de la liste
        printf("[%d]\n [%d]\n", li->x, li->y);
        li = li->next;
    }
}

ListPolygone *push_back_list(ListPolygone *li, int x, int y)
{
    ListPolygone *element;
    element = malloc(sizeof(*element));
    element->x = x;
    element->y = y;
    element->next = NULL;
    ListPolygone *temp;
    temp = li;

    while (temp->next)
    {
        temp = temp->next;
    }

    temp->next = element;
    free(temp);
    return li;
}

ListPolygone *pop_back_list(ListPolygone *li)
{
    if (li->next == NULL)
    {
        free(li);

        return NULL;
    }
    ListPolygone *temp = li;
    ListPolygone *before = NULL;

    while (temp->next != NULL)
    {
        before = temp;
        temp = temp->next;
    }
    before->next = NULL;
    free(temp);
    temp = NULL;

    return li;
}

DList new_dlist(void)
{
    return NULL;
}

Bool is_empty_dlist(DList li)
{
    if (li == NULL)
        return true;

    return false;
}

int dlist_length(DList li)
{
    if (is_empty_dlist(li))
        return 0;

    return li->length;
}

shape_t *dlist_first(DList li)
{
    if (is_empty_dlist(li))
        return NULL;

    return li->begin->choice;
}

shape_t *dlist_last(DList li)
{
    if (is_empty_dlist(li))
        return NULL;

    return li->end->choice;
}

void print_dlist(DList li)
{
    if (is_empty_dlist(li))
    {
        printf("Rien a afficher, la liste est vide. \n");
        return;
    }
    DListNode *temp = li->begin;

    while (temp != NULL)
    {
        print_shape(temp->choice);
        temp = temp->next;
    }
    printf("\n");
}

// Ajout d'un élément de la fin de la liste

DList push_back_dlist(DList li, shape_t *shape)
{
    DListNode *element;
    element = malloc(sizeof(*element));
    element->choice = shape;
    element->next = NULL;
    element->back = NULL;

    if (is_empty_dlist(li))
    {
        li = malloc(sizeof(*li));
        li->length = 0;
        li->begin = 0;
        li->end = element;
    }
    else
    {
        li->end->next = element;
        element->back = li->end;
        li->end = element;
    }
    li->length++;
    return li;
}

// Ajout d'un élément au début de la liste

DList push_front_dlist(DList li, shape_t *shape)
{
    DListNode *element;
    element = malloc(sizeof(*element));
    element->choice = shape;
    element->next = NULL;
    element->back = NULL;

    if (is_empty_dlist(li))
    {
        li = malloc(sizeof(*li));
        li->length = 0;
        li->begin = 0;
        li->end = element;
    }
    else
    {
        li->begin->back = element;
        element->next = li->begin;
        li->begin = element;
    }
    li->length++;
    return li;
}

// Supression du dernier élément de la liste

DList pop_back_dlist(DList li)
{
    if (is_empty_dlist(li))
    {
        printf("Liste vide, pas d'elements à supprimer.");
        return new_dlist();
    }
    if (li->begin == li->end)
    {
        free(li);
        li = NULL;

        return new_dlist();
    }
    DListNode *temp = li->end;

    li->end = li->end->back;
    li->end->next = NULL;
    temp->next = NULL;
    temp->back = NULL;

    free(temp);
    temp = NULL;

    li->length--;

    return li;
}

// Suppression du premier élément de la liste

DList pop_front_dlist(DList li)
{
    if (is_empty_dlist(li))
    {
        printf("Liste vide, pas d'elements à supprimer.");
        return new_dlist();
    }
    if (li->begin == li->end)
    {
        free(li);
        li = NULL;

        return new_dlist();
    }
    DListNode *temp = li->begin;

    li->begin = li->begin->back;
    li->begin->back = NULL;
    temp->next = NULL;
    temp->back = NULL;

    free(temp);
    temp = NULL;

    li->length--;

    return li;
}

shape_union_t *create_shape_union(void)
{
    shape_union_t *shape_union = malloc(sizeof(shape_union_t));
    return shape_union;
}

shape_enum_t *create_shape_enum(shape_enum_t *choice)
{
    shape_enum_t *shape_enum = malloc(sizeof(shape_enum_t));
    *shape_enum = *choice;
    return shape_enum;
}

shape_t *create_shape(shape_enum_t type, void *form)
{
    shape_t *shape = malloc(sizeof(shape_t));

    shape->type = type;
    switch (type)
    {
    case SHAPE_ELLIPSE:
        shape->shape.ellipse = (ellipse_t *)form;
        break;
    case SHAPE_RECTANGLE:
        shape->shape.rectangle = (rectangle_t *)form;
        break;
    case SHAPE_LINE:
        shape->shape.line = (line_t *)form;
        break;
    case SHAPE_POLYGONE:
        shape->shape.polygone = (ListPolygone *)form;
        break;
    case SHAPE_POLYLINE:
        shape->shape.polygone = (ListPolygone *)form;
        break;
    }

    return shape;
}

void free_shape_union(shape_union_t *shape_union)
{
    free(shape_union);
}

void free_shape_enum(shape_enum_t *shape_enum)
{
    free(shape_enum);
}

void free_polygone(ListPolygone *polygone)
{
    ListPolygone *temp;
    while (polygone != NULL)
    {
        temp = polygone;
        polygone = polygone->next;
        free(temp);
    }
}

void free_polyline(ListPolygone *polyline)
{
    ListPolygone *temp;
    while (polyline != NULL)
    {
        temp = polyline;
        polyline = polyline->next;
        free(temp);
    }
}

void free_shape(shape_t *shape)
{
    free(shape);
}

void print_shape(shape_t *shape)
{
    switch (shape->type)
    {
    case SHAPE_ELLIPSE:
        print_ellipse(shape->shape.ellipse);
        break;
    case SHAPE_RECTANGLE:
        print_rectangle(shape->shape.rectangle);
        break;
    case SHAPE_LINE:
        print_line(shape->shape.line);
        break;
    case SHAPE_POLYGONE:
        print_list(shape->shape.polygone);
        break;
    case SHAPE_POLYLINE:
        print_list(shape->shape.polygone);
        break;
    }
}
