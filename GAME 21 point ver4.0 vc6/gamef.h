typedef struct uInfo
{
	char name[10];
	int win;
	int num;
	double wins;
}user;

int RandomNum(int t,int d);
void getpoker(int r);
int s_OneMorePoker(int s1,int s2,int p1,int difficulty);
void result(int r,double *pwin);
int JudgeResult(int p,int s);
void intro();

void FileWrite(int win,int num);
user *FileRead(int *usernum);
void sort(user **p,int usernum);

void Opening();



