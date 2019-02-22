

int s_OneMorePoker(int s1,int s2,int p1,int difficulty)
{
	int sum = s1 + s2,j=0;
	switch(difficulty)
	{
	case 1:
	return sum<=15?1:0;                //1-要牌 0-不要牌
	

	//////////////////////
	case 2:
		{int c1=0,c2=0,h=0;
	s1<=6 ? (c1=1) : (s1>=10 ? c1=-1: c1=0);
	s2<=6 ? c2=1 : (s2>=10 ? c2=-1: c2=0);
	p1<=6 ? h=1 : (p1>=10 ? h=-1: h=0);

	if(c1+c2>0)
	{return 1;}

	if(c1+c2<0)
	{return 1;}

	if(s1+s2-p1<=8)
	{return 1;}

	else {return 0;}}

	}
return 0;
}

/*AI数据分析：

j>0.75输出

*/
