MODULE_SRC=hello-world.c

# remove the .c extension using make file manipulation
MODULE_NAME=$(basename $(MODULE_SRC)).ko
MODULE_OBJ=$(basename $(MODULE_SRC)).o

all: 
	make -C /lib/modules/`uname -r`/build M=$(PWD) modules

obj-m += $(MODULE_OBJ)

install: 
	insmod $(MODULE_NAME)
	dmesg | tail -n 2

uninstall:
	rmmod $(MODULE_NAME)
	dmesg | tail -n 2

show:
	dmesg | tail

clean: 
	@rm -f *.o *.ko *.mod.* modules.order Module.symvers
