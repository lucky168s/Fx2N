;/****************************************Copyright (C)**************************************************
;**                               	
;**                                                                             
;**                                  
;**--------------�ļ���Ϣ--------------------------------------------------------------------------------
;**��   ��   ��: PLC_PUBLIC.H
;**��        ��: V2.1
;**��   ��   ��: LuHeDing
;**����޸�����: 2010��05��08��
;**��        ��: PLC������������
;** 
;********************************************************************************************************/

#ifndef  PLC_PUBLIC_H
#define  PLC_PUBLIC_H

#include "PLC_CONF.H"

#include "plc_app.H"
#include "stm32f10x.h"

//#define	debug

/******************************************************************************/
typedef unsigned char  uint8;   /* �޷���8λ���ͱ���    */
typedef signed   char  int8;    /* �з���8λ���ͱ���	*/
typedef unsigned short uint16;  /* �޷���16λ���ͱ���   */
typedef signed   short int16;   /* �з���16λ���ͱ���   */
typedef unsigned int   uint32;  /* �޷���32λ���ͱ���   */
typedef unsigned long long   uint64;  /* �޷���64λ���ͱ���   */
typedef signed   int   int32;   /* �з���32λ���ͱ���   */ 
//typedef unsigned long  u32;
//typedef unsigned short u16;
//typedef unsigned char  u8;

	 //__set_PRIMASK(1);printf(fmt,##args); __set_PRIMASK(0) //DEBUG_UART(a)
#ifdef	debug
#define debug_send(fmt,args...)	printf(fmt,##args)
#else
#define debug_send(fmt,args...)	
#endif

/******************************************************************************/
#define RUN_LED 1<<5  //p0.05
#define RUN_KEY 1<<14 //P1.14(89)
#define 	O1	1<<15  //P1.15(88)CLK
#define 	O2	1<<16  //P1.16(87)OUT_CP
#define 	O3	1<<17  //P1.17(86)OUT_DATA
#define 	O4	1<<29  //P4.29(85)INT_LD
#define 	I5	1<<28  //P4.28(82)INT_DATA
extern      unsigned int MyD_I_DATA,MyD_O_DATA;
extern      void PLC_IO_INIT(void);
extern      void PLC_Init(void);
extern      void PLC_X_Filter(void);
extern      void PLC_IO_BREAK(void);

/******************************************************************************/
/*extern uint32 timer0_counter;
extern uint32 timer1_counter;
extern uint32 timer2_counter;
extern uint32 timer3_counter;  */
/******************************************************************************/
#define  PLC_Type  0x5EF6


extern void     PLC_UART_CMD(void);
extern void     PLC_UART_HANDLE(void); 
/******************************************************************************/
extern uint8    PLC_STL_CMD;
extern uint16   PLC_STL_ADD;//��һ��ִ�е�STL(S)��
extern uint32  PLC_STL_PC;
extern uint16 s[12];
extern uint8 cont;
extern void     PLC_STL_RUN(void);		   //STL��ָ��	 

extern uint8    BOT_BIT;				   //����ִ�б�־
/******************************************************************************/
extern uint32 	PLC_PC,PLC_O_PC;		 					//PLC����ָ��
extern uint16 	PLC_TEMP1,PLC_TEMP2,PLC_CMD;	//����ִ��ר��16λ�Ĵ���
extern uint16 	PLC_TEMP3,PLC_TEMP4;			//����ִ��ר��16λ�Ĵ���
extern uint32 	PLC_TEMP5,PLC_TEMP6,PLC_TEMPA;			//����ִ��ר��32λ�Ĵ���
extern uint64   PLC_TEMP7,PLC_TEMP8,PLC_TEMP9;//����ִ��ר��64λ�Ĵ���
extern uint8  	PLC_ACC_BIT,PLC_MPS_BIT;		//����ִ��ר��(����ջ������ջ)
extern uint16 	PLC_RUN_TIME; 					// ɨ��ʱ��
extern void     PLC_PROG_ERROR(uint16 err_id);	//PLC�������
//extern uint8    PLC_1MS_BIT;					//PLC 1MS��־λ(����������ʽ���б�־)
extern uint8    PLC_RUN_BIT;	 				//PLC���б�־
// 0=������;1=PLC����ǰ���ݸ�λ;2=PLC��������;3=PLC�����³�����;4=PLCֹͣǰ���ݸ�λ;
// 5=PLC�����������;6=PLC�������;����=?
/******************************************************************************/


