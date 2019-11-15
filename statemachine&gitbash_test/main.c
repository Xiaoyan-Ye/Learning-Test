#include<stdio.h>
#include"main.h"
#include<Windows.h>
#include ".\button\button.h"
#include ".\task\task.h"


int machine_state = 0;
int led_state = 0;

void updatemachine_state(int last_machine_state)
{
    machine_state = last_machine_state;    
}

void updateled_state(int last_led_state)
{
    led_state = last_led_state;    
}

void Time(int t)
{
    int x;
    for(x=0;x<t;x++)
    {
        if(getbutton())
        {
            printf("remain %d s\n",(t-x));
            Sleep(1000);
        }
        else
        {
            switch(led_state)
            {
                case state_1: updatemachine_state(state_1);break;
                case state_2: updatemachine_state(state_3);break;
                case state_3: Sleep(1000);printf("remain %d s\n",(t-x));continue;
                case state_4: updatemachine_state(state_5);break;
                case state_5: Sleep(1000);printf("remain %d s\n",(t-x));continue;
                
            }
        }       
    }
   
}


void (*statemachine[])()=
{
    all_red,
    road1_green,
    road1_perred,
    road2_green,
    road2_perred
};

int main()
{
    while(1)
    {
        statemachine[machine_state]();
        
    }
    return 0;
}