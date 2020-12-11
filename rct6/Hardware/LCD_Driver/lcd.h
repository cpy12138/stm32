#ifndef __LCD_H
#define __LCD_H		
#include "sys.h"	 
#include "stdlib.h"
#include "stm32f1xx_hal.h"
//////////////////////////////////////////////////////////////////////////////////	
/****************************************************************************************************
//=======================================Һ���������߽���==========================================//
//CS		��PB11	//Ƭѡ�ź�
//CLK	    ��PB13	//SPIʱ���ź�
//SDI(DIN)	��PB15	//SPI���������ź�
//=======================================Һ���������߽���==========================================//
//LED	    ��PB9	//��������źţ��ߵ�ƽ����
//RS(D/C)   ��PB10	//�Ĵ���/����ѡ���ź�(RS=0�������߷��͵���ָ�RS=1�������߷��͵�����������)
//RST	    ��PB12	//Һ������λ�źţ��͵�ƽ��λ
/////////////////////////////////////////////////////////////////////////////////////////////////
//==================================��ξ���ֻ��Ҫ3��IO=======================================//
//1.CS�źſ��Ծ��򣬲���SPI����Ƭѡ�ɽ�CS�ӵس��ͣ���ʡ1��IO
//2.LED��������źſ��ԽӸߵ�ƽ3.3V���ⳣ������ʡ1��IO
//3.RST��λ�źſ��Խӵ���Ƭ���ĸ�λ�ˣ�����ϵͳ�ϵ縴λ����ʡ1��IO
//==================================����л���������ʾ=======================================//
//��lcd.hͷ�ļ����޸ĺ�#define USE_HORIZONTAL ֵΪ0ʹ������ģʽ.1,ʹ�ú���ģʽ
//===========================����л�ģ��SPI����������Ӳ��SPI��������=========================//
//��lcd.hͷ�ļ����޸ĺ�#define USE_HARDWARE_SPI  ֵΪ0ʹ��ģ��SPI����.1,ʹ��Ӳ��SPI����
**************************************************************************************************/	

#define GPIO_Pin_0 GPIO_PIN_0
#define GPIO_Pin_1 GPIO_PIN_1
#define GPIO_Pin_2 GPIO_PIN_2
#define GPIO_Pin_3 GPIO_PIN_3
#define GPIO_Pin_4 GPIO_PIN_4
#define GPIO_Pin_5 GPIO_PIN_5
#define GPIO_Pin_6 GPIO_PIN_6
#define GPIO_Pin_7 GPIO_PIN_7
#define GPIO_Pin_8 GPIO_PIN_8
#define GPIO_Pin_9 GPIO_PIN_9
#define GPIO_Pin_10 GPIO_PIN_10
#define GPIO_Pin_11 GPIO_PIN_11
#define GPIO_Pin_12 GPIO_PIN_12
#define GPIO_Pin_13 GPIO_PIN_13

//LCD��Ҫ������
typedef struct  
{										    
	u16 width;			//LCD ����
	u16 height;			//LCD �߶�
	u16 id;				//LCD ID
	u8  dir;			//���������������ƣ�0��������1��������	
	u16	 wramcmd;		//��ʼдgramָ��
	u16  setxcmd;		//����x����ָ��
	u16  setycmd;		//����y����ָ��	 
}_lcd_dev; 	

//LCD����
extern _lcd_dev lcddev;	//����LCD��Ҫ����
/////////////////////////////////////�û�������///////////////////////////////////	 
//֧�ֺ��������ٶ����л���֧��8/16λģʽ�л�
#define USE_HORIZONTAL  	0	//�����Ƿ�ʹ�ú��� 		0,��ʹ��.1,ʹ��.
//ʹ��Ӳ��SPI ����ģ��SPI��Ϊ����
#define USE_HARDWARE_SPI    0  //1:Enable Hardware SPI;0:USE Soft SPI
//////////////////////////////////////////////////////////////////////////////////	  
//����LCD�ĳߴ�
#if USE_HORIZONTAL==1	//ʹ�ú���
#define LCD_W 320
#define LCD_H 240
#else
#define LCD_W 240
#define LCD_H 320
#endif

//TFTLCD������Ҫ���õĺ���		   
extern u16  POINT_COLOR;//Ĭ�Ϻ�ɫ    
extern u16  BACK_COLOR; //������ɫ.Ĭ��Ϊ��ɫ

////////////////////////////////////////////////////////////////////
//-----------------LCD�˿ڶ���---------------- 
//QDtechȫϵ��ģ������������ܿ��Ʊ��������û�Ҳ���Խ�PWM���ڱ�������

