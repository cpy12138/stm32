#ifndef __MYIIC_H
#define __MYIIC_H
#include "sys.h" 
#include "stm32f1xx_hal.h"
#include "main.h"
   	   		   
//delay_ms�ض���

//IO��������
//CLK:PD2
//SDA:PC12
#define SDA_IN()  {GPIOC->CRH&=0XFFF0FFFF;GPIOC->CRH|=(u32)8<<16;}
#define SDA_OUT() {GPIOC->CRH&=0XFFF0FFFF;GPIOC->CRH|=(u32)3<<16;}

//IO��������	 
#define IIC_SCL    PDout(2) //SCL
#define IIC_SDA    PCout(12) //SDA	 
#define READ_SDA   PCin(12)  //����SDA 
#define LED1   PAout(8)  //����SDA 

//IIC���в�������
void IIC_Init(void);                //��ʼ��IIC��IO��				 
void IIC_Start(void);				//����IIC��ʼ�ź�
void IIC_Stop(void);	  			//����IICֹͣ�ź�
void IIC_Send_Byte(u8 txd);			//IIC����һ���ֽ�
u8 IIC_Read_Byte(unsigned char ack);//IIC��ȡһ���ֽ�
u8 IIC_Wait_Ack(void); 				//IIC�ȴ�ACK�ź�
void IIC_Ack(void);					//IIC����ACK�ź�
void IIC_NAck(void);				//IIC������ACK�ź�
void delay_us(uint32_t us);

void IIC_Write_One_Byte(u8 daddr,u8 addr,u8 data);
u8 IIC_Read_One_Byte(u8 daddr,u8 addr);	  
#endif
















