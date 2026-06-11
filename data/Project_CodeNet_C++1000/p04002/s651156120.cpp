#include<bits/stdc++.h>
using namespace std;
#define maxn 100005
#define base 1000000005
long long node[maxn*10],ans[10];
int h,w,n,x,y,nodecnt;
int main()
{
	scanf("%d%d%d",&h,&w,&n);
	while(n--)
	{
		scanf("%d%d",&x,&y);
		for(int i=0;i<3;++i)
			for(int j=0;j<3;++j)
				if(1<=x-i&&x-i<=h-2&&1<=y-j&&y-j<=w-2)
					node[++nodecnt]=1ll*base*(x-i)+(y-j);
	}
	ans[0]=1ll*(h-2)*(w-2);
	sort(node+1,node+nodecnt+1);
	for(int i=1,cnt=1;i<=nodecnt;++i)
	{
		if(node[i]==node[i+1]) ++cnt;
		else ++ans[cnt],cnt=1,--ans[0];
	}
	for(int i=0;i<10;++i) printf("%lld\n",ans[i]);
	return 0;
}