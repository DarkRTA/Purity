#include "exporters.h"
#include <stdio.h>
#include "color.h"
#include "purity.h"

struct Exporter EXPORTERS[] = {
	{ .name = "base16", .ext = "yaml", .fn = export_base16 },
	{ .name = "text", .ext = "txt", .fn = export_text },
	{ .name = "css", .ext = "css", .fn = export_css },
	{ NULL, NULL, NULL },
};

void export_base16(FILE *f, char *name)
{
	fprintf(f, "author: \"%s\"\n", AUTHOR);
	fprintf(f, "scheme: \"%s\"\n", name);
	fprintf(f, "base00: \"%06x\"\n", Color_to_int(Color_get_gray_shade(0)));
	fprintf(f, "base01: \"%06x\"\n", Color_to_int(Color_get_gray_shade(1)));
	fprintf(f, "base02: \"%06x\"\n", Color_to_int(Color_get_gray_shade(2)));
	fprintf(f, "base03: \"%06x\"\n", Color_to_int(Color_get_gray_shade(3)));
	fprintf(f, "base04: \"%06x\"\n", Color_to_int(Color_get_gray_shade(4)));
	fprintf(f, "base05: \"%06x\"\n", Color_to_int(Color_get_gray_shade(5)));
	fprintf(f, "base06: \"%06x\"\n", Color_to_int(Color_get_gray_shade(6)));
	fprintf(f, "base07: \"%06x\"\n", Color_to_int(Color_get_gray_shade(7)));
	fprintf(f, "base08: \"%06x\"\n", Color_to_int(Color_get_hue_shade(RED, 0)));
	fprintf(f, "base09: \"%06x\"\n", Color_to_int(Color_get_hue_shade(BLUE, 0)));
	fprintf(f, "base0A: \"%06x\"\n", Color_to_int(Color_get_hue_shade(BLUE, 0)));
	fprintf(
		f,
		"base0B: \"%06x\"\n",
		Color_to_int(Color_get_hue_shade(GREEN, 0)));
	fprintf(f, "base0C: \"%06x\"\n", Color_to_int(Color_get_hue_shade(BLUE, 0)));
	fprintf(f, "base0D: \"%06x\"\n", Color_to_int(Color_get_hue_shade(CYAN, 0)));

	fprintf(
		f,
		"base0E: \"%06x\"\n",
		Color_to_int(Color_get_hue_shade(ORANGE, 0)));
	fprintf(f, "base0F: \"%06x\"\n", Color_to_int(Color_get_hue_shade(BLUE, 0)));
}

void export_text(FILE *f, char *name)
{
	fputs("-- Background/Forground Shades --\n", f);
	fprintf(f, "0: #%06x\n", Color_to_int(Color_get_gray_shade(0)));
	fprintf(f, "1: #%06x\n", Color_to_int(Color_get_gray_shade(1)));
	fprintf(f, "2: #%06x\n", Color_to_int(Color_get_gray_shade(2)));
	fprintf(f, "3: #%06x\n", Color_to_int(Color_get_gray_shade(3)));
	fprintf(f, "4: #%06x\n", Color_to_int(Color_get_gray_shade(4)));
	fprintf(f, "5: #%06x\n", Color_to_int(Color_get_gray_shade(5)));
	fprintf(f, "6: #%06x\n", Color_to_int(Color_get_gray_shade(6)));
	fprintf(f, "7: #%06x\n", Color_to_int(Color_get_gray_shade(7)));
	fputs("-- Color Pallete --\n", f);
	fprintf(f, "Red:      #%06x\n", Color_to_int(Color_get_hue_shade(RED, 0)));
	fprintf(f, "Blue:     #%06x\n", Color_to_int(Color_get_hue_shade(BLUE, 0)));
	fprintf(f, "Green:    #%06x\n", Color_to_int(Color_get_hue_shade(GREEN, 0)));
	fprintf(
		f,
		"Yellow:   #%06x\n",
		Color_to_int(Color_get_hue_shade(YELLOW, 0)));
	fprintf(
		f,
		"Orange:   #%06x\n",
		Color_to_int(Color_get_hue_shade(ORANGE, 0)));
	fprintf(f, "Cyan:     #%06x\n", Color_to_int(Color_get_hue_shade(CYAN, 0)));
	fprintf(
		f,
		"Magenta:  #%06x\n",
		Color_to_int(Color_get_hue_shade(MAGENTA, 0)));
	fprintf(
		f,
		"Violet:   #%06x\n",
		Color_to_int(Color_get_hue_shade(VIOLET, 0)));
}

void export_css(FILE *f, char *name)
{
	fputs(":root {\n", f);
	fprintf(
		f,
		"--purity-gray-0: #%06x;\n",
		Color_to_int(Color_get_gray_shade(0)));
	fprintf(
		f,
		"--purity-gray-1: #%06x;\n",
		Color_to_int(Color_get_gray_shade(1)));
	fprintf(
		f,
		"--purity-gray-2: #%06x;\n",
		Color_to_int(Color_get_gray_shade(2)));
	fprintf(
		f,
		"--purity-gray-3: #%06x;\n",
		Color_to_int(Color_get_gray_shade(3)));
	fprintf(
		f,
		"--purity-gray-4: #%06x;\n",
		Color_to_int(Color_get_gray_shade(4)));
	fprintf(
		f,
		"--purity-gray-5: #%06x;\n",
		Color_to_int(Color_get_gray_shade(5)));
	fprintf(
		f,
		"--purity-gray-6: #%06x;\n",
		Color_to_int(Color_get_gray_shade(6)));
	fprintf(
		f,
		"--purity-gray-7: #%06x;\n",
		Color_to_int(Color_get_gray_shade(7)));
	fprintf(
		f,
		"--purity-red: #%06x;\n",
		Color_to_int(Color_get_hue_shade(RED, 0)));
	fprintf(
		f,
		"--purity-blue: #%06x;\n",
		Color_to_int(Color_get_hue_shade(BLUE, 0)));
	fprintf(
		f,
		"--purity-green: #%06x;\n",
		Color_to_int(Color_get_hue_shade(GREEN, 0)));
	fprintf(
		f,
		"--purity-yellow: #%06x;\n",
		Color_to_int(Color_get_hue_shade(YELLOW, 0)));
	fprintf(
		f,
		"--purity-magenta: #%06x;\n",
		Color_to_int(Color_get_hue_shade(MAGENTA, 0)));
	fprintf(
		f,
		"--purity-cyan: #%06x;\n",
		Color_to_int(Color_get_hue_shade(CYAN, 0)));
	fprintf(
		f,
		"--purity-orange: #%06x;\n",
		Color_to_int(Color_get_hue_shade(ORANGE, 0)));
	fprintf(
		f,
		"--purity-violet: #%06x;\n",
		Color_to_int(Color_get_hue_shade(VIOLET, 0)));
	fputs("}", f);
}
