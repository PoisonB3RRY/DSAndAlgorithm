#include <stdio.h>
#include <stdlib.h>
#include "status.h"

void main()
{
    FILE *fp;
    int c;
    fp = fopen("stdio.h","r");

    if(fp == NULL){
        printf("Can't open stdio.h \n");
        exit(1);
    }
    while(1)
    {
       c = fgetc(fp);
       if(feof(fp))
       {
           break;
       }
       printf("%c",c);
    }
}
