#include "shapes.h"
#include <stdlib.h>
#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>

rgb_t read_rgb_color(void)
{
    rgb_t color;
    printf("Choisissez la couleur RGB de remplissage: \n");
    printf("Rouge (0-255 : ");
    scanf("%d", &color.r);
    printf("Vert (0-255 : ");
    scanf("%d", &color.g);
    printf("Bleu (0-255 : ");
    scanf("%d", &color.b);
    printf("Choisissez la couleur RGB des lignes: \n");
    printf("Rouge (0-255 : ");
    scanf("%d", &color.rl);
    printf("Vert (0-255 : ");
    scanf("%d", &color.gl);
    printf("Bleu (0-255 : ");
    scanf("%d", &color.bl);
    return color;
}

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

void rotate_point(int *x, int *y, int cx, int cy, double angle_rad)
{
    int dx = *x - cx;
    int dy = *y - cy;
    *x = cx + (int)(dx * cos(angle_rad) - dy * sin(angle_rad));
    *y = cy + (int)(dx * sin(angle_rad) - dy * cos(angle_rad));
}

ellipse_t *create_ellipse(int cx, int cy, int rx, int ry)
{
    ellipse_t *ellipse = malloc(sizeof(ellipse_t));
    ellipse->cx = cx;
    ellipse->cy = cy;
    ellipse->rx = rx;
    ellipse->ry = ry;
    ellipse->color = read_rgb_color();
    return ellipse;
}

