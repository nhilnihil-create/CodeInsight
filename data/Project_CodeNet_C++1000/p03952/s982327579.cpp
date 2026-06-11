#include<bits/stdc++.h>
using namespace std;
int n,m;
bitset<300005>BIT;
int main()
{
	scanf("%d %d",&n,&m);
	n=n*2-1;
	if(m==n||m==1)printf("No");
	else
	{
		printf("Yes\n");
		if(m==(n/2)+1)
		{
			for(int i=1;i<=n;i++)printf("%d\n",i);
		}
		else if(m<(n/2)+1)
		{
			BIT[1]=true,BIT[m]=true,BIT[m+1]=true,BIT[m+2]=true;
			for(int i=1;i<=(n/2)+2;i++)if(!BIT[i])printf("%d\n",i);
			printf("%d\n1\n%d\n%d\n",m+1,m,m+2);
			for(int i=(n/2)+3;i<=n;i++)if(!BIT[i])printf("%d\n",i);
		}
		else
		{	
			BIT[n]=true,BIT[m]=true,BIT[m-1]=true,BIT[m-2]=true;
			for(int i=1;i<=(n/2)-2;i++)if(!BIT[i])printf("%d\n",i);
			printf("%d\n%d\n%d\n%d\n",m-1,n,m,m-2);
			for(int i=(n/2)-1;i<=n;i++)if(!BIT[i])printf("%d\n",i);
			
		}
	}
}
