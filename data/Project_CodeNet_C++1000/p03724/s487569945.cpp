#include<bits/stdc++.h>
using namespace std;

int node[100100];

main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		node[a]++;
		node[b]++;
	}
	for(int i=1;i<=n;i++)
	{
		if(node[i]%2!=0)
		{
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
}