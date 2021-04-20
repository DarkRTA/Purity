#include <math.h>
#include "color.h"
#include <hsluv/hsluv.h>

int INVERT = 0;

struct Hue RED = {
	.h = 12,
	.s = 100,
	.lb = 56,
	.ld = 21,
};

struct Hue ORANGE = {
	.h = 30,
	.s = 100,
	.lb = 65,
	.ld = 25,
};

struct Hue YELLOW = {
	.h = 85.9,
	.s = 100,
	.lb = 80,
	.ld = 35,
};

struct Hue GREEN = {
	.h = 127.7,
	.s = 85,
	.lb = 75,
	.ld = 35,
};

struct Hue CYAN = {
	.h = 225,
	.s = 100,
	.lb = 75,
	.ld = 30,
};

struct Hue BLUE = {
	.h = 253,
	.s = 100,
	.lb = 65,
	.ld = 35,
};

struct Hue MAGENTA = {
	.h = 307.7,
	.s = 100,
	.lb = 61.6,
	.ld = 25,
};

struct Hue VIOLET = {
	.h = 280,
	.s = 100,
	.lb = 58,
	.ld = 25,
};

struct Color Color_get_gray_shade(char shade)
{
	double shade_map[] = { 3, 11, 20, 50, 60, 78, 83, 87 };
	double lightness = INVERT ? 87 - shade_map[shade] : shade_map[shade];

	struct Color ret;
	hsluv2rgb(240, 25, lightness, &ret.r, &ret.g, &ret.b);
	return ret;
}

struct Color Color_get_hue_shade(struct Hue hue, char shade)
{
	double l = INVERT ? hue.ld : hue.lb;

	struct Color ret;
	hsluv2rgb(hue.h, hue.s, l, &ret.r, &ret.g, &ret.b);
	return ret;
}

int Color_to_int(struct Color color)
{
	int ret = 0;
	ret |= ((int)round(color.r * 255) & 0xFF) << 16;
	ret |= ((int)round(color.g * 255) & 0xFF) << 8;
	ret |= ((int)round(color.b * 255) & 0xFF);
	return ret;
}
