#pragma once
#include <stdio.h>

struct Exporter {
	char *name;
	char *ext;
	void (*fn)(FILE *F, char *name);
};

void export_base16(FILE *f, char *name);
void export_text(FILE *f, char *name);

extern struct Exporter EXPORTERS[];
