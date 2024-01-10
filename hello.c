#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

static int __init hello_init(void)
{
        int *a;
	printk(KERN_INFO "Hello, world\n");

	pr_debug("Hello, dynamic world\n");

        a = (int *) 0x00001234;
#ifdef OOPS_WRITE
        *a = 3;
#endif
#ifdef OOPS_READ
        printk (KERN_ALERT "value = %d\n", *a);
#endif

	return 0;
}

static void __exit hello_exit(void)
{
	printk(KERN_INFO "Goodbye, cruel world\n");
	pr_debug("Goodbye, dynamic world\n");
}

module_init(hello_init);
module_exit(hello_exit);

MODULE_DESCRIPTION("Hello world module");
MODULE_LICENSE("GPL");
