#include <stdio.h>
#include<math.h>
void FCFS(int b[],int n,int init)  
{
	int i,s,sum;
	int a[20];
	for(i=0;i<n;i++)
	  a[i]=b[i];
	s=init;
	sum=0;
	for(i=0;i<n;i++)
	{
	 	printf("��%d�η��ʵĴŵ�:%d\n",i+1,a[i]);
	 	sum+=abs(s-a[i]);
		printf("sum=%d\n",sum);
		s=a[i];
	}
	printf("ƽ��Ѱ������:%f\n",sum*1.0/n);
}
void SSTF(int b[],int n,int k) 
{
	int i,j,s,sum=0,p;
	int a[20];
	for(i=0;i<n;i++)
	  a[i]=b[i];
	for(i=n-1;i>=0;i--)
	{
		s=a[0];
		p=0;
		for(j=0;j<=i;j++)
		  if(abs(a[j]-k)<abs(s-k))
		  {
		     s=a[j];
		     p=j;
		  }
		a[p]=a[i];
		printf("��%d�η��ʵĴŵ�:%d\n",n-i,s);
		sum+=abs(s-k);
		printf("sum=%d\n",sum);
		k=s;
	}
	printf("ƽ��Ѱ������:%f\n",sum*1.0/n);
}

void SCAN1(int b[],int n,int k)  
{
	int i,j,s,sum=0,p,biaoji;
	int a[20];
	for(i=0;i<n;i++)
	  a[i]=b[i];
	for(i=n-1;i>=0;i--)
	{
		biaoji=0;
		for(j=0;j<=i;j++)
		  if(a[j]-k<0)
		  {
		  	 biaoji=1;
		  	 p=j;
		  	 break;
		  }
		if(biaoji==1)
		{
		    s=a[p];
		    for(j=0;j<=i;j++)
		      if(a[j]<k&&k-a[j]<k-s)
		      {
		         s=a[j];
		         p=j;
		      }
		    a[p]=a[i];
		    printf("��%d�η��ʵĴŵ�:%d\n",n-i,s);
		    sum+=k-s;
	printf("sum=%d\n",sum);
		    k=s;
		}
		else
		{
			s=a[0];
			for(j=0;j<=i;j++)
			  if(a[j]-k<=s-k)
			  {
			  	 s=a[j];
			  	 p=j;
			  }
			a[p]=a[i];
			printf("��%d�η��ʵĴŵ�:%d\n",n-i,s);
		    sum+=abs(k-s);
			printf("sum=%d\n",sum);
		    k=s;
		}
	}
	printf("ƽ��Ѱ������:%f\n",sum*1.0/n);
}

void SCAN2(int b[],int n,int k)  
{
	int i,j,s,sum=0,p,biaoji;
	int a[20];
	for(i=0;i<n;i++)
	  a[i]=b[i];
	for(i=n-1;i>=0;i--)
	{
		biaoji=0;
		for(j=0;j<=i;j++)
		  if(a[j]-k>0){
		  	 biaoji=1;
		  	 p=j;
		  	 break;
		  }
		if(biaoji==1){
		    s=a[p];
		    for(j=0;j<=i;j++)
		      if(a[j]>k&&a[j]-k<s-k)
		      {
		         s=a[j];
		         p=j;
		      }
		    a[p]=a[i];
		    printf("��%d�η��ʵĴŵ�:%d\n",n-i,s);
		    sum+=s-k;
			printf("sum=%d\n",sum);
		    k=s;
		}
		else
		{
			s=a[0];
			for(j=0;j<=i;j++)
			  if(k-a[j]<=k-s){
			  	 s=a[j];
			  	 p=j;
			  }
			a[p]=a[i];
			printf("��%d�η��ʵĴŵ�:%d\n",n-i,s);
		    			sum+=abs(k-s);
			printf("sum=%d\n",sum);
		    k=s;
		}
	}
	
	printf("ƽ��Ѱ������:%f\n",sum*1.0/n);
}

void C_SCAN(int b[],int n,int k)  
{
	int i,j,s,sum=0,p,biaoji;
	int a[20];
	for(i=0;i<n;i++)
	  a[i]=b[i];
	for(i=n-1;i>=0;i--)
	{
		biaoji=0;
		for(j=0;j<=i;j++)
		  if(a[j]-k>0)
		  {
		  	 biaoji=1;
		  	 p=j;
		  	 break;
		  }
		if(biaoji==1)
		{
		    s=a[p];
		    for(j=0;j<=i;j++)
		      if(a[j]>k&&a[j]-k<s-k){
		         s=a[j];
		         p=j;
		      }
		    a[p]=a[i];
		    printf("��%d�η��ʵĴŵ�:%d\n",n-i,s);
		    sum+=s-k;
			printf("sum=%d\n",sum);
		    k=s;
		}
	    if(biaoji==0) break;
	}
	s=a[0];
	for(j=0;j<=i;j++)
	   if(a[j]<=s)
	   {
		  s=a[j];
	      p=j;
	   }
	a[p]=a[i];
	printf("��%d�η��ʵĴŵ�:%d\n",n-i,s);
	sum+=k-s;
	printf("sum=%d\n",sum);
	k=s;
	i--;
	for(;i>=0;i--)
	{
		//printf("a[0]=%d\n",a[0]);
		s=a[0];
		for(j=0;j<=i;j++)
		{
			//printf("j=%d;k=%d;a[j]=%d;s=%d;k=%d\n",j,k,a[j],s,k);
		  if(a[j]-k<=s-k)
		  {
			s=a[j];
			p=j;
			}
		}
		a[p]=a[i];
		printf("��%d�η��ʵĴŵ�:%d\n",n-i,s);
		sum+=s-k;
		printf("sum=%d\n",sum);
		k=s;
	}
	printf("ƽ��Ѱ������:%f\n",sum*1.0/n);
}

int main()
{
	int a[20];
	int i,n,k,k1,init;
	printf("��������Ҫ���ʵĴŵ�������");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("��Ҫ���ʵĴŵ����%d:",i+1);
		scanf("%d",&a[i]);
	}
	printf("������ָ�����ڴŵ����:");
	scanf("%d",&init);
	k=1;
	while(k)
	{
		printf("*************20201219*************\n");
		printf("**    1.�����ȷ���(FCFS)        **\n");
		printf("**    2.���Ѱ��ʱ������(SSTF)  **\n");
		printf("**    3.ɨ���㷨(SCAN)          **\n");
		printf("**    4.ѭ��ɨ���㷨(C-SCAN)    **\n");
		printf("**    0.�˳�                    **\n");
		printf("**��Ⱥ�ұ༭�ڻƺӿƼ�ѧԺ��¥**\n");
		printf("**********************************\n");
		printf("����������������ѡ��:");
		scanf("%d",&k);
		switch(k)
		{
			case 1:FCFS(a,n,init);break;
			case 2:SSTF(a,n,init);break;
			case 3:k1=1;
			  while(k1)
			  {
			    printf("************20201219 *************\n");
			    printf("**    1.�ƶ�����������          **\n");
			    printf("**    2.�ƶ�����������          **\n");
			    printf("**    0.������һ��              **\n");
			    printf("**********************************\n");
			    printf("����������������ѡ��:");
			    scanf("%d",&k1);
			    switch(k1)
				{
			  	   case 1:SCAN1(a,n,init);break;
			  	   case 2:SCAN2(a,n,init);break;
			    }
			  }
			  break;
			case 4:C_SCAN(a,n,init);break;
		}
	}
	return 0;
}

