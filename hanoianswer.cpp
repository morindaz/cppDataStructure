#include <stdio.h>
//��һ����Ϊ��ʼ�����м����Ϊ�����������һ����ΪĿ����
int i=1;//��¼����
void move(int n,char from,char to) //�����Ϊn��������from�ƶ���to
{printf("��%d��:��%d������%c---->%c\n",i++,n,from,to);
}
void hanoi(int n,char from,char denpend_on,char to)//��n�������ɳ�ʼ���ƶ���Ŀ����(���ý�����)
{
    if (n==1)
    move(1,from,to);//ֻ��һ��������ֱ�ӽ������ϵ������ƶ���Ŀ�ĵ�
    else
    {
      hanoi(n-1,from,to,denpend_on);//�Ƚ���ʼ����ǰn-1�����ӽ���Ŀ�����ƶ�����������
      move(n,from,to);              //��ʣ�µ�һ�������ƶ���Ŀ������
      hanoi(n-1,denpend_on,from,to);//��󽫽������ϵ�n-1�������ƶ���Ŀ������
    }
}
int main()
{
     printf("���������ӵĸ���:\n");
     int n;
     scanf("%d",&n);
     char x='A',y='B',z='C';
     printf("�����ƶ��������:\n");
     hanoi(n,x,y,z);
}
