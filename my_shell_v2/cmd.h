/*************************************************************************
  > File Name: cmd.h
  > Author: Sues
  > Mail: sumory.kaka@foxmail.com 
  > Created Time: 2018年09月14日 星期五 17时34分23秒
 ************************************************************************/


#ifndef __CMD_H__
#define __CMD_H__

#define ARGV_LEN_MAX 32
typedef char argv_t[ARGV_LEN_MAX];

extern struct cmd __cmd_start, __cmd_end;

typedef int(*fun_t)(int argc, argv_t * argv);

struct cmd{
    char name[16];
    fun_t fun;
};

#define TO_STRING(name) #name
#define FUN_NAME(name) name##_fun

#define CMD(name) \
    static int FUN_NAME(name)(int argc, argv_t * argv);\
    static struct cmd name __attribute__((section("dcmd"))) = {\
        TO_STRING(name),\
        FUN_NAME(name),\
    };\
   static int FUN_NAME(name)(int argc, argv_t * argv)

#endif
