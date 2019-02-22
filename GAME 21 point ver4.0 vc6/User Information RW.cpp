#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "gamef.h"

//***************************************
//*用户成绩排序(大-小)
//***************************************
void sort(user **p,int usernum)
{
	//p[0][0].wins;
	user temp;
	for(int i=0;i<usernum-1;i++)
	{
		for(int j=0;j<usernum-1-i;j++)
		{
			if(p[0][j].wins < p[0][j+1].wins)
			{
				temp = p[0][j];
				p[0][j] = p[0][j+1];
				p[0][j+1] = temp;

			}
		}
	}

}


//***************************************
//*读取用户信息
//***************************************
user *FileRead(int *usernum)
{
	int i=0;    
	int readnum=0; //每次读取的元素个数
	user *p;       //用于访问结构体的指针
	
//*************************************
//*检查分配是否成功
//*************************************
	p = (user *)malloc(2*sizeof(user));
	if(p==NULL){puts("ERRO");system("pause");
	//return 0;
	}  

//*************************************
//*检查是否成功打开
//*************************************
	FILE *fp;
	fp = fopen("SaveData.sav","r");
	if(fp==NULL)//创建存档文件
	{
		puts("*** No Data!   Creatting a new SaveData...  ***");
		//fclose(fp);
		fp = fopen("SaveData.sav","w");
		fclose(fp);
		fp = fopen("SaveData.sav","r");

		if(fp==NULL)
		{puts("*** Read Failed! Unknow Error! ***");system("pause");exit(0);}//再次读取失败关闭程序
		else
		{puts("Save Data Creat Successful!");}
		system("pause");
	}

	

	do
	{
		//*************************************
		//*动态分配所需的结构体
		//*************************************
		if(i!=0 && i%2==0)
		{
			user *q;
			q = (user *)realloc(p,(i+10)*sizeof(user));
			if(q==NULL){puts("ERRO");system("pause");
			//return 0;
			}
			p=q;
		}

		//*************************************
		//*从文件读取用户信息
		//*************************************
		readnum = fscanf(fp,"%s%d%d",&p[i].name,&p[i].win,&p[i].num);
		p[i].num == 0 ? p[i].wins=0: p[i].wins=(double)p[i].win / p[i].num;
		//*************************************
		//*检查读取信息是否齐全正确
		//*************************************
		if(readnum<3 && readnum != EOF)
		{puts("Read Cotent Failed!");system("pause");
		//return 0;
		}

		
		i++;
	}while(readnum != EOF);

	fclose(fp);
	*usernum = i-1;

	sort(&p,*usernum);//用户排序

	return p;
}




//***************************************
//*保存用户信息
//***************************************

void FileWrite(int win,int num)
{
	int WriteCheck=0;
	char UserName[20],NewFileName[25]="SaveData",suffix[5]=".sav";
	FILE *fp;

	puts("Please enter your name:");
	scanf("%19s",UserName); //限制输入不越界
	//strcpy(NewFileName,UserName);
	strcat(NewFileName,suffix);//连接用户名与后缀

	fp = fopen(NewFileName,"a");//创建文件

	WriteCheck = fprintf(fp,"%s %d %d\n\n",UserName,win,num);//写入文本

	if(WriteCheck < 7)
	{
		puts("Write Error!");
		system("pause");
	}
	else
	{
		puts("***  Write Success!  ***");
		Sleep(600);
	}
	fclose(fp);   //一定要有要不然写入有延迟

}