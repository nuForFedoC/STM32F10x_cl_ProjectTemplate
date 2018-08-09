#include "stm32f10x.h"
#include "stm32f10x_gpio.h"


void delay(uint32_t); 


int main(void)
{

		GPIO_InitTypeDef  GPIO_InitStructure;

    /* 使能LED对应GPIO的Clock时钟 */
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE);

    /* 初始化LED的GPIO管脚，配置为推挽输出 */				  //设置端口
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2 ;	 			  //LED1灯对应的GPIO_Pin_2端口 
														 	  //设置对端口的模式
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;		  //设置为 推挽(Push-Pull)输出
														 	  //
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		  //最大输出速度为50MHz

    GPIO_Init(GPIOD, &GPIO_InitStructure);	//调用GPIO初始化函数

    while (1)
    {
			GPIOD->BRR = GPIO_Pin_2 | GPIO_Pin_7; 
			delay(5000000);

			GPIOD->BSRR = GPIO_Pin_2 | GPIO_Pin_7;
			delay(5000000);
    }    
}

void delay(__IO uint32_t nCount)
{
  for (; nCount != 0; nCount--);
}
