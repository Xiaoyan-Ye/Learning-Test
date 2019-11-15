/* @File Brief : Task implementation file */
#include<stdio.h>
#include<stdlib.h>
#include <string>

#include "task.h"
#include "roadled.h"
#include "button.h"
#include "main.h"
#include "led.h"



#define Redlight_Time 5
#define Greenlight_Time 10
#define Yellowlight_Time 3



int machine_state = 0;


void (*statemachine[])()=
{
    all_red,
    road1_green,
    road1_perred,
    road2_green,
    road2_perred
};

void (*Nstatemachine[])()=
{
    Nall_red,
    Nroad1_green,
    Nroad1_perred,
    Nroad2_green,
    Nroad2_perred
};

void updatemachine_state(int last_machine_state)
{
    machine_state = last_machine_state;
}



/**
 * @brief      One second task,
 *             This task will be entered every 1 second
 * @param[in]  void
 * @param[out] void
 * @exception  NONE
 * @return     void
 */


void Check_button(void)
{
    if(getbutton())
    {
        statemachine[machine_state]();
    }
    else
    {
        Nstatemachine[machine_state]();
    }
}

void Nall_red(void)
{
	loadMedia( "../picture/state1.png" );
    updatemachine_state(state_1);
    update_time_tick(0);
}

void Nroad1_green(void)
{
    updatemachine_state(state_3);
    update_time_tick(0);
}

void Nroad1_perred(void)
{
	loadMedia( "../picture/state3.png" );

    int i = (Yellowlight_Time - get_time_tick()+1)/10;
    int j = (Yellowlight_Time - get_time_tick()+1)%10;
    show_countdown(gCountdownClips[i],gCountdownClips[j]);
  //  printf("road1_yellow,road2_red remain %d s\n",(Yellowlight_Time-get_time_tick()+1));
    if(get_time_tick() == Yellowlight_Time)
    {
        updatemachine_state(state_1);
        update_time_tick(0);
    }
    else
    {
        /*Do nothing*/
    }
}

void Nroad2_green(void)
{
    updatemachine_state(state_5);
    update_time_tick(0);
}

void Nroad2_perred(void)
{
	loadMedia( "../picture/state5.png" );
    int i = (Yellowlight_Time - get_time_tick()+1)/10;
    int j = (Yellowlight_Time - get_time_tick()+1)%10;
    show_countdown(gCountdownClips[i],gCountdownClips[j]);
   // printf("road1_yellow,road2_red remain %d s\n",(Yellowlight_Time-get_time_tick()+1));
    if(get_time_tick() == Yellowlight_Time)
    {
        updatemachine_state(state_1);
        update_time_tick(0);
    }
    else
    {
        /*Do nothing*/
    }
}


void all_red(void)
{
    int i = (Redlight_Time - get_time_tick()+1)/10;
    int j = (Redlight_Time - get_time_tick()+1)%10;
	if(!loadMedia( "../picture/state1.png" ))
	{
		printf("Can not open ../picture/state4.png \n");
	}

    show_countdown(gCountdownClips[i],gCountdownClips[j]);
 //   printf("All red remain %d s\n",(Redlight_Time-get_time_tick()+1) );
    if(get_time_tick() == Redlight_Time)
    {
        updatemachine_state(state_2);
        update_time_tick(0);
    }
    else
    {
        /*Do nothing*/
    }
}

void road1_green(void)
{
	if(!loadMedia( "../picture/state2.png" ))
	{
		printf("Can not open ../picture/state4.png \n");
	}

    int i = (Greenlight_Time - get_time_tick()+1)/10;
    int j = (Greenlight_Time - get_time_tick()+1)%10;
    show_countdown(gCountdownClips[i],gCountdownClips[j]);


  //  printf("road1_green,road2_red  remain %d s\n",(Greenlight_Time-get_time_tick()+1));
    if(get_time_tick() == Greenlight_Time)
    {
        updatemachine_state(state_3);
        update_time_tick(0);
    }
    else
    {
        /*Do nothing*/
    }
}

void road1_perred(void)
{
	if(!loadMedia( "../picture/state3.png" ))
	{
		printf("Can not open ../picture/state4.png \n");
	}

    int i = (Yellowlight_Time - get_time_tick()+1)/10;
    int j = (Yellowlight_Time - get_time_tick()+1)%10;
    show_countdown(gCountdownClips[i],gCountdownClips[j]);
   // printf("road1_yellow,road2_red remain %d s\n",(Yellowlight_Time-get_time_tick()+1));
    if(get_time_tick() == Yellowlight_Time)
    {
        updatemachine_state(state_4);
        update_time_tick(0);
    }
    else
    {
        /*Do nothing*/
    }
}

void road2_green(void)
{
	if(!loadMedia( "../picture/state4.png" ))
	{
		printf("Can not open ../picture/state4.png \n");
	}

    int i = (Greenlight_Time - get_time_tick()+1)/10;
    int j = (Greenlight_Time - get_time_tick()+1)%10;
    show_countdown(gCountdownClips[i],gCountdownClips[j]);
  //  printf("road1_red,road2_green remain %d s\n",(Greenlight_Time-get_time_tick()+1));
    if(get_time_tick() == Greenlight_Time)
    {
        updatemachine_state(state_5);
        update_time_tick(0);
    }
    else
    {
        /*Do nothing*/
    }

}

void road2_perred(void)
{
	loadMedia( "../picture/state5.png" );

    int i = (Yellowlight_Time - get_time_tick()+1)/10;
    int j = (Yellowlight_Time - get_time_tick()+1)%10;
    show_countdown(gCountdownClips[i],gCountdownClips[j]);
    //printf("road1_red,road2_yellow remain %d s\n",(Yellowlight_Time-get_time_tick()+1));
    if(get_time_tick() == Yellowlight_Time)
    {
        updatemachine_state(state_2);
        update_time_tick(0);
    }
    else
    {
        /*Do nothing*/
    }
}

/* !!! @All, You can add you application code to here or any other place except main.c !!! */
