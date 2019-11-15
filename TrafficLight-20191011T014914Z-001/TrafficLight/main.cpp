/*

2019.10.24: Add picture to the traffic light



*/






#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "task.h"
#include "roadled.h"
#include "button.h"

/* --------------Variables-------------------*/
/* Record the time from program start */

/* --------------Internal Function-------------------*/
extern unsigned int time_tick_second = 0;
bool quit = false;

int main()
{
    static unsigned char last_second = 0;
    time_t t;
    struct tm* pTime = NULL;
    t = time(NULL);
    pTime = localtime(&t);
    last_second = pTime->tm_sec;

	//Start up SDL and create window
	if( !init() )
	{
		printf( "Failed to initialize!\n" );
	}
	else{
        loadMediaB("../picture/button_off.png");
		while(!quit)
		{
			t = time(NULL);
			pTime = localtime(&t);
			if(last_second != (unsigned char)pTime->tm_sec)
			{
				last_second = pTime->tm_sec;
				time_tick_second++;
				Check_button();


			}
		}

		close();
	}

    return 0;
}

void update_quit_state(bool last_quit_state)
{
    quit = last_quit_state;
}

void update_time_tick(int last_time_tick)
{
    time_tick_second = last_time_tick;
}

int get_time_tick(void)
{
    return time_tick_second;
}

