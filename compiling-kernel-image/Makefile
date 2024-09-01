MODULE_SRC=hello-world.c

# removes the .c extension using make file manipulation

MODULE_NAME=${basename ${MODULE_SRC}}.ko
MODULE_OBJ=${basename ${MODULE_SRC}}.o

all: 
	make -C /lib/modules/'uname -r /build M='pwd'

obj-m+=${MODULE_OBJ}

install: 
	insmod ${MODULE_NAME}
	dmesg | tail -n 2

uninstall:
	rmmod ${MODULE_NAME}
	dmesg | tail -n 2

show:
	dmesg | tail

clean: 
	@rm modules.order Modules.symvers *.o

	

