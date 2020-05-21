/**
  ******************************************************************************
  * @file    	main.c 
  * @author  	Alfred Lohmann
  *        	  HAW-Hamburg
  *          	Labor für technische Informatik
  *          	Berliner Tor  7
  *          	D-20099 Hamburg
  * @version V1.0
  * @date    23.05.2013
  * @brief   Main program body
  ******************************************************************************
  */


/* Includes ------------------------------------------------------------------*/

#include "header.h"

//--- For GPIOs -----------------------------
//Include instead of "stm32f4xx.h" for
//compatibility between Simulation and Board
//#include "TI_memory_map.h"

//--- For Touch Keypad ----------------------
//#include "keypad.h"

//--- For Timer -----------------------------
//#include "timer.h"


/**
  * @brief  Main program
  * @param  None
  */
int main(void)
{
  Init_TI_Board();
    
  int ci0  = fiboci(0);
	int ci10 = fiboci(10);
	int ci22 = fiboci(22);
	int ci29 = fiboci(29);
	
	int cr0  = fibocr(0);
	int cr10 = fibocr(10);
	int cr22 = fibocr(22);
	int cr29 = fibocr(29);
	
	int ai0  = fiboai(0);
	int ai10 = fiboai(10);
	int ai22 = fiboai(22);
	int ai29 = fiboai(29);
	
	int ar0  = fiboar(0);
	int ar10 = fiboar(10);
	int ar22 = fiboar(22);
	int ar29 = fiboar(29);
	
	int (*fp[4])(int)={fiboci,fibocr,fiboai,fiboar};
	int arg[4]={0,10,22,29};
	int resu[4][4];
	
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			resu[i][j] = fp[i](arg[j]);
		}
	}
	
  return 0;

}

int fiboci(int arg)
{
	int i = 0;
	int lasti1 = 0;
	int lasti2 = 0;
	int result = 0;
	
	while(i<=arg)
	{
		if(i == 0)
		{
			result = 1;
			lasti1 = result;
		}
		else if(i == 1)
		{
			result = 1;
			lasti2 = lasti1;
		}
		else
		{
			result= lasti1 + lasti2;
			lasti2 = lasti1;
			lasti1 = result;
		}
		i++;

	}
	return result;
}

int fibocr(int arg)
{
	if(arg == 0)
	{
		return 1;
	}
	else if(arg == 1)
	{
		return 1;
	}
	else
	{
		return fibocr(arg-1) + fibocr(arg-2);
	}
}


// EOF
