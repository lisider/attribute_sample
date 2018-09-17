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


void help_fun(void){

    struct cmd *p = NULL;
    char * tmp = NULL;
    int count = 0;

    p = &__initcall_start;
    do {
        printf("%2d : %s\n",count+1,p->name);
        tmp = (char *)p;
        tmp +=32;  //手动对齐
        p= (struct cmd *)tmp;
        count ++;
    } while (p < &__initcall_end);

    if(p >= &__initcall_end)
        printf("total : %d\n",count);
}
struct cmd  help_count  __attribute__((section("data_ptrs"))) = {
    "help",
    help_fun,
};



void ct_fun(void){

    struct cmd *p = NULL;
    char * tmp = NULL;
    int count = 0;

    p = &__initcall_start;
    do {
        tmp = (char *)p;
        tmp +=32;  //手动对齐
        p= (struct cmd *)tmp;
        count ++;
    } while (p < &__initcall_end);

    if(p >= &__initcall_end)
        printf("%d\n",count);
}
struct cmd  cmd_count  __attribute__((section("data_ptrs"))) = {
    "ct",
    ct_fun,
};




void quit_fun(void){
    exit(0);
}
struct cmd  quit  __attribute__((section("data_ptrs"))) = {
    "quit",
    quit_fun,
};



//-------------------------------------------------------------


void new_fun(void){
    printf("%s\n",__func__);
}
struct cmd  new  __attribute__((section("data_ptrs"))) = {
    "new",
    new_fun,
};
