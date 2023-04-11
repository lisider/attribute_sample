/*************************************************************************
  > File Name: shell.c
  > Author: Sues
  > Mail: sumory.kaka@foxmail.com
  > Created Time: 2018年09月14日 星期五 15时22分02秒
 ************************************************************************/

#include <stdio.h>
#include <strings.h>
#include <string.h>
#include "parse.h"
#include "cmd.h"


#define CNTLQ       0x11
#define CNTLS       0x13
#define DEL         0x7F
#define BACKSPACE   0x08
#define TAB         0x09
#define LF          0x0A
#define CR          0x0D
#define ESC         0x1B

#define ARGC_MAX 4
#define PROMPT "suws@ls:~# "
#define INTRO \
"********************\n" \
"****LITTLE  SHELL****\n" \
"********************\n"
#define CMDLINE_BUF		256
static char oldcmd[CMDLINE_BUF];
static char *get_entry (char *cp, char **pNext) {
    char *sp, lfn = 0, sep_ch = ' ';
    if (cp == NULL) {                          /* skip NULL pointers          */
        *pNext = cp;
        return (cp);
    }
    for ( ; *cp == ' ' || *cp == '\"'; cp++) { /* skip blanks and starting  " */
        if (*cp == '\"') { sep_ch = '\"'; lfn = 1; }
        *cp = 0;
    }
    for (sp = cp; *sp != CR && *sp != LF; sp++) {
        if ( lfn && *sp == '\"') break;
        if (!lfn && *sp == ' ' ) break;
    }
    for ( ; *sp == sep_ch || *sp == CR || *sp == LF; sp++) {
        *sp = 0;
        if ( lfn && *sp == sep_ch) { sp ++; break; }
    }
    *pNext = (*sp) ? sp : NULL;                /* next entry                  */
    return (cp);
}

int main(void)
{
    char *sp,*next,*before;
    int argc = 0;
    char argv[ARGC_MAX][ARGV_LEN_MAX]={0};
    printf (INTRO);
    while (1) {
        argc = 0;
        printf (PROMPT);
        if (fgets(oldcmd,sizeof (oldcmd),stdin) == NULL){
            continue;
        }

        before = &oldcmd[0];
        sp = get_entry (before, &next);
        if (*sp == 0) { // enter only
            continue;
        }
        strncpy(argv[0],sp,ARGV_LEN_MAX);
        argc ++;

        while(next){    // have parameter
            before = next;
            sp = get_entry (before, &next);
            strncpy(argv[argc],sp,ARGV_LEN_MAX);
            if (++argc == ARGC_MAX)
                break;
        }

        parse(argv[0])(argc,argv);

    }
    return 0;
}

