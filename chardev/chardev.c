/* chardev.c: Creates a read-only char device that says how many times 
 * you have read from the dev file
 */

#include <linux/atomic.h>
#include <linux/cdev.h>
#include <linux/delay.h>
#include <linux/device.h>
#include <linux/fs.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/printk.h>
#include <linux/types.h>
#include <linux/uaccess.h>

#include <asm/errno.h>

/* Prototypes - this would normally go in a .h file */
static int device_open(struct inode *, struct file *);
static int device_release(struct inode *, struct file *);
static ssize_t device_read(struct file *, char __user *, size_t, loff_t *);
static ssize_t device_write(struct file *, const char __user *, size_t, loff_t *);

#define SUCCESS 0
#define DEVICE_NAME "chardev" // Dev name as it appears in /proc/devices
#define BUF_LEN 80 // Max lenght of the message from the device

static int major; // Major number assigned to our device driver

static char *msg_ptr;

enum {
    CDEV_NOT_USED = 0,
    CDEV_EXCLUSIVE_OPEN = 1,
};

// Is the device open? Used to prevent multiple acces to device
static atomic_t already_open = ATOMIC_INIT(CDEV_NOT_USED);

static char msg[BUF_LEN + 1]; // The message the device will give when asked

static struct class *cls;

static struct file_operations chardev_fops = {
    .read = device_read,
    .write = device_write,
    .open = device_open,
    .release = device_release,
};

static int __init chardev_init(void){
   
    major = register_chrdev(0, DEVICE_NAME, &chardev_fops);

    if(major < 0){
        pr_alert("Registering char device failed with %d\n", major);
        return major;
    }

    pr_info("I was assigned major number %d. \n", major);

    cls = class_create(DEVICE_NAME);
    device_create(cls, NULL, MKDEV(major, 0), NULL, DEVICE_NAME);

    pr_info("Device created on /dev/%s\n", DEVICE_NAME);

    return SUCCESS;
}

static void __exit chardev_exit(void){

    device_destroy(cls, MKDEV(major, 0));
    class_destroy(cls);

    // Unregister the device
    unregister_chrdev(major, DEVICE_NAME);
}

// Methods

// Called when a process tries to open the device file, like "sudo cat /dev/chardev"

static int device_open(struct inode *inode, struct file *file){

    msg_ptr = msg;

    static int counter = 0; 

    if(atomic_cmpxchg(&already_open, CDEV_NOT_USED, CDEV_EXCLUSIVE_OPEN))
        return -EBUSY;

    sprintf(msg, "I already told you %d times Hello world!\n", counter ++);
    try_module_get(THIS_MODULE);
    return SUCCESS;
}

// Called when a process closes the device file
static int device_release(struct inode *inode, struct file * file){

    // We're now ready for our next caller
    atomic_set(&already_open, CDEV_NOT_USED);

    // Decrement the usage count, or else once you opened the file, you will never get rid of the module
    module_put(THIS_MODULE);
    return SUCCESS;
}

// Called when a process, which already opened the dev file, attempts to read from it
static ssize_t device_read(struct file *filp,
                            char __user *buffer, // buffer to fill with data
                            size_t length, // length of the buffer
                            loff_t *offset)
{
    // Number of bytes actually written to the buffer
    int bytes_read = 0;

    if(!*(msg_ptr + *offset)){ // we are at the end of the message
        *offset = 0; // reset the offset
        return 0;
    }

    msg_ptr += *offset;

    // Actually put the data into the buffer
    while(length && *msg_ptr){
        put_user(*(msg_ptr++), buffer++);
        length--;
        bytes_read++;
    }
    *offset += bytes_read;
    return bytes_read;
}

// Called when a process writes to dev file: echo "hi" > /dev/hello
static ssize_t device_write(struct file *filp, const char __user *buff, 
                            size_t len, loff_t *off)
{
    pr_alert("Sorry, this operation is not supported. \n");
    return -EINVAL;
}

module_init(chardev_init);
module_exit(chardev_exit);

MODULE_LICENSE("GPL");