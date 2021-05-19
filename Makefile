CC      := cc
CFLAGS  := -Isrc -Ideps -I. -MMD -g -O2
LDFLAGS := -lm

OBJ = $(patsubst %.c,obj/%.o,$(shell find src deps -type f -name *.c))
DEPS = $(patsubst %.o,%.d,$(OBJ))

.PHONY: clean all tags
.SUFFIXES:

S=@

all: purity

clean: 
	@rm -rfv obj purity

tags:
	@ctags --totals=yes --c-kinds=+defghlmpstuvxz -R \
		src/** \
		deps/**

obj/%.o: %.c obj/%.d
	@echo "CC   "$<
	@mkdir -p $(shell dirname $@)
	$S$(CC) -c -o $@ $< $(CFLAGS)

$(DEPS):

include $(DEPS)

purity: $(OBJ)
	@echo "LINK "$@
	$S$(CC) -o $@ $(OBJ) $(LDFLAGS)
