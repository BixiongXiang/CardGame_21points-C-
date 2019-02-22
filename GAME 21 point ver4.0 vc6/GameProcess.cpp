#include "stdio.h"
#include "stdlib.h"
#include <time.h>
#include <windows.h>
#include "gamef.h"
#include <stdio.h>

//puts("\003     \004     \005     \006 \n");        club \003  spade \004  heart \005  diamon \006


int RandomNum(int t,int d);

void getpoker(int r)                          //进行一次抽牌
{	Sleep(1000);
	int p=RandomNum(1,4);
	if(p==1)
	{
		switch(r)
		{
			
		case 1:puts("\003 A  ");break;
		case 2:puts("\003 2  ");break;
		case 3:puts("\003 3  ");break;
		case 4:puts("\003 4  ");break;
		case 5:puts("\003 5  ");break;
		case 6:puts("\003 6  ");break;
		case 7:puts("\003 6  ");break;
		case 8:puts("\003 8  ");break;
		case 9:puts("\003 9  ");break;
		case 10:puts("\003 10  ");break;
		case 11:puts("\003 J  ");break;
		case 12:puts("\003 Q  ");break;
		case 13:puts("\003 K  ");break;
			
			
		}
		Sleep(500);
	}
	if(p==2)
	{
		switch(r)
		{
			
		case 1:puts("\004 A  ");break;
		case 2:puts("\004 2  ");break;
		case 3:puts("\004 3  ");break;
		case 4:puts("\004 4  ");break;
		case 5:puts("\004 5  ");break;
		case 6:puts("\004 6  ");break;
		case 7:puts("\004 6  ");break;
		case 8:puts("\004 8  ");break;
		case 9:puts("\004 9  ");break;
		case 10:puts("\004 10  ");break;
		case 11:puts("\004 J  ");break;
		case 12:puts("\004 Q  ");break;
		case 13:puts("\004 K  ");break;
			
			
		}
		Sleep(500);
	}
	
	if(p==3)
	{
		switch(r)
		{
			
		case 1:puts("\005 A  ");break;
		case 2:puts("\005 2  ");break;
		case 3:puts("\005 3  ");break;
		case 4:puts("\005 4  ");break;
		case 5:puts("\005 5  ");break;
		case 6:puts("\005 6  ");break;
		case 7:puts("\005 6  ");break;
		case 8:puts("\005 8  ");break;
		case 9:puts("\005 9  ");break;
		case 10:puts("\005 10  ");break;
		case 11:puts("\005 J  ");break;
		case 12:puts("\005 Q  ");break;
		case 13:puts("\005 K  ");break;
			
			
		}
		Sleep(500);
	}
	
	if(p==4)
	{
		switch(r)
		{
			
		case 1:puts("\006 A  ");break;
		case 2:puts("\006 2  ");break;
		case 3:puts("\006 3  ");break;
		case 4:puts("\006 4  ");break;
		case 5:puts("\006 5  ");break;
		case 6:puts("\006 6  ");break;
		case 7:puts("\006 6  ");break;
		case 8:puts("\006 8  ");break;
		case 9:puts("\006 9  ");break;
		case 10:puts("\006 10  ");break;
		case 11:puts("\006 J  ");break;
		case 12:puts("\006 Q  ");break;
		case 13:puts("\006 K  ");break;
			
			
		}
		Sleep(500);
	}
	
	
	
}

int JudgeResult(int p,int s)                   //判断结果    棋盘格法 画9宫格
{
	if(p>21&&s>21)
	{return 2;}

	if(p>21)
	{return 0;}

	if(p==21)
	{return 1;}

	if(s>21)
	{return 1;}

	if(s==21)
	{return 1;}

	if(p==s)
	{return 2;}

	

	else
	{return p>s?1:0;}
	
}



void result(int r,double *pwin)                             //输出结果
{
	if(r==0)                 //lose
	{
		
		puts("***YOU LOSE!\a  \a\a\a");
		system("color C0");
	}
	if(r==1)                 //win
	{

		*pwin=*pwin +1;
		puts("***YOU WIN!\a  \a\a\a");
		system("color A0");
	}
	if(r==2)                 //even  
	{
		
		puts("***EVEN MATCH\a  \a\a\a");
		system("color 80");
	}
	if(r==3)                //blackjack
	{
		*pwin=*pwin +1;
		puts("***YOU WIN!\a  \a\a\a");
		system("color E0");
	}
 	system("pause");
}
