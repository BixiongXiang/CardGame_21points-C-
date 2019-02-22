#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "gamef.h"

//***************************************
//*�û��ɼ�����(��-С)
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
//*��ȡ�û���Ϣ
//***************************************
user *FileRead(int *usernum)
{
	int i=0;    
	int readnum=0; //ÿ�ζ�ȡ��Ԫ�ظ���
	user *p;       //���ڷ��ʽṹ���ָ��
	
//*************************************
//*�������Ƿ�ɹ�
//*************************************
	p = (user *)malloc(2*sizeof(user));
	if(p==NULL){puts("ERRO");system("pause");
	//return 0;
	}  

//*************************************
//*����Ƿ�ɹ���
//*************************************
	FILE *fp;
	fp = fopen("SaveData.sav","r");
	if(fp==NULL)//�����浵�ļ�
	{
		puts("*** No Data!   Creatting a new SaveData...  ***");
		//fclose(fp);
		fp = fopen("SaveData.sav","w");
		fclose(fp);
		fp = fopen("SaveData.sav","r");

		if(fp==NULL)
		{puts("*** Read Failed! Unknow Error! ***");system("pause");exit(0);}//�ٴζ�ȡʧ�ܹرճ���
		else
		{puts("Save Data Creat Successful!");}
		system("pause");
	}

	

	do
	{
		//*************************************
		//*��̬��������Ľṹ��
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
		//*���ļ���ȡ�û���Ϣ
		//*************************************
		readnum = fscanf(fp,"%s%d%d",&p[i].name,&p[i].win,&p[i].num);
		p[i].num == 0 ? p[i].wins=0: p[i].wins=(double)p[i].win / p[i].num;
		//*************************************
		//*����ȡ��Ϣ�Ƿ���ȫ��ȷ
		//*************************************
		if(readnum<3 && readnum != EOF)
		{puts("Read Cotent Failed!");system("pause");
		//return 0;
		}

		
		i++;
	}while(readnum != EOF);

	fclose(fp);
	*usernum = i-1;

	sort(&p,*usernum);//�û�����

	return p;
}




//***************************************
//*�����û���Ϣ
//***************************************

void FileWrite(int win,int num)
{
	int WriteCheck=0;
	char UserName[20],NewFileName[25]="SaveData",suffix[5]=".sav";
	FILE *fp;

	puts("Please enter your name:");
	scanf("%19s",UserName); //�������벻Խ��
	//strcpy(NewFileName,UserName);
	strcat(NewFileName,suffix);//�����û������׺

	fp = fopen(NewFileName,"a");//�����ļ�

	WriteCheck = fprintf(fp,"%s %d %d\n\n",UserName,win,num);//д���ı�

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
	fclose(fp);   //һ��Ҫ��Ҫ��Ȼд�����ӳ�

}