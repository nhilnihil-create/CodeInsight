#include <cstdio>
#define rep(i,j,k) for (i=j;i<=k;i++)
using namespace std;
const int N=1e5+5;
int n,i,ans,a[N],cnt[2];
int gcd(int a,int b) {
	int c=a%b;
	while (c) { a=b; b=c; c=a%b; }
	return b;
}
int solve()
{
	int i,ret,g,pos=0;
	cnt[0]=cnt[1]=0;
	rep(i,1,n) {
		cnt[a[i]%2]++;
		if (a[i]%2 && a[i]>1) pos=i;
	}
	if (cnt[0]%2==0 && cnt[1]==1 && pos) {
		a[pos]--; g=a[1];
		rep(i,2,n) g=gcd(g,a[i]);
		rep(i,1,n) a[i]/=g;
		ret=solve()^1;
	}
	else ret=cnt[0]%2;
	return ret;
}
int main()
{
//	freopen("game.in","r",stdin);
//	freopen("game.out","w",stdout);
	scanf("%d",&n);
	rep(i,1,n) scanf("%d",&a[i]);
	ans=solve();
	if (ans) printf("First\n");
	else printf("Second\n");
	return 0;
}