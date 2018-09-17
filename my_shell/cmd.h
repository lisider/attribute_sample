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

#endif
