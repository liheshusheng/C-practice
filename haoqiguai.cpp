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
	 	printf("第%d次访问的磁道:%d\n",i+1,a[i]);
	 	sum+=abs(s-a[i]);
		printf("sum=%d\n",sum);
		s=a[i];
	}
	printf("平均寻道长度:%f\n",sum*1.0/n);
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
		printf("第%d次访问的磁道:%d\n",n-i,s);
		sum+=abs(s-k);
		printf("sum=%d\n",sum);
		k=s;
	}
	printf("平均寻道长度:%f\n",sum*1.0/n);
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
		    printf("第%d次访问的磁道:%d\n",n-i,s);
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
			printf("第%d次访问的磁道:%d\n",n-i,s);
		    sum+=abs(k-s);
			printf("sum=%d\n",sum);
		    k=s;
		}
	}
	printf("平均寻道长度:%f\n",sum*1.0/n);
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
		    printf("第%d次访问的磁道:%d\n",n-i,s);
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
			printf("第%d次访问的磁道:%d\n",n-i,s);
		    			sum+=abs(k-s);
			printf("sum=%d\n",sum);
		    k=s;
		}
	}
	
	printf("平均寻道长度:%f\n",sum*1.0/n);
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
		    printf("第%d次访问的磁道:%d\n",n-i,s);
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
	printf("第%d次访问的磁道:%d\n",n-i,s);
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
		printf("第%d次访问的磁道:%d\n",n-i,s);
		sum+=s-k;
		printf("sum=%d\n",sum);
		k=s;
	}
	printf("平均寻道长度:%f\n",sum*1.0/n);
}

int main()
{
	int a[20];
	int i,n,k,k1,init;
	printf("请输入需要访问的磁道总数：");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("需要访问的磁道编号%d:",i+1);
		scanf("%d",&a[i]);
	}
	printf("请输入指针所在磁道编号:");
	scanf("%d",&init);
	k=1;
	while(k)
	{
		printf("*************20201219*************\n");
		printf("**    1.先来先服务(FCFS)        **\n");
		printf("**    2.最短寻道时间优先(SSTF)  **\n");
		printf("**    3.扫描算法(SCAN)          **\n");
		printf("**    4.循环扫描算法(C-SCAN)    **\n");
		printf("**    0.退出                    **\n");
		printf("**傅群忠编辑于黄河科技学院理工楼**\n");
		printf("**********************************\n");
		printf("请在下面输入您的选择:");
		scanf("%d",&k);
		switch(k)
		{
			case 1:FCFS(a,n,init);break;
			case 2:SSTF(a,n,init);break;
			case 3:k1=1;
			  while(k1)
			  {
			    printf("************20201219 *************\n");
			    printf("**    1.移动臂由里向外          **\n");
			    printf("**    2.移动臂由外向里          **\n");
			    printf("**    0.返回上一层              **\n");
			    printf("**********************************\n");
			    printf("请在下面输入您的选择:");
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

