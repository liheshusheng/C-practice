# include <stdio.h>
# include <math.h>
int main(void)
{
	float a,b,c,l,s;
	char y;
	printf("�������������ε����߳�,�м��ÿո����\n");
	scanf("%f %f %f",&a,&b,&c);
	printf("�����ε����߳��ֱ���%7.2f\t%7.2f\t%7.2f\n",a,b,c);
	while(1)
	{
		if(a+b>c&&a+c>b&&b+c>a)
		{
			l=(a+b+c)/2;
			s=sqrt(l*(l-a)*(l-b)*(l-c));
			printf("��������������߳�������������Ϊ��%7.2f\n",s);
			printf("��������������������������룬������Y��y������N��n�˳���\n");	
		}
		else 
		{
			printf("\a���棡�������ֵ�����������Σ�������������������������룬������Y��y������N��n�˳���\n");
			
		}
		while(true)
		{
			y=getchar();
			printf("���������%c\n",y);
			if(y=='Y'||y=='y'||y=='N'||y=='n')
			{
				break;
			}
				
			else
			{
				printf("�밴Ҫ�����룡\n");
				continue;
			}
			
			
		}
		if(y=='Y'||y=='y')
				{
					printf("�������������ε����߳�,�м��ÿո����\n");
					scanf("%f %f %f",&a,&b,&c);
					printf("�����ε����߳��ֱ���%7.2f\t%7.2f\t%7.2f\n",a,b,c);
					continue;
				}
			else 
				{
					break;
				}
	}
	
	
	
	return 0;
}
