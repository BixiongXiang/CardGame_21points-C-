
#include <time.h>
#include <windows.h>


int RandomNum(int t,int d)           //产生随机数
{
	int a;
	//srand(time(NULL));  /*初始化随机数种子*/
	
	a=rand()%(d-t)+t;  /*生成一个[t,d)区间内的整数*/  //rand产生一个随机数a 若a%4则余数范围[0,4)  所以在10-13间取值就是 rand%4 + 10

	if(a>=11)
	{a=10;}

	return a;
}

