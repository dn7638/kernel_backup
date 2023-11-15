#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>

int __init hello_module_init(void)
{
	printk("Hello Module!\n");
	return 0;
}

void __exit hello_module_cleanup(void)
{
	printk("Bye Module!\n");
}

static int work_fn(void *data){
	int original;

	while(!kthread_shoult_stop()){
	
	printk(KERN_INFO "pid[%u] %s: counter: %d\n",
		current->pid, __func__, original);
	msleep(500);
	}
	do_exit(0);
}

module_init(hello_module_init);
module_exit(hello_module_cleanup);
MODULE_LICENSE("GPL");
