#include <linux/init.h>
#include <linux/module.h>


MODULE_LICENSE("GPL");                             //*
MODULE_AUTHOR("Guntis");                           //!
MODULE_DESCRIPTION("Test loadable kernel module"); //!

static int test_module_init(void)
{
    printk("Hello world!!\n");
    return 0;
}

static void test_module_exit(void)
{
    printk("Godbye!!!\n");
}

module_init(test_module_init);
module_exit(test_module_exit);
