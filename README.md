# motor_pmsm
stm32
#include "GrayConversion.h"


typedef enum
{
	false = 0,
	true = !false
}ubool;
/**
 * 二进制转换成格雷码
 * @param lStart lValue所在区间下界
 * @param lEnd lValue所在区间上界
 * @param lValue 要转换的二进制数的实值
 * @return 返回格雷码对应的二进制数的实值
 * @see g2b() g2b 格雷码转换二进制
 * @useage a=b2g(0,15,4); //取得4所对应格雷码的二进制值 结果a等于6
 * @memo lValue的值必须在区间[lStart,lEnd]里,否则无法求得所求结果.相应地,如果区间越小,求得结
 *       果所用的时间就越少.而且lStart,lEnd的值必须为2的N次方减1. 通常lStart为0.
 */
unsigned int b2g(unsigned int lStart,unsigned int lEnd,unsigned int lValue)
{
	unsigned int Start=lStart,End=lEnd,Temp=0,Counter=0;
	ubool Type = true;

	while(Start<End){
		Temp=(End+Start-1)>>1;
		if(lValue<=Temp){
			if(!Type)
				Counter+=((End-Start+1)>>1);
			End=Temp;
			Type=true;
		}
		else{
			if(Type)
				Counter+=((End-Start+1)>>1);
			Start=++Temp;
			Type=false;
		}
	}
	return Counter;
}
/**
 * 格雷码转换成二进制
 * @param lStart lValue对应二进制数所在区间下界
 * @param lEnd lValue对应二进制数所在区间上界
 * @param lValue 要转换的格雷码的实值
 * @return 返回二进制数对应的格雷码的实值
 * @see b2g() b2g 二进制转换格雷码
 * @useage a=b2g(0,15,6);//取得6所对应二进制值的格雷码 结果a等于4
 * @memo lValue对应二进制数的值必须在区间[lStart,lEnd]里,否则无法求得所求结果.相应地,如果区
 *       间越小,求得结果所用的时间就越少.而且lStart,lEnd的值必须为2的N次方减1. 通常lStart为0.
 */
unsigned int g2b(unsigned int lStart,unsigned int lEnd,unsigned int lValue)
{
	unsigned int Start=lStart,End=lEnd,Counter=0,Temp=0; 
	ubool Type=true;

	while(Start<End){
		Temp=Counter+((End-Start+1)>>1);
		if(Type^(lValue<Temp)){
			if(Type)
				Counter=Temp;
			Start=(Start+End+1)>>1;
			Type=false;
		}
		else{
			if(!Type)
				Counter=Temp;
			End=(Start+End-1)>>1;
			Type=true;
		}
	}
	return Start;
}

/**
  ******************************************************************************
  * @file    Templates/Src/stm32f4xx_it.c 
  * @author  MCD Application Team
  * @version V1.2.1
  * @date    13-March-2015
  * @brief   Main Interrupt Service Routines.
  *          This file provides template for all exceptions handler and 
  *          peripherals interrupt service routine.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT(c) 2015 STMicroelectronics</center></h2>
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32f4xx_it.h"

/** @addtogroup STM32F4xx_HAL_Examples
  * @{
  */

/** @addtogroup Templates
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/******************************************************************************/
/*            Cortex-M4 Processor Exceptions Handlers                         */
/******************************************************************************/

/**
  * @brief   This function handles NMI exception.
  * @param  None
  * @retval None
  */
void NMI_Handler(void)
{
}

/**
  * @brief  This function handles Hard Fault exception.
  * @param  None
  * @retval None
  */
void HardFault_Handler(void)
{
  /* Go to infinite loop when Hard Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Memory Manage exception.
  * @param  None
  * @retval None
  */
void MemManage_Handler(void)
{
  /* Go to infinite loop when Memory Manage exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Bus Fault exception.
  * @param  None
  * @retval None
  */
void BusFault_Handler(void)
{
  /* Go to infinite loop when Bus Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Usage Fault exception.
  * @param  None
  * @retval None
  */
void UsageFault_Handler(void)
{
  /* Go to infinite loop when Usage Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles SVCall exception.
  * @param  None
  * @retval None
  */
void SVC_Handler(void)
{
}

/**
  * @brief  This function handles Debug Monitor exception.
  * @param  None
  * @retval None
  */
void DebugMon_Handler(void)
{
}

/**
  * @brief  This function handles PendSVC exception.
  * @param  None
  * @retval None
  */
void PendSV_Handler(void)
{
}

/**
  * @brief  This function handles SysTick Handler.
  * @param  None
  * @retval None
  */
void SysTick_Handler(void)
{
  HAL_IncTick();
}

/******************************************************************************/
/*                 STM32F4xx Peripherals Interrupt Handlers                   */
/*  Add here the Interrupt Handler for the used peripheral(s) (PPP), for the  */
/*  available peripheral interrupt handler's name please refer to the startup */
/*  file (startup_stm32f4xx.s).                                               */
/******************************************************************************/

/**
  * @brief  This function handles PPP interrupt request.
  * @param  None
  * @retval None
  */
/*void PPP_IRQHandler(void)
{
}*/


/**
  * @}
  */ 

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/



