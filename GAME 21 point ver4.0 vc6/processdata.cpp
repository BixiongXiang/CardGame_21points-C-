
#include <time.h>
#include <windows.h>


int RandomNum(int t,int d)           //���������
{
	int a;
	//srand(time(NULL));  /*��ʼ�����������*/
	
	a=rand()%(d-t)+t;  /*����һ��[t,d)�����ڵ�����*/  //rand����һ�������a ��a%4��������Χ[0,4)  ������10-13��ȡֵ���� rand%4 + 10

	if(a>=11)
	{a=10;}

	return a;
}

