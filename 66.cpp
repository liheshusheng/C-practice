#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct jincheng_type{
int pid;
int youxian;
int daxiao;

int zhuangtai;//��ʶ����״̬��0-�����ڴ棬1-���ڴ棬2-����
char info[10];
};
struct jincheng_type neicun[20];
int shumu=0,zhuse=0,flag=0,pid;



void create()

{

if(shumu>=20)
printf("\n�ڴ����������Ȼ��ѻ�ɱ����");
else{

	int i;
for(i=0;i<20;i++)


//��λ���ҵ����Ի�δ�����Ľ���
if (neicun[i].zhuangtai==0)break;

printf("\n�������½���pid\n");

scanf("%d",&(neicun[i].pid));
for(int j=0;j<i;j++)

if(neicun[i].pid==neicun[j].pid){
printf("\n�ý����Ѵ���n");
break;
}
{
printf("\n�������½������ȼ�\n");
scanf("%d",&(neicun[i].youxian));
printf("\n�������½��̴�С\n");
scanf("%d",&(neicun[i].daxiao));
printf("\n�������½�������\n");
scanf("%s",&(neicun[i].info));}
//�������̣�ʹ���λΪ1
neicun[i].zhuangtai=1;
shumu++;
}
}

void run()
{
for(int i=0;i<20;i++){
if(neicun[i].zhuangtai==1){
//������н��̵ĸ�������ֵ
printf("\npid=%d",neicun[i].pid);
printf("���ȼ�=%d",neicun[i].youxian);
printf("��С=%d",neicun[i].daxiao);
printf("״̬=%d",neicun[i].zhuangtai);
printf("info=%s",neicun[i].info);
flag=1;
}
}
if  (! flag)
printf("\n��ǰû�����н���\n");
}

void zuse()
{
if(!shumu){
printf("��ǰû�����н���\n");
return ;
}
printf("\n�����������̵�IDֵ");
scanf("%d",&pid);
for(int i=0;i<20;i++){
//��λ���ҵ���Ҫ���ѵĽ��̣�������״̬����Ӧ����
if(pid==neicun[i].pid){
if(neicun[i].zhuangtai==1){
neicun[i].zhuangtai=2;
zhuse++;
printf("\n�Ѿ��ɹ���������\n");
}
else if (neicun[i].zhuangtai==0)


printf("\nҪ�����Ľ��̲�����\"n");}

else
printf("\nҪ�����Ľ����ѱ�����\n");
flag=1;
break;}
//�Ҳ�������˵�����̲�����
if(flag==0)
printf("\nҪ�����Ľ��̲�����\n");
}

 


void kill()
{
if(!shumu){
printf("��ǰû�����н���\n");
return ;
}
printf("\n����ɱ�����̵Ĺ�IDֵ");
scanf("%d",&pid);
for(int i=0;i<20;i++){
//��λ���ҵ���Ҫɱ���Ľ��̣�������״̬����Ӧ����
if(pid==neicun[i].pid){
if(neicun[i].zhuangtai==1){
neicun[i].zhuangtai==0;
shumu--;
printf("\n�ѳɹ�ɱ������\n");
}
else if (neicun[i].zhuangtai==0)
printf("\n:Ҫɱ���Ľ��̲�����\n");
else printf("\nҪɱ���Ľ����ѱ�����\n");
flag=1;
break;
}
}
//�Ҳ�������˵�����̲�����
if(!flag)
printf("\nҪɱ���Ľ��̲�����\n");
}



void huanxing()
{
if(!shumu){
printf("\n��ǰû�����н���\n");
return;
}
if(! zhuse)
{
printf("\n��ǰû����������\n");
return;
}

printf("\n����pid��\n");
scanf("%d",pid);
for(int i=0;i<20;i++)
//��λ���ҵ���Ҫɱ���Ľ��̣�������״̬����Ӧ����
if(pid==neicun[i].pid){
flag=false;
if(neicun[i].zhuangtai==2){
neicun[i].zhuangtai==1;
zhuse--;
printf("\n�Ѿ��ɹ����ѽ���\n");
}
else if(neicun[i].zhuangtai==0) 
printf("\nҪ���ѵĽ��̲�����\n");
else printf("\nҪ���ѵĽ����ѱ�����\n");
break;}
//�Ҳ�������˵�����̲�����
if(! flag)
printf("\nҪ���ѵĽ��̲�����\n");
}

 
int  main(){
int n=1;
int num;

//һ��ʼ���н��̶������ڴ���
for(int i=0;1<20;i++){
neicun[i].zhuangtai=0;
while(n){
printf("\n*****************""*****************************************");
printf("\n*******************������ʾϵͳ***********************");
printf("\n***********************************************************");
printf("\n*1. �����µĽ���2���鿴���н���");
printf("\n*3������ĳ������4��ɱ�����н���");
printf("\n*5������ĳ������6���˳�ϵͳ");
printf("\n************************************************************");
printf("\n��ѡ��1��6��\n");
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
flag=0;//�ָ����
}
}
}
 
