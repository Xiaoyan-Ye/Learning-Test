/* @File Brief : Task implementation file */\
#include<stdio.h>
#include"task.h"
#include "..\button\button.h"
#include "..\main.h"


void all_red(void)
{
    if(getbutton())
    {
        printf("All red \n");
        updateled_state(state_1);
        updatemachine_state(state_2);
        Time(5);
    }
    else
    { 
        updatemachine_state(state_1);
    } 
           
}

void road1_green(void)
{
    printf("road1_green,road2_red \n");
    updateled_state(state_2);
    updatemachine_state(state_3);
    Time(10);
}

void road1_perred(void)
{
    printf("road1_yellow,road2_red \n");
    updateled_state(state_3);
    Time(3);
    if(getbutton())
    {
      updatemachine_state(state_4);
    }
    else
    {
      updatemachine_state(state_1);
    }
}

void road2_green(void)
{
    printf("road1_red,road2_green \n");
    updateled_state(state_4);
    updatemachine_state(state_5);
    Time(10);
    
}

void road2_perred(void)
{
    printf("road1_red,road2_yellow \n");
    updateled_state(state_5);
    Time(3);
    if(getbutton())
    {
      updatemachine_state(state_2);
    }
    else
    {
      updatemachine_state(state_1);
    }    
}

