#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>

void Opening()
{
	initgraph(400, 300); 
	IMAGE img;	// 定义 IMAGE 对象

	/*loadimage(&img, "./image/1.jpg");	// 读取图片到 img 对象中  相对路径./表示当前路径下  绝对路径用如E:\\1.txt
	putimage(0,0, &img);	// 在坐标 (0, 0) 位置显示 IMAGE 对象*/

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