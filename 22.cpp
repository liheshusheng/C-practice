#include<stdio.h>
#include<dos.h>
#include<stdlib.h>
#include<conio.h>
#include<iostream>
#include<windows.h>
#define P_NUM 5
#define P_TIME 50

using namespace std;
enum state{
ready, 
execute,
block,
finish,
};//定义进程状态
struct pcb{
char name[4];//进程名
int priority;//优先权
int cputime;//CPU运行时间
int needtime;//进程运行所需时间
int count;//进程执行次数
int round;//时间片轮转轮次

state process;//进程状态
pcb *next;

};//定义进程PCB
pcb*getprocess(){
pcb *q;
pcb *t;
pcb *p; 
pcb*g;//多加一个g 
int i=0;
cout<<"inputnameandtime请输入名字和时间"<<endl;
while(i<P_NUM){// 多一个5 
	//float g;
g=(struct pcb*)malloc(sizeof(pcb));//pcb*g=(struct pcb*)malloc(sizeof(pcb));编译无错误 //
cin>>q->name;
cin>>q->needtime;
q->cputime=0;




q->priority=P_TIME-q->needtime;//q->priority-pTIME-G->needtime,//搞不懂,
q->process=ready; 
q->next=NULL;
}
if(i==0){
p=q;
t=q;}
else{
t->next=q;//创建就绪进程队列
t=q;
}
i++;
//while
return p;
}//输入模拟测试的进程名和执行所需时间，初始设置可模拟5个进程的调度
void display(pcb*p)
{
cout<<"名字"<<""<<"CPU时间"<<""<<"需要时间"<<""<<"优先权"<<""<<"state"<<endl;
while(p){
cout<<p->name;
cout<<"";
cout<<p->cputime;
cout<<"";
cout<<p->needtime;
cout<<"";
cout<<p->priority;
cout<<"";
switch(p->process){
case ready:cout<<"ready"<<endl;break;
case execute:cout<<"execute"<<endl;break;
case block:cout<<"block"<<endl;break;
case finish:cout<<"finish"<<endl;break;
}
p=p->next;
}//显示模拟结果，包含进程名、CPU时间、运行所需时间以及优先级
}




int process_finish(pcb*q) //intprocess_finish(pcbq){
{
int bl=1;//intbl=1;

while(bl&&q){//while(bl&&q){
bl=bl&&q->needtime==0;
q=q->next;
}
return bl ;//returnbli
}//结束进程，即将队列中各进程的所需时间设置为0



 
void cpuexe(pcb *q)
{

pcb*t=q;
int tp=0;
while(q){
if(q->process!=finish){
q->process=ready;
if(q->needtime=0){
q->process=finish;
}
}
if(tp<q->priority&&q->process!=finish)
{
tp=q->priority;
t=q;
}
q=q->next;
}
if(t->needtime!=0){
t->priority-=3;
t->needtime--;
t->process=execute;
t->cputime++;
}
}
//选择某一进程，给它分配CPU
//计算进程优先级


void prioritycal()
{
pcb*p;
system("cls");

//clrscr();
p=getprocess();//p=getprocess();
int cpu=0;
system("cls");
//clrscr();
while(!process_finish(p)){
cpu++;
cout<<"cputime:"<<cpu<<endl;
cpuexe(p);
display(p);//display(p);
Sleep(2);
//system("cls");
//clrscr();
}
printf("所有的进程都已完成");
getch();
}

void displaymenu()
{
cout<<"选择算法:"<<endl;//choose the algorithm 
cout<<"1优先权"<<endl;
cout<<"2循环"<<endl;
cout<<"3退出"<<endl;
//显示调度算法菜单，可供用户选择优先权调度算法和时间片轮转调度算法
}




pcb*getprocess_round(){
pcb*q;
pcb*t;
pcb*p;
pcb*g; //多添加一个g 
int i=0;
cout<<"输入名字和时间"<<endl;
while(i<P_NUM) //多一个5 
{
q=(struct pcb*)malloc(sizeof(pcb));
cin>>g->name;
cin>>g->needtime;
q->cputime=0;
q->round=0;
q->count=0;
q->process=ready;
g->next=NULL;
if(i==0){
p=q;
t=q;
}
else{
t->next=q;
t=q;
}
i++;
}//whilereturn q;
////while
return p;//
}//时间片轮转调度算法创建就绪进程队列

void cpu_round(pcb*q)
{
 
q->cputime+=2;
q->needtime-=2;
if(q->needtime<0){
q->needtime=0;
}
q->count++;
q->round++;
q->process=execute;
}//采用时间片轮转调度算法执行某一进程


pcb*get_next(pcb*k,pcb*head)
{


pcb*t;
t=k;
do{
t=t->next;
}
while(t&&t->process==finish);
if(t==NULL){
t=head;
while(t->next!=k&&t->process==finish){
t=t->next;
}
}
return t;
}//获取下一个进程




void setstate(pcb*p)
{
while(p){
if(p->needtime==0){
p->process=finish;//如果所需执行时间为0，则设置运行状态为结東
}
if(p->process==-execute){
p->process=ready;//如果为执行状态则设置为就绪
}
p=p->next;
}
}
//设置队列中进程执行状态
void display_round(pcb*p)
{
cout<<"名字"<<" "<<"CPU时间"<<" "<<"需要时间"<<" "<<"OOUNT"<<" "<<"ROUTND"<<" "<<"state"<<endl;//cout<"NAME"<<""<<"CPUTIME"<<""<<"NEEDTIME"<<""<<"OOUNT"<<""<<"ROUTND"<<""<<"STATE"<<endl;
//cout<<"name名字"<<""<<"cputimeCPU时间"<<""<<"needtime"<<""<<"priority"<<""<<"state"<<endl
while(p){
cout<<p->name;
cout<<"";
cout<<p->cputime;
cout<<"";
cout<<p->needtime;
cout<<"";
cout<<p->count;
cout<<"";
cout<<p->round;
cout<<"";
switch(p->process){
case ready:cout<<"ready"<<endl;break;
case execute:cout<<"execute"<<endl;break;
case finish:cout<<"finish"<<endl;break;
}
p=p->next;
}
}//时间片轮转调度算法输出调度信息}

void round_cal(){
pcb*p;
pcb*r;
system("cls");
//clrscr();
p=getprocess_round();
int cpu=0;
system("cls");//中间是一 
//clrscr;
r=p;
while(!process_finish(p)){
cpu+=2;
cpu_round(r);
r=get_next(r,p);
cout<<"cpu"<<cpu<<endl;
display_round(p); 
setstate(p);
Sleep(5);
//system("cls");
//clrsrc();
}
}//时间片轮转调度算法计算轮次及输出调度信息

int main(){
displaymenu();
int k;
scanf("%d",&k);
switch(k){
case 1:prioritycal();break;
case 2:round_cal();break;
case 3:break;
displaymenu();
scanf("%d",&k);
}

}
