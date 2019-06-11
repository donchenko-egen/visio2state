// Created 11.06.2019 14:52:02

#include <fsa.h>

SW_auto_t SW_aSystem; //Первый автомат

void fsa_conn_aSystem(void)  // Connect for Первый автомат
{
 // Switch Case
 switch (SW_aSystem.uCurState)
  {
  case 1: //  Start
     if (is_SW_Wait(1))
        {
         SW_aSystem.uNewState = 2; // goto Version Show
         
         set_SW_Wait(1,500);
        }
  break;
  case 2: // Version Show
     if (is_SW_Wait(1))
        {
         SW_aSystem.uNewState = 3; // goto Start test Led 
         
         set_SW_Wait(1,1500);
        }
  break;
  case 3: // Start test Led 
     if (is_SW_Wait(1))
        {
         SW_aSystem.uNewState = 4; // goto Green test Led 
         
         set_SW_Wait(1,1500);
        }
  break;
  case 4: // Green test Led 
     if (is_SW_Wait(1))
        {
         SW_aSystem.uNewState = 5; // goto Blue test Led
         
         set_SW_Wait(1,1500);
        }
  break;
  case 5: // Blue test Led
     if (is_SW_Wait(1))
        {
         SW_aSystem.uNewState = 6; // goto Name
         
         set_SW_Wait(1,2500);
        }
  break;
  case 6: // Name
     if (is_SW_Wait(1))
        {
         SW_aSystem.uNewState = 7; // goto Write Power Data 
         
         set_SW_Wait(1,2500);
        }
  break;
  case 7: // Write Power Data 
     if (is_SW_Wait(1))
        {
         SW_aSystem.uNewState = 8; // goto  Write Test Sensors 
         
         set_SW_Wait(1,2500);
        }
  break;
  case 8: //  Write Test Sensors 
     if (is_SW_Wait(1))
        {
         SW_aSystem.uNewState = 9; // goto Write Test Sensors 
         
         set_SW_Wait(1,2500);
        }
  break;
  case 9: // Write Test Sensors 
     if (is_SW_Wait(1))
        {
         SW_aSystem.uNewState = 10; // goto Wait Start Screen 
         zLedAllConnect();
         set_SW_Wait(1,4500);
        }
  break;
  case 10: // Wait Start Screen 
     if (xButtonOk())
        {
         SW_aSystem.uNewState = 11; // goto Qulity Out Screen 
        }
     else
     if (is_SW_Wait(1))
        {
         SW_aSystem.uNewState = 10; // goto Wait Start Screen 
         zClearKeyBufferAll();
         zLedAllConnect();
         set_SW_Wait(1,500);
        }
     else
     if (xButton1())
        {
         SW_aSystem.uNewState = 12; // goto Result  OUT Screen 
        }
  break;
  case 11: // Qulity Out Screen 
     if (is_SW_Wait(1))
        {
         SW_aSystem.uNewState = 11; // goto Qulity Out Screen 
         zClearKeyBufferAll();
         zMenuOutGistScreen();
         set_SW_Wait(1,4500);
        }
     else
     if (xButton1())
        {
         SW_aSystem.uNewState = 12; // goto Result  OUT Screen 
        }
     else
     if (is_SW_Wait(2))
        {
         SW_aSystem.uNewState = 11; // goto Qulity Out Screen 
         zClearKeyBufferAll();
         zCalc_Randomize_Seed();
          zLedAllShow();
         set_SW_Wait(2,100);
        }
     else
     if (xButton2())
        {
         SW_aSystem.uNewState = 10; // goto 
        }
  break;
  case 12: // Result  OUT Screen 
     if (xButton2())
        {
           fsa_return_old_aSystem(); // Return old
        }
     else
     if (xButtonDown())
        {
         SW_aSystem.uNewState = 12; // goto Result  OUT Screen 
         zColumDown();
         zClearKeyBufferAll();
         zMenuOutResScreen();
        }
     else
     if (xButtonUp())
        {
         SW_aSystem.uNewState = 12; // goto Result  OUT Screen 
         zColumUp();
         zClearKeyBufferAll();
         zMenuOutResScreen();
        }
  break;
  case 25: // A
     if (1)
        {
         SW_aSystem.uNewState = 26; // goto B
        }
  break;
  case 26: // B
     if (1)
        {
         SW_aSystem.uNewState = 25; // goto A
        }
  break;
  }
}
void fsa_out_aSystem(void)  // OUT block for  Первый автомат
{
  switch (SW_aSystem.uCurState) //  OUT Case
   {
   case 1: //  Start
          
   break;
   case 2: // Version Show
          
   break;
   case 3: // Start test Led 
          
   break;
   case 4: // Green test Led 
          
   break;
   case 5: // Blue test Led
          
   break;
   case 6: // Name
          
   break;
   case 7: // Write Power Data 
          
   break;
   case 8: //  Write Test Sensors 
          
   break;
   case 9: // Write Test Sensors 
          zClearKeyBufferAll();
          zLedAllOff();
   break;
   case 10: // Wait Start Screen 
          zClearKeyBufferAll();
   break;
   case 11: // Qulity Out Screen 
          zClearKeyBufferAll();
   break;
   case 12: // Result  OUT Screen 
          zClearKeyBufferAll();
   break;
   case 25: // A
          
   break;
   case 26: // B
          
   break;
  }
}
void fsa_in_aSystem(void)  // IN block for Первый автомат
{
  switch (SW_aSystem.uNewState)  //  IN Case
     {
     case 1:   //  Start
          zPower_9V_Off();
          zPower_5V_On();
          set_SW_Wait(1,500);

     break;
     case 2:   // Version Show
          zMenuOutVersion();
          set_SW_Wait(1,1500);

     break;
     case 3:   // Start test Led 
          zMenuOutTestLed();
          zLedAllRed();
          set_SW_Wait(1,1500);

     break;
     case 4:   // Green test Led 
          zLedAllGreen(); 
          zMenuOutGreenLed();
          set_SW_Wait(1,1500);

     break;
     case 5:   // Blue test Led
          zLedAllBlue();
          zMenuOutBlueLed();
          set_SW_Wait(1,2500);

     break;
     case 6:   // Name
          zLedAllOff();
          zPower_9V_On();
          zMenuOutTestPower();
          set_SW_Wait(1,2500);

     break;
     case 7:   // Write Power Data 
          zMenuOutPowerData();
          set_SW_Wait(1,2500);

     break;
     case 8:   //  Write Test Sensors 
          zMenuOutSensorsTest();
          set_SW_Wait(1,2500);

     break;
     case 9:   // Write Test Sensors 
          zLedAllGreen();
          zMenuOutSensorsOK();
          set_SW_Wait(1,4500);

     break;
     case 10:   // Wait Start Screen 
          zMenuOutStartScreen();
          zLedAllConnect();
          set_SW_Wait(1,500);

     break;
     case 11:   // Qulity Out Screen 
          zMenuOutGistScreen();
          set_SW_Wait(1,4500);

          set_SW_Wait(2,100);

     break;
     case 12:   // Result  OUT Screen 
          zMenuOutResScreen();
     break;
     case 25:   // A
          
     break;
     case 26:   // B
          
     break;
     }
}
void fsa_loop_aSystem(void)  // Loop block for Первый автомат
{
  switch (SW_aSystem.uCurState)
     {
     case 1:   //  Start
          
     break;
     case 2:   // Version Show
          
     break;
     case 3:   // Start test Led 
          
     break;
     case 4:   // Green test Led 
          
     break;
     case 5:   // Blue test Led
          
     break;
     case 6:   // Name
          
     break;
     case 7:   // Write Power Data 
          
     break;
     case 8:   //  Write Test Sensors 
          
     break;
     case 9:   // Write Test Sensors 
          
     break;
     case 10:   // Wait Start Screen 
          
     break;
     case 11:   // Qulity Out Screen 
          
     break;
     case 12:   // Result  OUT Screen 
          
     break;
     case 25:   // A
          
     break;
     case 26:   // B
          
     break;
     }
}
void fsa_aSystem(void)  //Первый автомат
{
   if (SW_aSystem.uNewState != SW_aSystem.uCurState )// if in to current state
      {
          fsa_in_aSystem(); // IN
      }
   SW_aSystem.uCurState = SW_aSystem.uNewState;  // Set Cur state

   fsa_conn_aSystem();  // Conn  Первый автомат

   if (SW_aSystem.uNewState != SW_aSystem.uCurState )// if exit of current state
      fsa_out_aSystem(); // OUT
    else // Not exit of current state
      fsa_loop_aSystem(); // loop block

   if (SW_aSystem.uNewState != SW_aSystem.uCurState ) // if exit of current state
       {
         SW_aSystem.uOld5State = SW_aSystem.uOld4State;  // Set Old5 state
         SW_aSystem.uOld4State = SW_aSystem.uOld3State;  // Set Old4 state
         SW_aSystem.uOld3State = SW_aSystem.uOld2State;  // Set Old3 state
         SW_aSystem.uOld2State = SW_aSystem.uOld1State;  // Set Old2 state
         SW_aSystem.uOld1State = SW_aSystem.uOldState;  // Set Old1 state
         SW_aSystem.uOldState = SW_aSystem.uCurState;  // Set Old state
       }
}
void fsa(void) // All automate 
{
  fsa_aSystem();  // RUN Первый автомат
}

