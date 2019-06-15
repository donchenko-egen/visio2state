// Created 15.06.2019 20:45:46

#ifndef FSA_H
#define FSA_H

#include <data.h>
void zPower_9V_Off(void);
void zPower_5V_On(void);
void zPower_5V_Off(void);
void zMenuOutVersion(void);
void zMenuOutTestLed(void);
void zLedAllRed(void);
void zLedAllGreen(void); 
void zMenuOutGreenLed(void);
void zLedAllBlue(void);
void zMenuOutBlueLed(void);
void zLedAllOff(void);
void zPower_9V_On(void);
void zMenuOutTestPower(void);
void zMenuOutPowerData(void);
void zMenuOutSensorsTest(void);
void zMenuOutSensorsOK(void);
void zMenuOutStartScreen(void);
char xButtonOk(void);
char xButtonNo(void);
char xButton1(void);
char xButton2(void);
char xButtonDown(void);
char xButtonUp(void);
void zClearKeyBufferAll(void );
void zLedAllConnect(void );
void zMenuOutGistScreen(void);
void zLedAllShow(void);
void zColumDown(void);
void zColumUp(void);
void zMenuOutResScreen(void);
void zCalc_Randomize_Seed(void);
char xPowerOffRequest(void);
void zMenuPowerScreen(void);
void zMenuPowerScreenOn(void);
void zMenuClearScreen(void);
char EPD_is_Update(void);
void zSleep(void);
void zShowPowerErrorDetect(void);
char xPowerErrorDetect(void);
typedef struct  {
  volatile uint32_t uNewState;
  volatile uint32_t uOldState;
  volatile uint32_t uOld1State;
  volatile uint32_t uOld2State;
  volatile uint32_t uOld3State;
  volatile uint32_t uOld4State;
  volatile uint32_t uOld5State;
  volatile uint32_t uIsOldReturn; // Flag Return old
  volatile uint32_t uCurState;

} SW_auto_t;

extern uint32_t uSW_Wait_Time[]; // Wait time
void SW_Systick(void); // SW Wait for Systick
void set_SW_Wait(uint32_t uNumWait, uint32_t uTim_Wait); // Set time for wait
uint32_t is_SW_Wait(uint32_t uNumWait); // is time for wait clear


void fsa_aSystem(void); //Первый автомат
void fsa_return_old_aSystem(void); // Return old
void fsa_aTest(void); //Тестовый автомат
void fsa_return_old_aTest(void); // Return old
void fsa(void); // All automate 
void fsa_init(void); // All automate init state 
#endif
