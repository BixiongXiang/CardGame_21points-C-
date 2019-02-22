// 21 point.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#include "stdafx.h"
#include "gamef.h"
#include "Structs.h"

#include <graphics.h>
#include <conio.h>

int game(int difficulty,double *pwin)                 
{
	int r,countp,player[3]={0,0,0},counts,system[3]={0,0,0};
	
//*************************************
//*(1)抽牌
//*************************************
	puts("*****正在为您抽牌……");            
	r = RandomNum(1,14);
	getpoker(r);
	if(r>=11)r=10;
	player[0]=r;
	
	r = RandomNum(1,14);
	getpoker(r);
	if(r>=11)r=10;
	player[1]=r;
	puts("*****您的牌已抽好\n");

	if((player[0]==1 || player[1]==1) && (player[0]==10 || player[1]==10 || player[0]==11 || player[1]==11 || player[0]==12 || player[1]==12 || player[0]==13 || player[1]==13))
	{
		puts("Congratulation!  you got Blackjack!");
		result(3,pwin);
		return 0;
	}
////////////////////////////////////////////////////////////////
	puts("*****庄家正在抽牌……");
	r = RandomNum(1,14);
	getpoker(r);
	if(r>=11)r=10;
	system[0]=r;
	
	r = RandomNum(1,14);
	puts("**暗牌**");
	if(r>=11)r=10;
	system[1]=r;
	puts("*****以上为庄家的牌");

	if((system[0]==1 || system[1]==1) && (system[0]==10 || system[1]==10 || system[0]==11 || system[1]==11 || system[0]==12 || system[1]==12 || system[0]==13 || system[1]==13))
	{
		puts("Maker got Blackjack!");
		result(0,pwin);
		return 0;
	}
	
//*************************************
//*(2)要牌
//*************************************
	puts("*****您是否要牌？[y/n]:");			
	getchar();
	if(getchar()=='y')
	{
		r = RandomNum(1,14);
		getpoker(r);
		if(r>=11)r=10;
		player[2]=r;
	}
	
	if(s_OneMorePoker(system[0],system[1],player[0],difficulty)==1)                 //系统判断是否要牌
	{
		r = RandomNum(1,14);
		getpoker(r);
		if(r>=11)r=10;
		system[2]=r;
	}
	
	
//*************************************
//*//(3)比大小 (4)判断结果
//*************************************	
	countp = player[0]+player[1]+player[2];							             
	counts = system[0]+system[1]+system[2];
	
	printf("***Your Point:%d\n***Maker's Point:%d\n\n",countp,counts);

	switch(JudgeResult(countp,counts))
	{ 
  	case 0:result(0,pwin);break;
	case 1:result(1,pwin);break;
 	case 2:result(2,pwin);break;
		
	}

	return 0;
}





int main(int argc, char* argv[])
{
	Opening();//开场动画

	//***************************************
	//*初始化游戏变量
	//***************************************
	int choose,usernum=0,*pun=&usernum;
	double win=0,num=0,*pwin,*pnum;
	pwin = &win;
	pnum = &num;
	srand(time(NULL));

	user *puser;
	puser = (user *)malloc(2*sizeof(user));

	//***************************************
	//*读取存档或新建存档
	//***************************************
	puser = FileRead(pun);


	while (1)
	{
		//***************************************
		//*初始化游戏界面
		//***************************************
		system("color F0");
		system("cls");
		system("title        ~~~  21 Points ver4.0-Alpha ~~~      Copyright NaHo,2015,All Right Reserved.");//版本信息

			 

		//***************************************
		//*输出胜率信息
		//***************************************
		if(num>=1)
		{
			double wins;
			wins = win/num*100;
			printf("\n		   *****  Your winning rate:[%02.2lf%%]  *****\n\n",wins);         //printf %  need %%
		}

		//***************************************
		//*开始界面
		//***************************************
		printf(
			"\n********************************************************************************"
			"\n\n	[***  1-Start Game   2-Introduction  3-Save Data  4-Rank Board ***]\n\n"
			"			Please enter your selection: ");
		scanf("%1d",&choose);
		

		switch(choose)
		{
		case 1:
			int difficulty;
			printf(
				"\n--------------------------------------------------------------------------------"
				"\n\n			     [***  1-Easy 2-Hard  ***]"
				"\n\n			        Difficulty level:");
			scanf("%d",&difficulty);
			
			system("cls");
			game(difficulty,pwin);
			
			num++;               //count number
								//count winning number
            break;  
			
			
		case 2:
			system("cls");
			intro();
			system("pause");
			break;
			
		case 3:
			FileWrite((int)win,(int)num);
			puser = FileRead(pun);
			break;

		case 4:
			system("cls");
			printf("*** Rankings ***\n\n");
			printf("Rank Wins   Name   win  number\n\n");
			for(int j=0;j<usernum;j++)
			{
				printf("<%d> [%02.2lf%%] %s : %d     %d\n\n",j+1,puser[j].wins,puser[j].name,puser[j].win,puser[j].num);
			}
			system("pause");
			break;
		}
	}
	return 0;
}
