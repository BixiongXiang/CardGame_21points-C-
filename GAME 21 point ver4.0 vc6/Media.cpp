#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>

void Opening()
{
	initgraph(400, 300); 
	IMAGE img;	// ���� IMAGE ����

	/*loadimage(&img, "./image/1.jpg");	// ��ȡͼƬ�� img ������  ���·��./��ʾ��ǰ·����  ����·������E:\\1.txt
	putimage(0,0, &img);	// ������ (0, 0) λ����ʾ IMAGE ����*/

	loadimage(&img, "./image/title1.graphic");	
	putimage(0,0, &img);
	Sleep(400);
	loadimage(&img, "./image/title2.graphic");	
	putimage(0,0, &img);
	Sleep(400);
	loadimage(&img, "./image/title3.graphic");	
	putimage(0,0, &img);
	Sleep(400);
	loadimage(&img, "./image/title4.graphic");	
	putimage(0,0, &img);
	Sleep(400);

	getch();
	closegraph();
}