#include<stdio.h>

int main()
{
	int N,i;
	int s[100005]={0};
	while(scanf("%d",&N)!=EOF)
	{
		int q=0;
		int t=0;
		for(i=1;i<=N;i++)
		{
			scanf("%d",&s[i]);
		}
		
		for(i=1;i<=N;i++)
		{
			if(s[i]==i)
			{
				int x;
				x=s[i];
				s[i]=s[i+1];
				s[i+1]=x;
				t++;
			}
		}
		if(s[N]==N) t++;
		printf("%d\n",t);
	}
	
}