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
};//�������״̬
struct pcb{
char name[4];//������
int priority;//����Ȩ
int cputime;//CPU����ʱ��
int needtime;//������������ʱ��
int count;//����ִ�д���
int round;//ʱ��Ƭ��ת�ִ�

state process;//����״̬
pcb *next;

};//�������PCB
pcb*getprocess(){
pcb *q;
pcb *t;
pcb *p; 
pcb*g;//���һ��g 
int i=0;
cout<<"inputnameandtime���������ֺ�ʱ��"<<endl;
while(i<P_NUM){// ��һ��5 
	//float g;
g=(struct pcb*)malloc(sizeof(pcb));//pcb*g=(struct pcb*)malloc(sizeof(pcb));�����޴��� //
cin>>q->name;
cin>>q->needtime;
q->cputime=0;




q->priority=P_TIME-q->needtime;//q->priority-pTIME-G->needtime,//�㲻��,
q->process=ready; 
q->next=NULL;
}
if(i==0){
p=q;
t=q;}
else{
t->next=q;//�����������̶���
t=q;
}
i++;
//while
return p;
}//����ģ����ԵĽ�������ִ������ʱ�䣬��ʼ���ÿ�ģ��5�����̵ĵ���
void display(pcb*p)
{
cout<<"����"<<""<<"CPUʱ��"<<""<<"��Ҫʱ��"<<""<<"����Ȩ"<<""<<"state"<<endl;
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
}//��ʾģ������������������CPUʱ�䡢��������ʱ���Լ����ȼ�
}




int process_finish(pcb*q) //intprocess_finish(pcbq){
{
int bl=1;//intbl=1;

while(bl&&q){//while(bl&&q){
bl=bl&&q->needtime==0;
q=q->next;
}
return bl ;//returnbli
}//�������̣����������и����̵�����ʱ������Ϊ0



 
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
//ѡ��ĳһ���̣���������CPU
//����������ȼ�


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
printf("���еĽ��̶������");
getch();
}

void displaymenu()
{
cout<<"ѡ���㷨:"<<endl;//choose the algorithm 
cout<<"1����Ȩ"<<endl;
cout<<"2ѭ��"<<endl;
cout<<"3�˳�"<<endl;
//��ʾ�����㷨�˵����ɹ��û�ѡ������Ȩ�����㷨��ʱ��Ƭ��ת�����㷨
}




pcb*getprocess_round(){
pcb*q;
pcb*t;
pcb*p;
pcb*g; //�����һ��g 
int i=0;
cout<<"�������ֺ�ʱ��"<<endl;
while(i<P_NUM) //��һ��5 
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
}//ʱ��Ƭ��ת�����㷨�����������̶���

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
}//����ʱ��Ƭ��ת�����㷨ִ��ĳһ����


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
}//��ȡ��һ������




void setstate(pcb*p)
{
while(p){
if(p->needtime==0){
p->process=finish;//�������ִ��ʱ��Ϊ0������������״̬Ϊ��|
}
if(p->process==-execute){
p->process=ready;//���Ϊִ��״̬������Ϊ����
}
p=p->next;
}
}
//���ö����н���ִ��״̬
void display_round(pcb*p)
{
cout<<"����"<<" "<<"CPUʱ��"<<" "<<"��Ҫʱ��"<<" "<<"OOUNT"<<" "<<"ROUTND"<<" "<<"state"<<endl;//cout<"NAME"<<""<<"CPUTIME"<<""<<"NEEDTIME"<<""<<"OOUNT"<<""<<"ROUTND"<<""<<"STATE"<<endl;
//cout<<"name����"<<""<<"cputimeCPUʱ��"<<""<<"needtime"<<""<<"priority"<<""<<"state"<<endl
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
}//ʱ��Ƭ��ת�����㷨���������Ϣ}

void round_cal(){
pcb*p;
pcb*r;
system("cls");
//clrscr();
p=getprocess_round();
int cpu=0;
system("cls");//�м���һ 
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
}//ʱ��Ƭ��ת�����㷨�����ִμ����������Ϣ

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