extern void   PLC_END_PROG(void);
extern void	  MyD_IO_INIT(void);
extern void	  MyD_I_INPUT(void);
extern void	  PLC_IO_BREAK(void);
extern void	  PLC_RESET_RAM(void);
extern void   PLC_PROG_TEST(void);
extern void UARTSend2(USART_TypeDef *uart);
extern void   PLC_AllInit(void);
extern void   diy(unsigned int diy_t);
/******************************************************************************/
extern const uint8 hex[256];
extern const uint8 asc[16];
/******************************************************************************/
extern const uint8 PLC_BIT_OR[];
extern const uint8 PLC_BIT_AND[];
extern const uint8 PROG_CODE[];



#define PLC_T_START_ADD			PLC_R_START_ADD+0x0800	//T��ʱ����ǰֵ��ʼ��ַ
#define PLC_C_START_ADD			PLC_R_START_ADD+0x0A00	//C��ʱ����ǰֵ��ʼ��ַ
#define PLC_C16_START_ADD		PLC_R_START_ADD+0x0A00	//C16λ��������ǰֵ��ʼ��ַ
#define PLC_C32_START_ADD		PLC_R_START_ADD+0x0C00	//C32λ��������ǰֵ��ʼ��ַ
#define PLC_D8000_START_ADD		PLC_R_START_ADD+0x0E00	//D8000-D8255��ǰֵ��ʼ��ַ
#define PLC_D_START_ADD			PLC_R_START_ADD+0x1000	//D0-D999��ǰֵ��ʼ��ַ	 0x1000-0x17CF
#define PLC_D1000_START_ADD		PLC_R_START_ADD+0x17D0	//D1000-D7999��ǰֵ��ʼ��ַ



//#define PLC_O_R_START_ADD		PLC_R_START_ADD+0x0200	//������Ȧ��ֵ
//#define PLC_CT_C_START_ADD	PLC_R_START_ADD+0x0400	//C T COIL ��Ȧ

//#define PLC_Comm_Rx	            PLC_R_START_ADD+0x5B00	//ͨ������(����)����
//#define PLC_Comm_Tx	            PLC_R_START_ADD+0x5B40	//ͨ������(����)����

#define PLC_Ins1400_S_Add		PLC_R_START_ADD+0x5D00	//E10 1400���ÿ�ʼ��ַ
#define PLC_Ins1790_S_Add		PLC_R_START_ADD+0x5B90	//E10 1790���ÿ�ʼ��ַ
/******************************************************************************/
//#define PLC_ROM_TEST(x)		(PLC_RAM8(PLC_PROG_START_ADD2+((x)/8)) 		& PLC_BIT_OR[(x)%8])
#define PLC_BIT_TEST(x)		(PLC_RAM8(PLC_R_START_ADD+((x)/8)) 			& PLC_BIT_OR[(x)%8])
#define PLC_BIT_ON(x)		(PLC_RAM8(PLC_R_START_ADD+((x)/8))			|=PLC_BIT_OR[(x)%8])
#define PLC_BIT_OFF(x)		(PLC_RAM8(PLC_R_START_ADD+((x)/8))			&=PLC_BIT_AND[(x)%8])

#define PLC_BIT_M1536_TEST(x)		(PLC_RAM8(PLC_R_START_ADD+0x5720+((x)/8)) 			& PLC_BIT_OR[(x)%8])
#define PLC_BIT_M1536_ON(x)		(PLC_RAM8(PLC_R_START_ADD+0x5720+((x)/8))			|=PLC_BIT_OR[(x)%8])
#define PLC_BIT_M1536_OFF(x)		(PLC_RAM8(PLC_R_START_ADD+0x5720+((x)/8))			&=PLC_BIT_AND[(x)%8])

#define PLC_O_BIT_TEST(x)	(PLC_RAM8(PLC_R_START_ADD+0x0600+((x)/8)) 	& PLC_BIT_OR[(x)%8])
#define PLC_O_BIT_OFF(x)	(PLC_RAM8(PLC_R_START_ADD+0x0600+((x)/8)) 	&= PLC_BIT_AND[(x)%8])
#define PLC_O2_BIT_TEST(x)	(PLC_RAM8(PLC_R_START_ADD+0x0400+((x)/8)) 	& PLC_BIT_OR[(x)%8])
#define PLC_O2_BIT_OFF(x)	(PLC_RAM8(PLC_R_START_ADD+0x0400+((x)/8)) 	&= PLC_BIT_AND[(x)%8])

#define PLC_O_M1536_BIT_TEST(x)	(PLC_RAM8(PLC_R_START_ADD+0x58A0+((x)/8)) 	& PLC_BIT_OR[(x)%8])
#define PLC_O2_M1536_BIT_TEST(x)	(PLC_RAM8(PLC_R_START_ADD+0x57E0+((x)/8)) 	& PLC_BIT_OR[(x)%8])

