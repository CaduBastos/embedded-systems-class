all: jupiter 
	
src/jupiter: src/main.c 
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ src/main.c 

check: all
	./jupiter | grep "Hello from .*jupiter!"
	@echo "*** ALL TESTS PASSED ***"

jupiter: main.c
	gcc -g -O0 -o $@ main.c

clean:
	-rm jupiter

.PHONY: all clean check
