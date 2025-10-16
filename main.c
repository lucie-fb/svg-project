#include <stdio.h>
#include <stdlib.h>
#include "shapes.h"
#include "cli.h"
#include <string.h>

void afficherMenu()
{
    printf("Menu :\n");
    printf("1. Ajouter une forme\n");
    printf("2. Supprimer une forme\n");
    printf("3. Sauvegarder\n");
    printf("4. Quitter\n");
}

int main(void)
{

    size_map_t *size_map = create_size_map(0, 0, 0, 0);
    DList mylist = new_dlist();
    print_dlist(mylist);
    ListPolygone *polygone = new_list();
    print_list(polygone);
    printf("La taille de la liste est : %d\n", dlist_length(mylist));

    int menu = 0;
    int ajout = 0;
    int forme_choisie = 0;
    shape_t *shape = NULL;

    printf("Choisissez les 4 coordonnees de la map\n");
    size_map->cw = ask_for_out("Choisir la coordonees w :", "La coordonnee n'est pas valable.");
    size_map->cx = ask_for_out("Choisir la coordonees x :", "La coordonnee n'est pas valable.");
    size_map->cy = ask_for_out("Choisir la coordonees y :", "La coordonnee n'est pas valable.");
    size_map->cz = ask_for_out("Choisir la coordonees z :", "La coordonnee n'est pas valable.");
    FILE *write_file = fopen("test.svg", "w");
    fprintf(write_file, "<svg viewBox='%d %d %d %d' xmlns='http://www.w3.org/2000/svg'>\n", size_map->cw, size_map->cx, size_map->cy, size_map->cz);

    print_size_map(size_map);

    do
    {
        afficherMenu();
        printf("Choisissez ce que vous voulez faire : \n ");

        scanf("%d", &menu);

        if (menu == 1)
        {
            printf("Voulez-vous ajouter un element : \n 1. au debut de la liste \n 2. a la fin de la liste\n");
            scanf("%d", &ajout);
            if (ajout == 1)
            {
                printf("Quelle forme choisissez-vous ? \n Ellipse -> 1\n Rectangle -> 2\n Ligne -> 3\n Polygone -> 4 \n Polyline -> 5 \n Entree votre choix : ");
                scanf("%d", &forme_choisie);

                if (forme_choisie == 1)
                {
                    ellipse_t *ellipse = create_ellipse(0, 0, 0, 0);
                    print_ellipse(ellipse);
                    edit_ellipse(ellipse);
                    print_ellipse(ellipse);
                    write_ellipse(write_file, ellipse);
                    shape = create_shape(SHAPE_ELLIPSE, ellipse);
                    free_ellipse(ellipse);
                }
                else if (forme_choisie == 2)
                {
                    rectangle_t *rectangle = create_rectangle(0, 0, 0, 0, 0, 0);
                    print_rectangle(rectangle);
                    edit_rectangle(rectangle);
                    print_rectangle(rectangle);
                    write_rectangle(write_file, rectangle);
                    shape = create_shape(SHAPE_RECTANGLE, rectangle);
                    free_rectangle(rectangle);
                }
                else if (forme_choisie == 3)
                {
                    line_t *line = create_line(0, 0, 0, 0);
                    print_line(line);
                    edit_line(line);
                    print_line(line);
                    write_line(write_file, line);
                    shape = create_shape(SHAPE_LINE, line);
                    free_line(line);
                }
                else if (forme_choisie == 4)
                {
                    int n = ask_for_int("Combien de points voulez-vous pour le polygone :", "Valeur invalide\n");
                    int x, y;
                    char points_str1[1024] = "";

                    for (int i = 0; i < n; i++) 
                    {
                        printf("Point %d :\n", i + 1);
                        x = ask_for_out("Coordonnee x :", "Valeur invalide");
                        y = ask_for_out("Coordonnee y :", "Valeur invalide");
                        char buff[50];
                        sprintf(buff, "%d, %d ", x, y); // pour séparer les points
                        strcat(points_str1, buff);
                    }

                    fprintf(write_file, "<polygon points='%s'/>\n", points_str1);
                    print_list(polygone);
                    shape = create_shape(SHAPE_POLYGONE, polygone);
                    free_polygone(polygone);
                }
                else if (forme_choisie == 5)
                {
                    int p = ask_for_int("Combien de points voulez-vous pour la polyline :", "Valeur invalide\n");
                    int x, y;
                    char points_str2[1024] = "";

                    for (int i = 0; i < p; i++) 
                    {
                        printf("Point %d :\n", i + 1);
                        x = ask_for_out("Coordonnee x :", "Valeur invalide");
                        y = ask_for_out("Coordonnee y :", "Valeur invalide");
                        char buff[50];
                        sprintf(buff, "%d, %d ", x, y); // pour séparer les points
                        strcat(points_str2, buff);
                    }
                    fprintf(write_file, "<polyline fill='none' stroke='black' points='%s'/>\n", points_str2);
                    print_list(polygone);
                    shape = create_shape(SHAPE_POLYLINE, polygone);
                    free_polygone(polygone);
                }
                mylist = push_front_dlist(mylist, shape);
            }
            else if (ajout == 2)
            {
                printf("Quelle forme choisissez-vous ? \n Ellipse -> 1\n Rectangle -> 2\n Ligne -> 3\n Entree votre choix : ");
                scanf("%d", &forme_choisie);

                if (forme_choisie == 1)
                {
                    ellipse_t *ellipse = create_ellipse(0, 0, 0, 0);
                    print_ellipse(ellipse);
                    edit_ellipse(ellipse);
                    print_ellipse(ellipse);
                    write_ellipse(write_file, ellipse);
                    shape = create_shape(SHAPE_ELLIPSE, ellipse);
                    free_ellipse(ellipse);
                }
                else if (forme_choisie == 2)
                {
                    rectangle_t *rectangle = create_rectangle(0, 0, 0, 0, 0, 0);
                    print_rectangle(rectangle);
                    edit_rectangle(rectangle);
                    print_rectangle(rectangle);
                    write_rectangle(write_file, rectangle);
                    shape = create_shape(SHAPE_RECTANGLE, rectangle);
                    free_rectangle(rectangle);
                }
                else if (forme_choisie == 3)
                {
                    line_t *line = create_line(0, 0, 0, 0);
                    print_line(line);
                    edit_line(line);
                    print_line(line);
                    write_line(write_file, line);
                    shape = create_shape(SHAPE_LINE, line);
                    free_line(line);
                }
                else if (forme_choisie == 4)
                {
                    int n = ask_for_int("Combien de points voulez-vous pour le polygone :", "Valeur invalide\n");
                    int x, y;
                    char points_str2[1024] = "";

                    for (int i = 0; i < n; i++)
                    {
                        printf("Point %d :\n", i + 1);
                        x = ask_for_out("Coordonnee x :", "Valeur invalide");
                        y = ask_for_out("Coordonnee y :", "Valeur invalide");
                        char buff[50];
                        sprintf(buff, "%d, %d", x, y); // pour séparer les points
                        strcat(points_str2, buff);
                    }
                    fprintf(write_file, "<polygon points='%s'/>\n", points_str2);
                    print_list(polygone);
                    shape = create_shape(SHAPE_POLYGONE, polygone);
                    free_polygone(polygone);
                }
                else if (forme_choisie == 5)
                {
                    int p = ask_for_int("Combien de points voulez-vous pour la polyline :", "Valeur invalide\n");
                    int x, y;
                    char points_str2[1024] = "";

                    for (int i = 0; i < p; i++) 
                    {
                        printf("Point %d :\n", i + 1);
                        x = ask_for_out("Coordonnee x :", "Valeur invalide");
                        y = ask_for_out("Coordonnee y :", "Valeur invalide");
                        char buff[50];
                        sprintf(buff, "%d, %d", x, y); // pour séparer les points
                        strcat(points_str2, buff);
                    }
                    fprintf(write_file, "<polyline fill='none' stroke= 'black' points='%s'/>\n", points_str2);
                    print_list(polygone);
                    shape = create_shape(SHAPE_POLYLINE, polygone);
                    free_polygone(polygone);
                }
                mylist = push_back_dlist(mylist, shape);
                print_dlist(mylist);
                printf("La taille de la liste est : %d\n", dlist_length(mylist));
            }
        }

        else if (menu == 2)
        {
            int suppression = 0;
            printf("Voulez-vous supprimer : \n 1. Supprimer le premier element de la liste \n 2. Supprimer le dernier element de la liste\n");
            scanf("%d", &suppression);
            if (suppression == 1)
            {
                mylist = pop_front_dlist(mylist);
            }
            else if (suppression == 2)
            {
                mylist = pop_back_dlist(mylist);
            }
        }

        else if (menu == 3)
        {
        }
        else if (menu == 4)
        {
            printf("Au revoir");
            fprintf(write_file, "</svg>\n");
            fclose(write_file);
            free_size_map(size_map);
            return 0;
        }
        print_dlist(mylist);
        printf("La taille de la liste est : %d\n", dlist_length(mylist));

    } while (menu);
}
