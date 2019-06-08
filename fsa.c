// Created 08.06.2019 22:22:37

#include <fsa.h>
SW_auto_t aSystem; //Первый автомат
SW_auto_t aSys; //Второй автомат
void fsa_aSystem(void)  //Первый автомат
{
 // Switch Case
 switch (aSystem.uCurState)
  {
  case 1: // Start
     if (1)
        {
         aSystem.uNewState = 2; // goto Next
         F12();
        }
  break;
  case 2: // Next
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
     if (1)
        {
         aSystem.uNewState = 1; // goto Start
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
          
   break;
   case 3: // Третий блок
          uF2 = 10*u8X;
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
