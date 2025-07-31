#include <linux/init.h>
#include <linux/module.h>
#include <linux/proc_fs.h>


MODULE_LICENSE("GPL");                             //*
MODULE_AUTHOR("Guntis");                           //!
MODULE_DESCRIPTION("Test loadable kernel module"); //!

static struct proc_dir_entry *custom_proc_node;

static ssize_t test_read(struct file *file_pointer, 
                                char __user *user_space_buffer, 
                                size_t count, 
                                loff_t *ofset){
    printk("->test_read entry\n");
    printk("->test_read entry\n");
    return 0;
}
struct proc_ops driver_proc_ops = {
    .proc_read = test_read
};

static int test_module_init(void)
{
    printk("->test_module_init entry\n");

    custom_proc_node =  proc_create("test_driver", 0, NULL, &driver_proc_ops);
    
    printk("->test_module_init exit\n");
    return 0;
}

static void test_module_exit(void)
{
    printk("->test_module_exit start\n");

    proc_remove(custom_proc_node);
    
    printk("->test_module_exit end\n");
}



module_init(test_module_init);
module_exit(test_module_exit);
