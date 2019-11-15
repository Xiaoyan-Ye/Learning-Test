/* @File Brief : Button detection file */

#include<stdio.h>
#include<stdlib.h>

#include "button.h"

#define Button_on     0
#define Button_off    1

int getbutton(void)
{
    char Button;
    FILE *fp;
    if((fp = fopen("button.txt","r"))==NULL)
    {
        printf("cannot open file strike any key exit");
        getch();
        exit(1);       
    }
    else{}
    Button = fgetc(fp);
   // printf("Button is %c\n",Button);
    fclose(fp);
    if(Button == '0')
    {
      //  printf("return 0");
        return Button_on;
        }
    else if(Button == '1')
    {
       // printf("return 1");
        return Button_off;
    }
    else
    {
        printf("error input,please input the correct number\n 0 means the button is pressed, and 1 means the button is released\n");
        printf("strike any key exit\n");
        getch();
        exit(1); 
    }
    
}