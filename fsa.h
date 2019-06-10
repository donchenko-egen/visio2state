// Created 10.06.2019 19:53:24

#ifndef FSA_H
#define FSA_H

// My include
#include <data.h>

void  MyFun(void); 
void F_In(int A); // Example
void F_Loop(uint32_t uA);
void F_Out1(void);
void F12(void);
void F23_Hi(void);
void F23_Lo(void);
uint32_t uX2, uX3, uX4, uF2,uS;
uint32_t uX5;
uint8_t u8X;

typedef struct  {
  volatile uint32_t uNewState;
  volatile uint32_t uCurState;

} SW_auto_t;

uint32_t uSW_Wait_Time[2]; // Wait time
void SW_Systick(void); // SW Wait for Systick
void set_SW_Wait(uint32_t uNumWait, uint32_t uTim_Wait); // Set time for wait
uint32_t is_SW_Wait(uint32_t uNumWait); // is time for wait clear


void fsa_aSystem(void); //Первый автомат
void fsa_aSys(void); //Второй автомат
#endif
