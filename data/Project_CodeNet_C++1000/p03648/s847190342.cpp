#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<vector>
#include<queue>
#include<string.h>
using namespace std;
int main()
{
	long long k,i,num,h,j;
	while(scanf("%lld",&k)!=EOF)
	{
		if(k<=49)
		{
			for(i=2;i<=50;i++)
			{
				if(i>k)
				break;
			}
			printf("%lld\n",i);
			printf("%lld ",k*i+i-1);
			for(j=2;j<=i;j++)
			{
				printf("0");
				if(j!=i)
				printf(" ");
				else
				printf("\n");
			}
		}
		else
		{
			printf("50\n");
			if(k%50==0)
			{
				num=k/50+49;
				for(i=1;i<=50;i++)
				{
					printf("%lld",num);
					if(i!=50)
					printf(" ");
					else
					printf("\n");
				}
			}
			else
			{
				h=k%50;
				num=k/50+49;
				for(i=1;i<=h;i++)
				printf("%lld ",num+51-h);
				for(i=h+1;i<=50;i++)
				{
					printf("%lld",num-h);
					if(i!=50)
					printf(" ");
					else
					printf("\n");
				}
			}
		}
	}
	return 0;
}