//PLS(F) Y M
#define PLC_PL_BIT_TEST(x)		(PLC_RAM8(PLC_R_START_ADD+0X0200+((x)/8)) & PLC_BIT_OR[(x)%8])
#define PLC_PL_BIT_ON(x)		(PLC_RAM8(PLC_R_START_ADD+0X0200+((x)/8)) |=PLC_BIT_OR[(x)%8])
#define PLC_PL_BIT_OFF(x)		(PLC_RAM8(PLC_R_START_ADD+0X0200+((x)/8)) &=PLC_BIT_AND[(x)%8])
#define PLC_PL_M1536_BIT_TEST(x)		(PLC_RAM8(PLC_R_START_ADD+0x5960+((x)/8)) & PLC_BIT_OR[(x)%8])
#define PLC_PL_M1536_BIT_ON(x)		(PLC_RAM8(PLC_R_START_ADD+0x5960+((x)/8)) |=PLC_BIT_OR[(x)%8])
#define PLC_PL_M1536_BIT_OFF(x)		(PLC_RAM8(PLC_R_START_ADD+0x5960+((x)/8)) &=PLC_BIT_AND[(x)%8])
 //T
#define PLC_T_OUT_BIT_TEST(x) (PLC_RAM8(PLC_R_START_ADD+0x00C0+((x)/8)) 	& PLC_BIT_OR[(x)%8])
#define PLC_T_OUT_BIT_ON(x)	  (PLC_RAM8(PLC_R_START_ADD+0x00C0+((x)/8))	|=PLC_BIT_OR[(x)%8])
#define PLC_T_OUT_BIT_OFF(x)  (PLC_RAM8(PLC_R_START_ADD+0x00C0+((x)/8))	&=PLC_BIT_AND[(x)%8])
#define PLC_T_C_BIT_TEST(x)	  (PLC_RAM8(PLC_R_START_ADD+0x02C0+((x)/8)) 	& PLC_BIT_OR[(x)%8])
#define PLC_T_C_BIT_ON(x)	  (PLC_RAM8(PLC_R_START_ADD+0x02C0+((x)/8))	|=PLC_BIT_OR[(x)%8])
#define PLC_T_C_BIT_OFF(x)	  (PLC_RAM8(PLC_R_START_ADD+0x02C0+((x)/8))	&=PLC_BIT_AND[(x)%8])
//RST T
#define PLC_T_RST_TEST(x)	(PLC_RAM8(PLC_R_START_ADD+0x0240+((x)/8)) 	& PLC_BIT_OR[(x)%8])
#define PLC_T_RST_ON(x)	    (PLC_RAM8(PLC_R_START_ADD+0x0240+((x)/8))	|=PLC_BIT_OR[(x)%8])
#define PLC_T_RST_OFF(x)    (PLC_RAM8(PLC_R_START_ADD+0x0240+((x)/8))	&=PLC_BIT_AND[(x)%8])
//C
#define PLC_C_C_BIT_TEST(x)	(PLC_RAM8(PLC_R_START_ADD+0x03C0+((x)/8)) 	& PLC_BIT_OR[(x)%8])
#define PLC_C_OUT_BIT_ON(x)	(PLC_RAM8(PLC_R_START_ADD+0x01C0+((x)/8))	|=PLC_BIT_OR[(x)%8])
#define PLC_C_OUT_BIT_OFF(x)(PLC_RAM8(PLC_R_START_ADD+0x01C0+((x)/8))	&=PLC_BIT_AND[(x)%8])
#define PLC_C_OUT_BIT_TEST(x) (PLC_RAM8(PLC_R_START_ADD+0x01C0+((x)/8)) 	& PLC_BIT_OR[(x)%8])
#define PLC_C_C_BIT_ON(x)	(PLC_RAM8(PLC_R_START_ADD+0x03C0+((x)/8))	|=PLC_BIT_OR[(x)%8])
#define PLC_C_C_BIT_OFF(x)	(PLC_RAM8(PLC_R_START_ADD+0x03C0+((x)/8))	&=PLC_BIT_AND[(x)%8])
//RST C
#define PLC_C_RST_TEST(x)	(PLC_RAM8(PLC_R_START_ADD+0x0280+((x)/8)) 	& PLC_BIT_OR[(x)%8])
#define PLC_C_RST_ON(x)	    (PLC_RAM8(PLC_R_START_ADD+0x0280+((x)/8))	|=PLC_BIT_OR[(x)%8])
#define PLC_C_RST_OFF(x)    (PLC_RAM8(PLC_R_START_ADD+0x0280+((x)/8))	&=PLC_BIT_AND[(x)%8])
//X Y
#define PLC_X_BIT_ON(x)		(PLC_RAM8(PLC_R_START_ADD+0x0080+((x)/8))	|=PLC_BIT_OR[(x)%8])
#define PLC_X_BIT_OFF(x)	(PLC_RAM8(PLC_R_START_ADD+0x0080+((x)/8))	&=PLC_BIT_AND[(x)%8])
#define PLC_Y_C_BIT_TEST(x)	(PLC_RAM8(PLC_R_START_ADD+0x00A0+((x)/8)) 	& PLC_BIT_OR[(x)%8])
//FNC(P)
#define PLC_FNC_P_BIT_TEST(x)(PLC_RAM8(PLC_R_START_ADD+0x4E80+(((x)/2)/8)) 	& PLC_BIT_OR[((x)/2)%8])
#define PLC_FNC_P_BIT_ON(x)	 (PLC_RAM8(PLC_R_START_ADD+0x4E80+(((x)/2)/8))	|=PLC_BIT_OR[((x)/2)%8])
#define PLC_FNC_P_BIT_OFF(x) (PLC_RAM8(PLC_R_START_ADD+0x4E80+(((x)/2)/8))	&=PLC_BIT_AND[((x)/2)%8])
//P0-P127
#define PLC_P_TEST(x)   (PLC_RAM8(PLC_R_START_ADD+0x5800+((x)/8)) 	& PLC_BIT_OR[(x)%8])
#define PLC_P_ON(x)	    (PLC_RAM8(PLC_R_START_ADD+0x5800+((x)/8))	|=PLC_BIT_OR[(x)%8])
/******************************************************************************/

