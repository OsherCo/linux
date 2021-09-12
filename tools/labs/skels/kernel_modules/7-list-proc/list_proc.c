#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/sched/signal.h>

MODULE_DESCRIPTION("List current processes");
MODULE_AUTHOR("Kernel Hacker");
MODULE_LICENSE("GPL");

static int my_proc_init(void)
{
	struct task_struct *p;
	
	p = current;
	
	pr_info("CURR PID: %d\n", p->pid);
	pr_info("CURR NAME: %s\n", p->comm);
	
	for_each_process(p)
	{
		pr_info("PID: %d\n", p->pid);
		pr_info("NAME: %s\n", p->comm);
	}

	return 0;
}

static void my_proc_exit(void)
{
	struct task_struct *p;
	
	p = current;
	
	pr_info("CURR PID: %d\n", p->pid);
	pr_info("CURR NAME: %s\n", p->comm);
}

module_init(my_proc_init);
module_exit(my_proc_exit);
