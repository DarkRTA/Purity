#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include "color.h"
#include "exporters.h"

int main(int argc, char **argv)
{
	mkdir("./dist", S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
	for (struct Exporter *out = EXPORTERS; out->name != NULL; out++) {
		char *dir;
		asprintf(&dir, "./dist/%s/", out->name);
		mkdir(dir, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
		free(dir);
	}
	for (struct Exporter *out = EXPORTERS; out->name != NULL; out++) {
		char *file;
		asprintf(&file, "./dist/%s/purity-void.%s", out->name, out->ext);
		FILE *f = fopen(file, "w+");
		out->fn(f, "Purity Void");
		free(file);
		fclose(f);
	}
	INVERT = 1;
	for (struct Exporter *out = EXPORTERS; out->name != NULL; out++) {
		char *file;
		asprintf(&file, "./dist/%s/purity-mass.%s", out->name, out->ext);
		FILE *f = fopen(file, "w+");
		out->fn(f, "Purity Mass");
		free(file);
		fclose(f);
	}
}
