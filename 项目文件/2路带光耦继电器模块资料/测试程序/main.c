//1·�̵���ģ����Գ���
//��Ƭ��:AT89S52
//ϵͳ����:12MHz
#include <reg52.h>
#define uchar unsigned char
#define uint  unsigned int
//���Ŷ���
sbit Relay1=P2^0;
sbit Relay2=P2^1;
//����:��ʱ1����
//��ڲ���:x
//���ڲ���:��
//˵��:����Ϊ12M
void Delay_xms(uint x)
{
  uint i,j;
  for(i=0;i<x;i++)
    for(j=0;j<112;j++);
}
//����:�̵����պ�
void Relay1_On(void)
{
 Relay1=0; 
}
//����:�̵����Ͽ�
void Relay1_Off(void)
{
 Relay1=1; 
}
//����:�̵����պ�
void Relay2_On(void)
{
 Relay2=0; 
}
//����:�̵����Ͽ�
void Relay2_Off(void)
{
 Relay2=1; 
}
//������
void main(void)
{
 Delay_xms(50);//�ȴ�ϵͳ�ȶ�
 while(1)
 {
  Relay1_On();     //�̵�������
  Delay_xms(2000);//��ʱ2��
  Relay1_Off();    //�̵����Ͽ�
  Delay_xms(2000);//��ʱ2��
  Relay2_On();     //�̵�������
  Delay_xms(2000);//��ʱ2��
  Relay2_Off();    //�̵����Ͽ�
  Delay_xms(2000);//��ʱ2��
 }
}