//1路继电器模块测试程序
//单片机:AT89S52
//系统晶振:12MHz
#include <reg52.h>
#define uchar unsigned char
#define uint  unsigned int
//引脚定义
sbit Relay1=P2^0;
sbit Relay2=P2^1;
//功能:延时1毫秒
//入口参数:x
//出口参数:无
//说明:晶振为12M
void Delay_xms(uint x)
{
  uint i,j;
  for(i=0;i<x;i++)
    for(j=0;j<112;j++);
}
//功能:继电器闭合
void Relay1_On(void)
{
 Relay1=0; 
}
//功能:继电器断开
void Relay1_Off(void)
{
 Relay1=1; 
}
//功能:继电器闭合
void Relay2_On(void)
{
 Relay2=0; 
}
//功能:继电器断开
void Relay2_Off(void)
{
 Relay2=1; 
}
//主函数
void main(void)
{
 Delay_xms(50);//等待系统稳定
 while(1)
 {
  Relay1_On();     //继电器吸合
  Delay_xms(2000);//延时2秒
  Relay1_Off();    //继电器断开
  Delay_xms(2000);//延时2秒
  Relay2_On();     //继电器吸合
  Delay_xms(2000);//延时2秒
  Relay2_Off();    //继电器断开
  Delay_xms(2000);//延时2秒
 }
}