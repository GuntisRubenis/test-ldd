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
                                loff_t *offset){
    printk("->test_read entry\n");
    char msg[] = "Ack\n";
    size_t len = sizeof(msg);
    int result;

    if(*offset >= len){
        return 0;
    }
    
    result = copy_to_user(user_space_buffer, msg, len);
    
    *offset += len;

    printk("Message len %d:\n",len);
    printk("->test_read exit\n");
    return len;
}

ssize_t	test_write(struct file * file_pointer, 
                    const char __user *user_space_buffer, 
                    size_t count, 
                    loff_t *offset){
    printk("->test_write entry\n");
    printk("->test_write exit\n");

    return 0;

};
struct proc_ops driver_proc_ops = {
    .proc_read = test_read
    //.proc_write = test_write
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
