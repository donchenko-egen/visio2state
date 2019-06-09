// Created 09.06.2019 22:19:22

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
void fsa_aSystem(void); //Первый автомат
void fsa_aSys(void); //Второй автомат
#endif
