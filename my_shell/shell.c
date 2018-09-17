/*************************************************************************
  > File Name: shell.c
  > Author: Sues
  > Mail: sumory.kaka@foxmail.com
  > Created Time: 2018年09月14日 星期五 15时22分02秒
 ************************************************************************/

#include <stdio.h>
#include <strings.h>
#include <string.h>
#include "cmd.h"
#include "parse.h"


int main(void){

    char name[16] = {0};

    while(1){
        printf(">");fflush(stdout);
        scanf("%s",name);getchar();
        parse(name)();
        bzero(name,sizeof(name));
    }
}
