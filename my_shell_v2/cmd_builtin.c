/*************************************************************************
  > File Name: cmds.c
  > Author: Sues
  > Mail: sumory.kaka@foxmail.com
  > Created Time: 2018年09月14日 星期五 15时38分42秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "cmd.h"

//#define __init __attribute__ ((__section__ ("data_segment")))
//struct cmd  hello  __attribute__((section("function_ptrs"))) __attribute__((aligned(32))) = {
//struct cmd  hello  __attribute__((section("function_ptrs"))) __attribute__((align))  = {
//struct cmd  hello  __attribute__((section("function_ptrs")))  = {


CMD(help){

    struct cmd *p = NULL;
    char * tmp = NULL;
    int count = 0;

    p = &__cmd_start;
    do {
        printf("%2d : %s\n",count+1,p->name);
        tmp = (char *)p;
        tmp +=32;  //手动对齐
        p= (struct cmd *)tmp;
        count ++;
    } while (p < &__cmd_end);

    if(p >= &__cmd_end)
        printf("total : %d\n",count);
}



CMD(ct){

    struct cmd *p = NULL;
    char * tmp = NULL;
    int count = 0;

    p = &__cmd_start;
    do {
        tmp = (char *)p;
        tmp +=32;  //手动对齐
        p= (struct cmd *)tmp;
        count ++;
    } while (p < &__cmd_end);

    if(p >= &__cmd_end)
        printf("%d\n",count);
}




CMD(quit){
    exit(0);
}



//-------------------------------------------------------------

CMD(new){
    printf("%s\n",__func__);
    int i = 0;
    for(; i< argc ; i++){
        printf("Argument %d is %s\n", i, argv[i]);
    }
}
