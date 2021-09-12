#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/sched/signal.h>
/* TODO: add missing headers */

MODULE_DESCRIPTION("List current processes");
MODULE_AUTHOR("Kernel Hacker");
MODULE_LICENSE("GPL");

static int my_proc_init(void)
{
	struct task_struct *p;
	
	p = current;
	
	pr_info("PID: %d\n", (*p).pid);
	pr_info("NAME: %s\n", (*p).comm);
	/* TODO: print current process pid and its name */

	/* TODO: print the pid and name of all processes */

	return 0;
}

static void my_proc_exit(void)
{
	struct task_struct *p;
	
	p = current;
	
	pr_info("PID: %d\n", (*p).pid);
	pr_info("NAME: %s\n", (*p).comm);
	/* TODO: print current process pid and name */
}

module_init(my_proc_init);
module_exit(my_proc_exit);
