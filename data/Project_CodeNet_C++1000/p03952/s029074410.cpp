#include<bits/stdc++.h>
using namespace std;
int pp[300005];
main()
{
	int t,p;
	scanf("%d%d",&t,&p);
	if(t==2)
	{
		if(p==2)
		{
			printf("Yes\n");
			printf("1\n2\n3");
		}
		else
		printf("No");
	}
	else
	{
		if(p<=1 || p>=2*t-1)
		printf("No");
		else
		{
			int cou=0;
			printf("Yes\n");
			if(p==2)
			{
				pp[2*t-1]=1;
				pp[1]=1;
				pp[2]=1;
				pp[4]=1;
				for(int i = 1;i <= 2*t-1 && cou<=t-4;i++)
				{
					if(pp[i]==0)
					{
						pp[i]=1;
						printf("%d\n",i);
						cou++;
					}
				}
				printf("%d\n%d\n%d\n%d\n",2*t-1,1,2,4);
				
				for(int i = 1;i <= 2*t-1;i++)
				{
					if(pp[i]==0)
					printf("%d\n",i);
				}
			}
			else if(p==2*t-2)
			{
				
				pp[2*t-1]=1;
				pp[2]=1;
				pp[2*t-2]=1;
				pp[1]=1;
				for(int i = 1;i <= 2*t-1 && cou<=t-4;i++)
				{
					if(pp[i]==0)
					{
						pp[i]=1;
						printf("%d\n",i);
						cou++;
					}
				}
				printf("%d\n%d\n%d\n%d\n",2,2*t-1,2*t-2,1);
				for(int i = 1;i <= 2*t-1;i++)
				{
					if(pp[i]==0)
					{
						pp[i]=1;
						printf("%d\n",i);
						cou++;
					}
				}
			}
			else
			{
				
				pp[p-1]=1;
				pp[p]=1;
				pp[p+1]=1;
				pp[p-2]=1;
				for(int i = 1;i <= 2*t-1 && cou<=t-4;i++)
				{
					if(pp[i]==0)
					{
						pp[i]=1;
						printf("%d\n",i);
						cou++;
					}
				}
				printf("%d\n%d\n%d\n%d\n",p-1,p,p+1,p-2);
				for(int i = 1;i <= 2*t-1;i++)
				{
					if(pp[i]==0)
					printf("%d\n",i);
				}
			}
		}
	}
	
}
/*
3-3;
   
   1
  111
 
7124356


   1
  111
 
4765

 331
23415
*/