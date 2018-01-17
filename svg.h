
#ifndef SVG_H
#define SVG_H

#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<math.h>

#define prl { printf("\n"); }

typedef struct color_s{
	double r;
	double g;
	double b;
	char c;
}color_t;

typedef struct coord_s{
    double x;
    double y;
}coord_t;

typedef struct circle_s{
    double r;
}circle_t;

typedef struct rectangle_s{
    double w; // demie longueur
    double h; // demie hauteur
}rectangle_t;

typedef struct line_s{
     double l; // demie longueur
}line_t;

typedef struct photo_s{
    char     *name;
}photo_t;

typedef struct text_s{
    char     *name;

}text_t;

typedef struct	figure_s{
    color_t color;
    coord_t centre;
    double angle;
    enum {
        RIEN,
        CERCLE,
        RECTANGLE,
        LIGNE,
        PHOTO,
        GROUPE
    } type;
    union {
      circle_t cercle;
      rectangle_t rectangle;
      line_t line;
      text_t text;
    	photo_t photo;
    };
}figure_t;

typedef struct	image_s
{
	unsigned int w; //width
	unsigned int h; //height
	double g;
	figure_t**	tab;
	unsigned	size;
}image_t;

//**********************prototype**********************
void print_coord(coord_t c);
coord_t coordinate(double x, double y);
coord_t inv_translate_point(coord_t p, coord_t v);
coord_t inv_rotate_point(coord_t p, double t);
figure_t circle(double radius);
figure_t rectangle(double width, double height);
figure_t line(double length);
figure_t color(figure_t f, char c);
figure_t translate(figure_t f, double dx, double dy);
figure_t rotate(figure_t f, double dt);
char intersect(coord_t p, figure_t f, double grain);


#endif
