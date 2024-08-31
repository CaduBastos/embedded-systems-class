all: jupiter 
	
src/jupiter: src/main.c 
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ src/main.c 

check: all
	./jupiter | grep "Hello from .*jupiter!"
	@echo "*** ALL TESTS PASSED ***"

jupiter: main.c
	gcc -g -O0 -o $@ main.c

# $(prefix) is set in the top-level makefile
install: 
	install -d $(prefix)/bin
	install -m 0755 jupiter $(prefix)/bin

uninstall:
	rm -f $(prefix)/bin/jupiter
	-rmdir $(prefix)/bin > /dev/null 2>&1

clean:
	-rm jupiter

.PHONY: all clean check install uninstall
