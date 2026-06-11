#include<cstdio>
#include<algorithm>
using namespace std;
int n,x,vis[200005],a[200005],hd=1,i;
void pt(int x,int y)
{
	vis[x]=1;
	a[y]=x;
}
int main()
{
	scanf("%d%d",&n,&x);
	if(x==1||x==2*n-1)
	{
		printf("No\n");
		return 0;
	}
	if(n==2)
	{
		printf("Yes\n1\n2\n3\n");
		return 0;
	}
	printf("Yes\n");
	vis[x]=1;vis[1]=vis[2*n-1]=1;
	a[n]=x;a[n+1]=2*n-1;a[n-1]=1;
	if(x==2*n-2)pt(x-1,n+2);
	else pt(x+1,n-2);
	hd=1;
	for(i=1;i<=2*n-1;i++)
	{
		if(a[i])printf("%d\n",a[i]);
		else
		{
			while(vis[hd])hd++;
			printf("%d\n",hd);
			vis[hd]=1;
		}
	}
	return 0;
}