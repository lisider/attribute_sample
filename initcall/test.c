/*************************************************************************
  > File Name: t.c
  > Author: Sues
  > Mail: sumory.kaka@foxmail.com
  > Created Time: 2018年09月14日 星期五 16时03分41秒
 ************************************************************************/

#include <stdio.h>
#include <stdio.h>

typedef int (*initcall_t)(void); /*定义函数指针*/
extern initcall_t __initcall_start, __initcall_end; /*申明外部变量,在ld的脚本文件中定义*/

#define __initcall(fn)  static initcall_t __initcall_##fn __init_call = fn
#define __init_call     __attribute__ ((unused,__section__ ("function_ptrs")))
#define module_init(x) __initcall(x);
/*上述宏定义名为"__initcall_函数名"的函数指针,且将函数指针放在function_ptrs节
 *  这个函数指针，指向fn(fn函数则放在code_segment节中)*/

//#define __init __attribute__ ((__section__ ("code_segment")))
#define __init

static int __init  my_init1 (void) { /*函数放在code_segment节*/
    printf ("%s\n",__func__);
    return 0;
}

static int __init my_init2 (void) {
    printf ("%s\n",__func__);
    return 0;
}


module_init (my_init1);/*定义要被调用的函数指针并放到指定的节中*/
module_init (my_init2);

void do_initcalls (void) {

    initcall_t *call_p; //定义函数指针变量

    call_p = &__initcall_start;/*获取节首址*/
    do {
        fprintf (stderr, "call_p: %p\t", call_p);
        (*call_p)();
        ++call_p;/*32位机器上,函数指针占4bytes，增加一次就是指针便宜4bytes*/

    } while (call_p < &__initcall_end);

}

int main (void) {
    do_initcalls (); /*调用*/
    return 0;

}
