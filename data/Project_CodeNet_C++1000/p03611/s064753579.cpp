#include<bits/stdc++.h>
main()
{
	int n,b[100005];
	memset(b,0,sizeof(b));
	scanf("%d",&n);
	while(n--)
	{
		int a;
		scanf("%d",&a);
		if(a==1)
		{
			b[1]++;
			b[2]++;
		}
		else if(a==100000)
		{
			b[100000]++;
			b[99999]++;
		}
		else
		{
			b[a-1]++;
			b[a]++;
			b[a+1]++; 
		}
	}
	int max=0;
	for(int i=1;i<=100000;i++)
	{
		if(b[i]>max)max=b[i];
	}
	printf("%d",max);
}