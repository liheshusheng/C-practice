#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<stdio.h>
using namespace std;
struct pcb
{
int status;
int length;
}*PCB[3]; 
struct req
{
int reqname;
int length;
int addr;
}reqblock[10];
int buffer[2][100];
int head=0,tail=0;
int t1=5,t2=5;
void request(int i);//i=1表示用户进程1；i=2表示用户进程2
void spooling();
int main()
{
for(int l=0;l<2;l++)
for(int j=0;j<100;j++)
buffer[l][j]=0;
for(int n=0;n<3;n++)
{
struct pcb * tmppcb=(struct pcb*)malloc(sizeof(struct pcb));
tmppcb->status=0;
tmppcb->length=0;
PCB[n]=tmppcb;
cout<<"两个用户进程的请求分别为5，5"<<endl;
}
srand((unsigned)time(NULL));
	while(1)
	{
		int k;
		k=rand()%100;
		printf("当前k的值为%d\n",k);
		if(k<=45)
		{
			if((0==PCB[0]->status)&&(t1>0))
			request(1);
		}
		else if((k<=90)&&(t2>0))
		{
			if(0==PCB[1]->status)
			{
				request(2);
			}
		}
		else
			spooling();
		if((0==t1)&&(0==t2)&&(head==tail))
			break;
		for(int m=0;m<3;m++)
		{
		free(PCB[m]);
		PCB[m]=NULL;
		}
		getchar();
		}
}
void request(int i)
{
int j,length=0;
struct req * run;
if(1==i)
t1--;
else
t2--;
cout<<"用户"<<i<<"请求数据:\n";
run=&reqblock[tail%10];
run->reqname=i;
run->length=0;
if(0==tail)
run->addr=0;
else{
int index=(tail-1)%10;
run->addr=reqblock[index].addr+reqblock[index].length;
}
for(int m=0;m<100;m++)
{
if(0==buffer[i-1][m])
{
run->addr=m;
break;
}
}
int s=0;
while(1){
j=rand()%10;
if(0==j){
run->length=length;
break;
}
buffer[i-1][(run->addr+length)]=s;
cout<<s<<"";
s++;
length++;
}
cout<<endl;
PCB[i-1]->length+=length;
length=0;
if(2==PCB[2]->status)
PCB[2]->status=0;
tail++;
}
void spooling()
{
struct req  *run;
cout<<"调用SPOOLING输出服务程序输出数据:"<<endl;
run=&reqblock[head%10];
cout<<run->reqname<<":\n";
for(int  i=0;i<run->length;i++)
cout<<buffer[run->reqname-1][run->addr+i]<<"";
cout<<endl;
head++;
for(int j=0;j<2;j++)
{
if(3==PCB[j]->status)//若没有可用请求块时，调用进程进入“等待状态3
PCB[j]->status=0;
}
}
