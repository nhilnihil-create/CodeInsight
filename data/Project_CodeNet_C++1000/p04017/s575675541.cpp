#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int x[N],n,l;
int nxt[N][20];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&x[i]);
	scanf("%d",&l);
	int now=n;
	nxt[n][0]=n;
	for(int i=n-1;i;i--)
	{
		while(x[now]-x[i]>l)now--;
		nxt[i][0]=now;
	}
	for(int i=1;i<=19;i++)
		for(int j=1;j<=n;j++)
			nxt[j][i]=nxt[nxt[j][i-1]][i-1];
	int q,x,y,ans;
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d%d",&x,&y);
		if(x>y)swap(x,y); ans=0; now=x;
		for(int i=19;i>=0;i--)
			if(nxt[now][i]<y)
				ans+=(1<<i),now=nxt[now][i];
		printf("%d\n",ans+1);
	}
	return 0;
}
