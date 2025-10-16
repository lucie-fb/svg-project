#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct size_map_s {
    char *map;
} my_struct_t;





typedef struct polyline_s {
    
} polyline_t;

polyline_t *create_polyline() {
    polyline_t *polyline = malloc(sizeof(polyline_t));
    return polyline;
}

void free_polyline(polyline_t *polyline) {
    free(polyline);
}

typedef struct polygon_s {
} polygon_t;

polygon_t *create_polygon(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
    polygon_t *polygon = malloc(sizeof(polygon_t));
    polygon->x1 = x1;
    polygon->y1 = y1;
    polygon->x2 = x2;
    polygon->y2 = y2;
    polygon->x3 = x3;
    polygon->y3 = y3;
    polygon->x4 = x4;
    polygon->y4 = y4;
    return polygon;
}

void free_polygon(polygon_t *polygon) {
    free(polygon);
}

typedef struct trajectoire_s {
    
} trajectoire_t;

trajectoire_t *create_trajectoire() {
    trajectoire_t *trajectoire = malloc(sizeof(trajectoiret));
    return trajectoire;
}

void free_trajectoire(trajectoire_t *trajectoire) {
    free(trajectoire);
}

typedef struct groupe_s {
    
} groupe_t;

groupe_t *create_groupe() {
    groupe_t *groupe = malloc(sizeof(groupe_t));
    return groupe;
}

void free_groupe(groupe_t *groupe) {
    free(groupe);
}

int main () {

    size_map_t size_map = { 0, "Hello" };
    return 0;

    char forme_choisie[10] = "";

    printf("Quelle forme choisissez-vous ? \n");
    scanf("%s", &forme_choisie);

    if (strcmp(forme_choisie, "cercle") == 0){
        fprintf(append_file, cercle_t);
    } 
    else if (strcmp(forme_choisie, "rectangle") == 0) {
        fprintf(append_file, rectangle_t);
    }

    fclose(write_file);

    FILE* read_file = fopen("test.svg", "r"); 

    return 0;*/

}