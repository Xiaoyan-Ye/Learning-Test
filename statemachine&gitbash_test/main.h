#ifndef _MAIN_H_
#define _MAIN_H_

void updatemachine_state(int last_buttonstate);
void updateled_state(int last_led_state);
void Time(int t);

enum Machine_state 
{
    state_1 = 0,
    state_2,
    state_3,
    state_4,
    state_5
};

#endif