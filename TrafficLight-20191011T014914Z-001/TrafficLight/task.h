/* @File Brief : Task header file */

#ifndef _TASK_H_
#define _TASK_H_

enum Machine_state
{
    state_1 = 0,
    state_2,
    state_3,
    state_4,
    state_5
};
void updatemachine_state(int last_machine_state);

void Check_button(void);


void all_red(void);
void road1_green(void);
void road1_perred(void);
void road2_green(void);
void road2_perred(void);

void Nall_red(void);
void Nroad1_green(void);
void Nroad1_perred(void);
void Nroad2_green(void);
void Nroad2_perred(void);
#endif

