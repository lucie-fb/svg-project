#ifndef CLI
#define CLI

#include "shapes.h"

void clear_buffer();

/* =================================== */
//  Get single value
/* =================================== */

int ask_for_int(char *message, char *error_message);

int ask_for_out(char *message, char *error_message);

/* =================================== */
//  Create shapes
/* =================================== */

ellipse_t* generate_ellipse();

rectangle_t* generate_rectangle();

line_t* generate_line();

// void generate_shape();

/* =================================== */
//  Edit shapes
/* =================================== */




void edit_ellipse(ellipse_t *ellipse);

void edit_rectangle(rectangle_t *rectangle);

void edit_line(line_t *line);

void edit_shape();

#endif