#include "stm32f10x.h"
#include "stm32f10x_gpio.h"


void delay(uint32_t); 


int main(void)
{

		GPIO_InitTypeDef  GPIO_InitStructure;

    /* ʹ��LED��ӦGPIO��Clockʱ�� */
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE);

    /* ��ʼ��LED��GPIO�ܽţ�����Ϊ������� */				  //���ö˿�
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2 ;	 			  //LED1�ƶ�Ӧ��GPIO_Pin_2�˿� 
														 	  //���öԶ˿ڵ�ģʽ
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;		  //����Ϊ ����(Push-Pull)���
														 	  //
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		  //�������ٶ�Ϊ50MHz

    GPIO_Init(GPIOD, &GPIO_InitStructure);	//����GPIO��ʼ������

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
