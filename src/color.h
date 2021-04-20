#pragma once
#include <stddef.h>

struct Color {
	double r;
	double g;
	double b;
};

struct Hue {
	double h;
	double s;
	double lb;
	double ld;
};

extern int INVERT;

extern struct Hue RED;
extern struct Hue ORANGE;
extern struct Hue YELLOW;
extern struct Hue GREEN;
extern struct Hue CYAN;
extern struct Hue BLUE;
extern struct Hue MAGENTA;
extern struct Hue VIOLET;

struct Color Color_get_gray_shade(char shade);
struct Color Color_get_hue_shade(struct Hue hue, char shade);
int Color_to_int(struct Color);
