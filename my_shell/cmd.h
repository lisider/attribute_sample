/*************************************************************************
  > File Name: cmd.h
  > Author: Sues
  > Mail: sumory.kaka@foxmail.com 
  > Created Time: 2018年09月14日 星期五 17时34分23秒
 ************************************************************************/


#ifndef __CMD_H__
#define __CMD_H__

extern struct cmd __initcall_start, __initcall_end;

typedef void(*fun_t)(void);

struct cmd{
    char name[16];
    fun_t fun;
};

#define TO_STRING(name) #name
#define FUN_NAME(name) name##_fun

#define CMD(name) \
    static void FUN_NAME(name)(void);\
    static struct cmd name __attribute__((section("data_ptrs"))) = {\
        TO_STRING(name),\
        FUN_NAME(name),\
    };\
   static void FUN_NAME(name)(void)

#endif
