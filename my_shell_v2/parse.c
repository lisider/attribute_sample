/*************************************************************************
  > File Name: parse.c
  > Author: Sues
  > Mail: sumory.kaka@foxmail.com
  > Created Time: 2018年09月14日 星期五 15时28分25秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include "cmd.h"


void not_find(int argc, argv_t * argv){
    printf("%s: command not found\n",argv[0]);
}


fun_t parse(const char * name){

    struct cmd *p = NULL;
    char * tmp = NULL;

    p = &__cmd_start;
    do {
        if(strcmp(p->name,name) == 0){
            return p->fun;
        }else{
            tmp = (char *)p;
            tmp +=32;  //手动对齐
            p= (struct cmd *)tmp;
        }
    } while (p < &__cmd_end);

    if(p >= &__cmd_end)
        return not_find;

}


