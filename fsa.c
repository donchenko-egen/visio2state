// Created 10.06.2019 19:53:24

#include <fsa.h>
SW_auto_t aSystem; //Первый автомат
SW_auto_t aSys; //Второй автомат
void fsa_aSystem(void)  //Первый автомат
{
 // Switch Case
 switch (aSystem.uCurState)
  {
  case 1: // Start
     if (uX5)
        {
         aSystem.uNewState = 4; // goto Name
        }
     else
     if (12)
        {
         aSystem.uNewState = 2; // goto Next
        }
  break;
  case 2: // Next
     if (uX5)
        {
         aSystem.uNewState = 4; // goto Name
        }
     else
     if (uX2)
        {
         aSystem.uNewState = 3; // goto Третий блок
         F23_Hi();
        }
     else
     if (uX3)
        {
         aSystem.uNewState = 3; // goto Третий блок
        }
     else
     if (uX4)
        {
         aSystem.uNewState = 3; // goto Третий блок
         F23_Lo();
        }
  break;
  case 3: // Третий блок
     if (uX5)
        {
         aSystem.uNewState = 4; // goto Name
        }
     else
     if (31)
        {
         aSystem.uNewState = 1; // goto Start
        }
  break;
  case 4: // Name
     if (is_SW_Wait(1))
        {
         aSystem.uNewState = 2; // goto 
        }
     else
     if (is_SW_Wait(2))
        {
         aSystem.uNewState = 3; // goto 
        }
  break;
  }
 if (aSystem.uCurState != aSystem.uNewState) // Exit of current state
    {
    switch (aSystem.uCurState) //  OUT Case
   {
   case 1: // Start
          F_Out1();
          if(uX2) uS=10;
   break;
   case 2: // Next
          SEMADD(A,4)
   break;
   case 3: // Третий блок
          uF2 = 10*u8X;
   break;
   case 4: // Name
          
   break;
  }
    switch (aSystem.uNewState)  //  IN Case
     {
     case 1:   // Start
          F_In(1); //In
          MyFun();
     break;
     case 2:   // Next
          
     break;
     case 3:   // Третий блок
          
     break;
     case 4:   // Name
          
          set_SW_Wait(1,100);

          set_SW_Wait(2,300);

     break;
     }
 }
 else // Loop cycle
    switch (aSystem.uCurState)
     {
     case 1:   // Start
          F_Loop(100);
     break;
     case 2:   // Next
          
     break;
     case 3:   // Третий блок
          
     break;
     case 4:   // Name
          
     break;
     }
 aSystem.uCurState = aSystem.uNewState;
}
void fsa_aSys(void)  //Второй автомат
{
 // Switch Case
 switch (aSys.uCurState)
  {
  case 1: // A
     if (1)
        {
         aSys.uNewState = 2; // goto B
        }
  break;
  case 2: // B
     if (1)
        {
         aSys.uNewState = 1; // goto A
        }
  break;
  }
 if (aSys.uCurState != aSys.uNewState) // Exit of current state
    {
    switch (aSys.uCurState) //  OUT Case
   {
   case 1: // A
          
   break;
   case 2: // B
          
   break;
  }
    switch (aSys.uNewState)  //  IN Case
     {
     case 1:   // A
          
     break;
     case 2:   // B
          
     break;
     }
 }
 else // Loop cycle
    switch (aSys.uCurState)
     {
     case 1:   // A
          
     break;
     case 2:   // B
          
     break;
     }
 aSys.uCurState = aSys.uNewState;
}
 // SW_Wait block 
 void SW_Systick(void) // Dec SW_Wait
    {
       for (int iCount = 0; iCount < 2; iCount++)
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
