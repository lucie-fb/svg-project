#include "cli.h"
#include "shapes.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void clear_buffer()
{
    int c = 0;
    while (c != '\n' && c != EOF)
    {
        c = getchar();
    }
}

int ask_for_out(char *message, char *error_message)
{
    int coordonnees;
    bool is_user_input_valid = false;

    while (!is_user_input_valid)
    {
        printf("%s\n", message);

        if (scanf("%d", &coordonnees) > 0)
        {
            is_user_input_valid = true;
        }
        else
        {
            printf("%s\n", error_message);
        }
        clear_buffer();
    }

    return coordonnees;
}

int ask_for_int(char *message, char *error_message)
{
    int rayon;
    bool is_user_input_valid = false;

    while (!is_user_input_valid)
    {
        printf("%s\n", message);

        if (scanf("%d", &rayon) > 0)
        {
            is_user_input_valid = true;
        }
        else
        {
            printf("%s\n", error_message);
        }
        clear_buffer();
    }

    return rayon;
}

ellipse_t *generate_ellipse()
{
    ellipse_t *ellipse = create_ellipse(
        ask_for_out("Choisir la coordonees x :", "La coordonnee n'est pas valable."),
        ask_for_out("Choisir la coordonees y :", "La coordonnee n'est pas valable."),
        ask_for_int("Choisir le rayon x :", "Le rayon n'est pas valable."),
        ask_for_int("Choisir le rayon y :", "Le rayon n'est pas valable."));
    return ellipse;
}

rectangle_t *generate_rectangle()
{
    rectangle_t *rectangle = create_rectangle(
        ask_for_out("Choisir la coordonee x :", "La coordonnee n'est pas valable."),
        ask_for_out("Choisir la coordonee y :", "La coordonnee n'est pas valable."),
        ask_for_out("Choisir la largeur :", "La coordonnee n'est pas valable."),
        ask_for_out("Choisir la longueur y :", "La coordonnee n'est pas valable."),
        ask_for_int("Choisir le rayon x :", "Le rayon n'est pas valable."),
        ask_for_int("Choisir le rayon y :", "Le rayon n'est pas valable."));
    return rectangle;
}

line_t *generate_line()
{
    line_t *line = create_line(
        ask_for_out("Choisir la coordonees x :", "La coordonnee n'est pas valable."),
        ask_for_out("Choisir la coordonees y :", "La coordonnee n'est pas valable."),
        ask_for_int("Choisir le rayon x :", "Le rayon n'est pas valable."),
        ask_for_int("Choisir le rayon y :", "Le rayon n'est pas valable."));
    return line;
}


/*shape_t *generate_shape() {

}*/


void edit_ellipse(ellipse_t *ellipse)
{
    ellipse->cx = ask_for_out("Choisir la coordonees x :", "La coordonnee n'est pas valable.");
    ellipse->cy = ask_for_out("Choisir la coordonees y :", "La coordonnee n'est pas valable.");
    ellipse->rx = ask_for_int("Choisir le rayon x :", "Le rayon n'est pas valable.");
    ellipse->ry = ask_for_int("Choisir le rayon y :", "Le rayon n'est pas valable.");
}

void edit_rectangle(rectangle_t *rectangle)
{
    rectangle->x = ask_for_out("Choisir la coordonee x :", "La coordonnee n'est pas valable.");
    rectangle->y = ask_for_out("Choisir la coordonee y :", "La coordonnee n'est pas valable.");
    rectangle->width = ask_for_out("Choisir la largeur :", "La coordonnee n'est pas valable.");
    rectangle->height = ask_for_out("Choisir la longueur y :", "La coordonnee n'est pas valable.");
    rectangle->rx = ask_for_int("Choisir le rayon x :", "Le rayon n'est pas valable.");
    rectangle->ry = ask_for_int("Choisir le rayon y :", "Le rayon n'est pas valable.");
}

void edit_line(line_t *line)
{
    line->x1 = ask_for_out("Choisir la coordonees x1 :", "La coordonnee n'est pas valable.");
    line->y1 = ask_for_out("Choisir la coordonees y1 :", "La coordonnee n'est pas valable.");
    line->x2 = ask_for_out("Choisir la coordonees x2 :", "La coordonnee n'est pas valable.");
    line->y2 = ask_for_out("Choisir la coordonees y2 :", "La coordonnee n'est pas valable.");
}