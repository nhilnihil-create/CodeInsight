#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)

using namespace std;
typedef long long LL;
LL n;
int ans[1000],cnt[1000],tot;

int main()
{
	scanf("%lld",&n),++n;
	while(n)
	{
		cnt[++*cnt]=n&1;
		n>>=1;
	}
	int l=100,r=99;
	ans[++r]=++tot;
	repd(i,*cnt-1,1)
	{
		if(cnt[i]) ans[--l]=++tot;
		if(i>1) ans[++r]=++tot;
	}
	printf("%d\n",tot*2);
	rep(i,l,r) printf("%d ",ans[i]);
	rep(i,1,tot) printf("%d ",i);
	puts("");
	return 0;
}