#makefile

#generate assembler file from c file
assembler: main.c
	gcc -S main.c

#generate an object from c file
objects: main.c 
	gcc -c main.c

#show informations about main.o
show-objs: objects
	objdump -x main.o 

#generate the executable file from objects
make exec: objects
	gcc -o main main.o 

#execute the executable file
make run: exec
	./main
	
#clean files created by this makefile
clean:
	rm main.s main.o main  