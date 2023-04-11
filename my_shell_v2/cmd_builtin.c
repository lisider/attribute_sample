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

    return 0;
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

    return 0;
}




CMD(quit){
    exit(0);
}


CMD(wr32){
    if (argc != 3) return -1;
    unsigned long long virt_addr = strtoull(argv[1],NULL,16);
    unsigned int value = strtoul(argv[2],NULL,16);
    *((volatile unsigned int *)virt_addr) = value;
    printf("W 0X%016llX:0X%08X\n",virt_addr,value);
    return 0;
}

CMD(rd32){
    if (argc != 2) return -1;
    unsigned long long virt_addr = strtoull(argv[1],NULL,16);
    printf("R 0X%016llX:0X%08X\n",virt_addr,*((volatile unsigned int *)virt_addr));
    return 0;
}


//-------------------------------------------------------------

CMD(new){
    printf("%s\n",__func__);
    int i = 0;
    for(; i< argc ; i++){
        printf("Argument %d is %s\n", i, argv[i]);
    }
    return 0;
}
