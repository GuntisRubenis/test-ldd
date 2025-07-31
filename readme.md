# Kernel Operations

## Load Module into Kernel
-   `sudo insmod ldd.ko`
## Print Kernel Messages
-   `sudo dmesg -c` (to clear log message)
## Remove Module
-   `sudo rmmod ldd`
## Print Module Info
-   `modinfo ldd.ko`
## Check Last Command
-   `sudo $?`
## List Modules
-   `sudo lsmod`
## Man Pages
-   `man lsmod`

## virtual files
- ls /proc/

# `insmod` Module Loading Process

1.  Calls `init_module` to hint the kernel that a module insertion is attempted.
2.  Transfers control to kernel.
3.  Kernel executes `sys_init_module`.
4.  Verifies permissions.
5.  `load_module` function is called:
    1.  Checks the sanity of the `.ko` file.
    2.  Creates memory.
    3.  Copies from user space to kernel space.
    4.  Resolves symbols.
    5.  Returns a reference to the Kernel.
6.  Adds the reference to a linked list that has all the loaded modules.
7.  `module_init` function is executed.