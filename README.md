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




