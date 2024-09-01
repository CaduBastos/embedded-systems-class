SOURCE = chardev.c 

OBJECT_NAME = $(patsubst %.c, %.o, $(SOURCE))	
MODULE_NAME = $(patsubst %.c, %.ko, $(SOURCE))	

MOD_OBJECT_NAME = $(patsubst %.c, %.mod.o, $(SOURCE))

obj-m += $(OBJECT_NAME)

all: 
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

install: 
	insmod $(MODULE_NAME)

uninstall:
	rmmod $(basename $(MODULE_NAME))

show:
	@dmesg | tail -n 3
	cat /dev/chardev

show_info:
	modinfo $(MODULE_NAME)

clean: 
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
	@rm -f *.o *.ko *.mod.* modules.order Module.symvers

distclean:clean	
	rm -f $(MODULE_NAME)