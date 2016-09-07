LIBS="-lm"
FILES=$(shell find . -name '*.c')
OBJECTS=$(shell find . -name '*.c' | sed -e 's/".c"/".o"/g')
EXEC="teste"
bindir="$(shell echo $(HOME))/binario/"
all: objects $(EXEC)
.PHONY: uninstall install clean mrproper reinstall help
help:
	echo "reinstall, install, uninstall, clean, mrproper"
reinstall: uninstall install
uninstall:
	rm -r $(bindir)
install: all
	mkdir $(bindir)
	cp $(EXEC) $(bindir)
$(EXEC): $(OBJECTS)
	gcc -o $@ $^ $(LIBS)
objects: $(FILES)
	gcc -c $^ $(LIBS)
clean:
	rm *.o
mrproper: clean
	rm teste

