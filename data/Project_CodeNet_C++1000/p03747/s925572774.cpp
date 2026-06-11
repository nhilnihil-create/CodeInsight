#include <cstdio>
#include <algorithm>
#define rep(i,j,k) for (i=j;i<=k;i++)
using namespace std;
const int N=1e5+5;
int n,L,T,i,rk,x[N],d[N];
int main()
{
//	freopen("ants.in","r",stdin);
//	freopen("ants.out","w",stdout);
	scanf("%d%d%d",&n,&L,&T);
	rep(i,0,n-1) scanf("%d%d",&x[i],&d[i]);
	rep(i,0,n-1)
	{
		if (d[i]==1)
		{
			rk+=(x[i]+T)/L;
			x[i]=(x[i]+T)%L;
		}
		else {
			rk+=(x[i]-T)/L;
			x[i]=(x[i]-T)%L;
			if (x[i]<0) {
				x[i]+=L;
				rk--;
			}
		}
	}
	rk=(rk%n+n)%n;
	sort(x,x+n);
	rep(i,rk,n-1) printf("%d\n",x[i]);
	rep(i,0,rk-1) printf("%d\n",x[i]);
	return 0;
}