extern void init_timer(uint8 timer_num, uint32 timerInterval );
extern void enable_timer(uint8 timer_num );
extern void disable_timer(uint8 timer_num );
//extern void reset_timer( uint8 timer_num );
extern void bod_init (void);
extern uint32_t UARTInit(uint32_t portNum, uint32_t Baudrate );
extern void PLC_RESET_RAM(void);
extern void PLC_PROG_RUN(void);
extern void PLC_T_COUNT(void);
extern void PLC_M_MS(void);
/*********************���ݸ�λ***********************************************/
extern void PLC_PowerUpReset(void);

/*********************���ݲ���***********************************************/
extern void   PLC_ByteWrite64(uint32 pc,uint32 Data,uint32 Data2);
extern void   PLC_ByteWrite32(uint32 pc,uint32 Data);//32λд
extern void   PLC_ByteWrite16(uint32 pc,uint16 Data);//16λд
extern uint32 PLC_ByteRead32(uint32 pc);//32λ��
extern uint16 PLC_ByteRead16(uint32 pc);//16λ��
extern void   PLC_ProgDataTest(uint32 pc,uint8 count);//ר���ڳ���ʼ����
extern void   PLC_ByteReset(uint16 BitStartAdd,uint16 BitEndAdd);//�ֽ�����������λ
extern void   PLC_BitReset(uint16 BitStartAdd,uint16 BitEndAdd);//λ����������λ
extern uint32 PLC_ProgTypeAddReturn(uint32 pc);//�ӳ����з������ͼ���ַ
extern uint16 PLC_ProgTypeReturn(uint32 pc);//�ӳ����з�������
extern uint16 PLC_ProgAddReturn(uint32 pc);//�ӳ����з��ص�ַ
/*********************����ָ��***********************************************/
extern uint8  Y0_H_OE,Y1_H_OE;
extern uint16 PWM_Y0_ON_TIMER,PWM_Y0_CYCLE,PWM_Y0_COUNT;
extern uint16 PWM_Y1_ON_TIMER,PWM_Y1_CYCLE,PWM_Y1_COUNT;
extern uint8  PLSY_Y0_CCW,PLSY_Y1_CCW;
extern uint32 PLSY_Y0_COUNT,PLSY_Y1_COUNT;
extern void   PLC_PWM_RUN(uint16 PWM_Width,uint16 PWM_Cycle,uint16 Y_num);
extern void   PLC_PWM_STOP(uint16 Y_num);
extern void   PLC_PLSY_RUN(uint32 PLSY_Frequency,uint32 PLSY_Count,uint16 Y_num);
extern void   PLC_PLSY_STOP(uint16 Y_num);
extern void   H_Y0_Y1_STOP(void);
#endif   
/*********************************************************************************************************
**                            End Of File
********************************************************************************************************/