void fsa_init(void) // All automate init 
{
    SW_aSystem.uNewState = 1; // Goto Base state
    SW_aSystem.uCurState = 1; // Base state
    SW_aSystem.uOldState = 1; // Base state
    SW_aSystem.uOld2State = 1; // Base state
    SW_aSystem.uOld3State = 1; // Base state
    SW_aSystem.uOld4State = 1; // Base state
    SW_aSystem.uOld5State = 1; // Base state
}
void fsa_return_old_aSystem(void)  // Return OLD Num of Первый автомат
{
         SW_aSystem.uNewState = SW_aSystem.uOldState; // Return OLD
         SW_aSystem.uOldState = SW_aSystem.uOld1State; // Return OLD
         SW_aSystem.uOld1State = SW_aSystem.uOld2State; // Return OLD
         SW_aSystem.uOld2State = SW_aSystem.uOld3State; // Return OLD
         SW_aSystem.uOld3State = SW_aSystem.uOld4State; // Return OLD
         SW_aSystem.uOld4State = SW_aSystem.uOld5State; // Return OLD
}

 // SW_Wait block 

uint32_t uSW_Wait_Time[3]; // Wait time array

 void SW_Systick(void) // Dec SW_Wait
    {
       for (int iCount = 0; iCount < 3; iCount++)
            if (uSW_Wait_Time[iCount]) (uSW_Wait_Time[iCount])--; // Dec SW_Wait time 
    }
 void set_SW_Wait(uint32_t uNumWait, uint32_t uTim_Wait) // Set time for wait
    {
        uSW_Wait_Time[uNumWait] = uTim_Wait; //Set SW_Wait time 
    }
 uint32_t is_SW_Wait(uint32_t uNumWait) // is time for wait clear
    {
       if ( uSW_Wait_Time[uNumWait] ) return 0; 
            else return 1;
    }