//�ӿڶ�����Lcd_Driver.h�ڶ��壬����ݽ����޸Ĳ��޸���ӦIO��ʼ��LCD_GPIO_Init()
#define LCD_CTRLA   	  GPIOA		//����TFT���ݶ˿�
#define LCD_CTRLB   	  GPIOB		//����TFT���ݶ˿�
#define LCD_CTRLC   	  GPIOC		//����TFT���ݶ˿�
#define LCD_CTRLD   	  GPIOD		//����TFT���ݶ˿�

#define LCD_CS        	GPIO_Pin_4 //PB11 ������TFT --CS

#define LCD_RST     		GPIO_Pin_13	//PB12������TFT --RST
#define LCD_RS         	GPIO_Pin_8	//PB10������TFT --RS
#define LCD_SCL        	GPIO_Pin_2	//PB13������TFT -- CLK
#define LCD_SDA        	GPIO_Pin_12	//PB15������TFT - SDI
							    
//////////////////////////////////////////////////////////////////////
//Һ�����ƿ���1�������궨��
#define	LCD_CS_SET  	LCD_CTRLA->BSRR=LCD_CS  
#define	LCD_LED_SET  	LCD_CTRLB->BSRR=LCD_LED  

#define	LCD_RST_SET  	LCD_CTRLC->BSRR=LCD_RST    
#define	LCD_RS_SET  	LCD_CTRLA->BSRR=LCD_RS    
#define	LCD_SDA_SET  	LCD_CTRLC->BSRR=LCD_SDA    
#define	LCD_SCL_SET  	LCD_CTRLD->BSRR=LCD_SCL    
 

//Һ�����ƿ���0�������궨��
   
#define	LCD_RS_CLR  	LCD_CTRLA->BRR=LCD_RS    
#define	LCD_SDA_CLR  	LCD_CTRLC->BRR=LCD_SDA    
#define	LCD_SCL_CLR  	LCD_CTRLD->BRR=LCD_SCL
#define	LCD_RST_CLR  	LCD_CTRLC->BRR=LCD_RST 

#define	LCD_CS_CLR  	LCD_CTRLA->BRR=LCD_CS        
#define	LCD_LED_CLR  	LCD_CTRLB->BRR=LCD_LED 

//������ɫ
#define WHITE       0xFFFF
#define BLACK      	0x0000	  
#define BLUE       	0x001F  
#define BRED        0XF81F
#define GRED 			 	0XFFE0
#define GBLUE			 	0X07FF
#define RED         0xF800
#define MAGENTA     0xF81F
#define GREEN       0x07E0
#define CYAN        0x7FFF
#define YELLOW      0xFFE0
#define BROWN 			0XBC40 //��ɫ
#define BRRED 			0XFC07 //�غ�ɫ
#define GRAY  			0X8430 //��ɫ
//GUI��ɫ

#define DARKBLUE      	 0X01CF	//����ɫ
#define LIGHTBLUE      	 0X7D7C	//ǳ��ɫ  
#define GRAYBLUE       	 0X5458 //����ɫ
//������ɫΪPANEL����ɫ 
 
#define LIGHTGREEN     	0X841F //ǳ��ɫ
//#define LIGHTGRAY     0XEF5B //ǳ��ɫ(PANNEL)
#define LGRAY 			 		0XC618 //ǳ��ɫ(PANNEL),���屳��ɫ

#define LGRAYBLUE      	0XA651 //ǳ����ɫ(�м����ɫ)
#define LBBLUE          0X2B12 //ǳ����ɫ(ѡ����Ŀ�ķ�ɫ)
	    															  
extern u16 BACK_COLOR, POINT_COLOR ;  

void LCD_Init(void);
void LCD_DisplayOn(void);
void LCD_DisplayOff(void);
void LCD_Clear(u16 Color);	 
void LCD_SetCursor(u16 Xpos, u16 Ypos);
void LCD_DrawPoint(u16 x,u16 y);//����
u16  LCD_ReadPoint(u16 x,u16 y); //����
void LCD_DrawLine(u16 x1, u16 y1, u16 x2, u16 y2);
void LCD_DrawRectangle(u16 x1, u16 y1, u16 x2, u16 y2);		   
void LCD_SetWindows(u16 xStar, u16 yStar,u16 xEnd,u16 yEnd);
void LCD_DrawPoint_16Bit(u16 color);
u16 LCD_RD_DATA(void);//��ȡLCD����									    
void LCD_WriteReg(u16 LCD_Reg, u16 LCD_RegValue);
void LCD_WR_DATA(u8 data);
void LCD_WR_DATA_16Bit(u16 data);
u16 LCD_ReadReg(u8 LCD_Reg);
void LCD_WriteRAM_Prepare(void);
void LCD_WriteRAM(u16 RGB_Code);
u16 LCD_ReadRAM(void);		   
u16 LCD_BGR2RGB(u16 c);
void LCD_SetParam(void);

						  		 
#endif  
	 
	 