void write_ellipse(FILE *file, ellipse_t *ellipse)
{
    fprintf(file,
            "<ellipse cx='%d' cy='%d' rx='%d' ry='%d' fill='rgb(%d ,%d ,%d)' stroke='rgb(%d ,%d ,%d)'/>\n",
            ellipse->cx,
            ellipse->cy,
            ellipse->rx,
            ellipse->ry,
            ellipse->color.r,
            ellipse->color.g,
            ellipse->color.b,
            ellipse->color.rl,
            ellipse->color.gl,
            ellipse->color.bl);
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
    if (rectangle->rotated)
    {
        fprintf(file,
                "<polygon points='%d, %d %d, %d %d, %d %d,%d' fill='rgb(%d ,%d ,%d)' stroke='rgb(%d ,%d ,%d)'/>\n",
                rectangle->x1,
                rectangle->y1,
                rectangle->x2,
                rectangle->y2,
                rectangle->x3,
                rectangle->y3,
                rectangle->x4,
                rectangle->y4,
                rectangle->color.r,
                rectangle->color.g,
                rectangle->color.b,
                rectangle->color.rl,
                rectangle->color.gl,
                rectangle->color.bl);
    }
    else
    {
        fprintf(file,
                "<rect x='%d' y='%d' width='%d' height='%d' rx='%d' ry='%d' fill='rgb(%d ,%d ,%d)' stroke='rgb(%d ,%d ,%d)'/>\n",
                rectangle->x,
                rectangle->y,
                rectangle->width,
                rectangle->height,
                rectangle->rx,
                rectangle->ry,
                rectangle->color.r,
                rectangle->color.g,
                rectangle->color.b,
                rectangle->color.rl,
                rectangle->color.gl,
                rectangle->color.bl);
    }
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
    rectangle->color = read_rgb_color();
    rectangle->rotated = 0;
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

void rotate_rectangle(rectangle_t *rectangle, double angle_deg)
{
    double angle_rad = angle_deg * M_PI / 180.0;
    int x1 = rectangle->x;
    int y1 = rectangle->y;
    int x2 = rectangle->x + rectangle->width;
    int y2 = rectangle->y;
    int x3 = rectangle->x + rectangle->width;
    int y3 = rectangle->y + rectangle->height;
    int x4 = rectangle->x;
    int y4 = rectangle->y + rectangle->height;

    int cx = rectangle->x + rectangle->width / 2;
    int cy = rectangle->y + rectangle->height / 2;

    rotate_point(&x1, &y1, cx, cy, angle_rad);
    rotate_point(&x2, &y2, cx, cy, angle_rad);
    rotate_point(&x3, &y3, cx, cy, angle_rad);
    rotate_point(&x4, &y4, cx, cy, angle_rad);

    rectangle->rotated = 1;
    rectangle->x1 = x1;
    rectangle->x2 = x2;
    rectangle->x3 = x3;
    rectangle->x4 = x4;
    rectangle->y1 = y1;
    rectangle->y2 = y2;
    rectangle->y3 = y3;
    rectangle->y4 = y4;
    printf("Le rectangle pivote a :\n");
    printf("Coin 1 : (%d, %d)\n", x1, y1);
    printf("Coin 2 : (%d, %d)\n", x2, y2);
    printf("Coin 3 : (%d, %d)\n", x3, y3);
    printf("Coin 4 : (%d, %d)\n", x4, y4);
}

void write_line(FILE *file, line_t *line)
{
    fprintf(file,
            "<line x1='%d' y1='%d' x2='%d' y2='%d' fill='none' stroke='rgb(%d ,%d ,%d)' />\n",
            line->x1,
            line->y1,
            line->x2,
            line->y2,
            line->color.rl,
            line->color.gl,
            line->color.bl);
}

line_t *create_line(int x1, int y1, int x2, int y2)
{
    line_t *line = malloc(sizeof(line_t));
    line->x1 = x1;
    line->y1 = y1;
    line->x2 = x2;
    line->y2 = y2;
    line->color = read_rgb_color();
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

ListPolygone *create_polygone(int x, int y, rgb_t color)
{
    ListPolygone *polygone = malloc(sizeof(ListPolygone));
    polygone->x = x;
    polygone->y = y;
    polygone->color = color;
    polygone->next = NULL;
    return polygone;
}

void write_polygone(FILE *file, ListPolygone *polygone)
{
    fprintf(file, "<polygon points='");
    ListPolygone *current = polygone;
    while (current)
    {
        fprintf(file, "%d\n, %d\n", current->x, current->y);
        current = current->next;
    }
    fprintf(file, "' fill='rgb(%d ,%d ,%d)' stroke='rgb(%d ,%d ,%d)'/>", polygone->color.r, polygone->color.g, polygone->color.b, polygone->color.rl, polygone->color.gl, polygone->color.bl);
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

group_t *create_group(void)
{
    group_t *group = malloc(sizeof(group_t));
    group->shapes = new_dlist();
    return group;
}

void write_group(FILE *file, group_t *group)
{
    fprintf(file, "<g>'\n");
    DListNode *node = group->shapes->begin;
    while (node)
    {
        write_shape(file, node->choice);
        node = node->next;
    }
    fprintf(file, "</g>\n");
}

void print_group(group_t *group)
{

    printf("Contenu du groupe (%d forme%s) :\n", dlist_length(group->shapes), dlist_length(group->shapes) > 1 ? "s" : "");
    int index = 1;
    DListNode *node = group->shapes->begin;
    while (node)
    {
        printf("Forme %d : \n", index++);
        print_shape(node->choice);
        node = node->next;
    }
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
    case SHAPE_GROUP:
        shape->shape.group = (group_t *)form;
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

void free_group(group_t *group)
{
    DListNode *node = group->shapes->begin;
    while (node)
    {
        free_shape(node->choice);
        node = node->next;
    }
    free(group->shapes);
    free(group);
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
    case SHAPE_GROUP:
        print_group(shape->shape.group);
    }
}

void write_shape(FILE *file, shape_t *shape)
{
    switch (shape->type)
    {
    case SHAPE_ELLIPSE:
        write_ellipse(file, shape->shape.ellipse);
        break;
    case SHAPE_RECTANGLE:
        write_rectangle(file, shape->shape.rectangle);
        break;
    case SHAPE_LINE:
        write_line(file, shape->shape.line);
        break;
    case SHAPE_POLYGONE:
        write_polygone(file, shape->shape.polygone);
        break;
    case SHAPE_POLYLINE:
        write_polygone(file, shape->shape.polygone);
        break;
    case SHAPE_GROUP:
        write_group(file, shape->shape.group);
        break;
    }
}
