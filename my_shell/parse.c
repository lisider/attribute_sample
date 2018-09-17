/*************************************************************************
  > File Name: parse.c
  > Author: Sues
  > Mail: sumory.kaka@foxmail.com
  > Created Time: 2018年09月14日 星期五 15时28分25秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include "cmd.h"




void not_find(void){
    printf("command not found\n");
}


fun_t parse(char * name){

    struct cmd *p = NULL;
    char * tmp = NULL;

    p = &__initcall_start;
    do {
        if(strcmp(p->name,name) == 0){
            return p->fun;
        }else{
            tmp = (char *)p;
            tmp +=32;  //手动对齐
            p= (struct cmd *)tmp;
        }
    } while (p < &__initcall_end);

    if(p >= &__initcall_end)
        return not_find;

}


