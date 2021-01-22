#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct jincheng_type{
int pid;
int youxian;
int daxiao;

int zhuangtai;//标识进程状态，0-不在内存，1-在内存，2-阻塞
char info[10];
};
struct jincheng_type neicun[20];
int shumu=0,zhuse=0,flag=0,pid;



void create()

{

if(shumu>=20)
printf("\n内存已满，请先唤醒或杀死进");
else{

	int i;
for(i=0;i<20;i++)


//定位，找到可以还未创建的进程
if (neicun[i].zhuangtai==0)break;

printf("\n请输入新进程pid\n");

scanf("%d",&(neicun[i].pid));
for(int j=0;j<i;j++)

if(neicun[i].pid==neicun[j].pid){
printf("\n该进程已存在n");
break;
}
{
printf("\n请输入新进程优先级\n");
scanf("%d",&(neicun[i].youxian));
printf("\n请输入新进程大小\n");
scanf("%d",&(neicun[i].daxiao));
printf("\n请输入新进程内容\n");
scanf("%s",&(neicun[i].info));}
//创建进程，使标记位为1
neicun[i].zhuangtai=1;
shumu++;
}
}

void run()
{
for(int i=0;i<20;i++){
if(neicun[i].zhuangtai==1){
//输出运行进程的各个属性值
printf("\npid=%d",neicun[i].pid);
printf("优先级=%d",neicun[i].youxian);
printf("大小=%d",neicun[i].daxiao);
printf("状态=%d",neicun[i].zhuangtai);
printf("info=%s",neicun[i].info);
flag=1;
}
}
if  (! flag)
printf("\n当前没有运行进程\n");
}

void zuse()
{
if(!shumu){
printf("当前没有运行进程\n");
return ;
}
printf("\n输人阻塞进程的ID值");
scanf("%d",&pid);
for(int i=0;i<20;i++){
//定位，找到所要唤醒的进程，根据其状态做相应处理
if(pid==neicun[i].pid){
if(neicun[i].zhuangtai==1){
neicun[i].zhuangtai=2;
zhuse++;
printf("\n已经成功阻塞进程\n");
}
else if (neicun[i].zhuangtai==0)


printf("\n要阻塞的进程不存在\"n");}

else
printf("\n要阻塞的进程已被阻塞\n");
flag=1;
break;}
//找不到，则说明进程不存在
if(flag==0)
printf("\n要阻塞的进程不存在\n");
}

 


void kill()
{
if(!shumu){
printf("当前没有运行进程\n");
return ;
}
printf("\n输入杀死进程的工ID值");
scanf("%d",&pid);
for(int i=0;i<20;i++){
//定位，找到所要杀死的进程，根据其状态做相应处理
if(pid==neicun[i].pid){
if(neicun[i].zhuangtai==1){
neicun[i].zhuangtai==0;
shumu--;
printf("\n已成功杀死进程\n");
}
else if (neicun[i].zhuangtai==0)
printf("\n:要杀死的进程不存在\n");
else printf("\n要杀死的进程已被阻塞\n");
flag=1;
break;
}
}
//找不到，则说明进程不存在
if(!flag)
printf("\n要杀死的进程不存在\n");
}



void huanxing()
{
if(!shumu){
printf("\n当前没有运行进程\n");
return;
}
if(! zhuse)
{
printf("\n当前没有阻塞进程\n");
return;
}

printf("\n输人pid：\n");
scanf("%d",pid);
for(int i=0;i<20;i++)
//定位，找到所要杀死的进程，根据其状态做相应处理
if(pid==neicun[i].pid){
flag=false;
if(neicun[i].zhuangtai==2){
neicun[i].zhuangtai==1;
zhuse--;
printf("\n已经成功唤醒进程\n");
}
else if(neicun[i].zhuangtai==0) 
printf("\n要唤醒的进程不存在\n");
else printf("\n要唤醒的进程已被阻塞\n");
break;}
//找不到，则说明进程不存在
if(! flag)
printf("\n要唤醒的进程不存在\n");
}

 
int  main(){
int n=1;
int num;

//一开始所有进程都不在内存中
for(int i=0;1<20;i++){
neicun[i].zhuangtai=0;
while(n){
printf("\n*****************""*****************************************");
printf("\n*******************进程演示系统***********************");
printf("\n***********************************************************");
printf("\n*1. 创建新的进程2．查看运行进程");
printf("\n*3．唤醒某个进程4．杀死运行进程");
printf("\n*5．阻塞某个进程6．退出系统");
printf("\n************************************************************");
printf("\n请选择（1～6）\n");
scanf("%d",&num);
switch(num){
case 1:create();break;
case 2:run();break;
case 3:huanxing();break;
case 4:kill();break;
case 5:zuse();break;
case 6:exit(0);
default:n=0;
}
flag=0;//恢复标记
}
}
}
 
