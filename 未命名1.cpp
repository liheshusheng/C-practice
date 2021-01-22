# include <stdio.h>
# include <math.h>
int main(void)
{
	float a,b,c,l,s;
	char y;
	printf("请您输入三角形的三边长,中间用空格隔开\n");
	scanf("%f %f %f",&a,&b,&c);
	printf("三角形的三边长分别是%7.2f\t%7.2f\t%7.2f\n",a,b,c);
	while(1)
	{
		if(a+b>c&&a+c>b&&b+c>a)
		{
			l=(a+b+c)/2;
			s=sqrt(l*(l-a)*(l-b)*(l-c));
			printf("根据你输入的三边长求出三角形面积为：%7.2f\n",s);
			printf("您还想继续输入吗？如果想继续输入，请输入Y或y，否则按N或n退出！\n");	
		}
		else 
		{
			printf("\a警告！您输入的值构不成三角形，还想继续输入吗？如果想继续输入，请输入Y或y，否则按N或n退出！\n");
			
		}
		while(true)
		{
			y=getchar();
			printf("您输入的是%c\n",y);
			if(y=='Y'||y=='y'||y=='N'||y=='n')
			{
				break;
			}
				
			else
			{
				printf("请按要求输入！\n");
				continue;
			}
			
			
		}
		if(y=='Y'||y=='y')
				{
					printf("请您输入三角形的三边长,中间用空格隔开\n");
					scanf("%f %f %f",&a,&b,&c);
					printf("三角形的三边长分别是%7.2f\t%7.2f\t%7.2f\n",a,b,c);
					continue;
				}
			else 
				{
					break;
				}
	}
	
	
	
	return 0;
}
