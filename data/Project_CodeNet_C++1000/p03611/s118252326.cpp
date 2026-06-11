#include<bits/stdc++.h>
 const int N=1e5+5;
 int a[N];
 int main()
 {
 	int n,ai;
 	scanf("%d",&n);
 	while(n--)
 	{
 		scanf("%d",&ai);
 		a[ai]++;
 		a[ai-1]++;
 		a[ai+1]++;
	}
	int max=0;
	for(int i=0;i<N-1;i++)
	{
		if(max<a[i])
		{
			max=a[i];
		}
	}
	printf("%d",max);
 } 