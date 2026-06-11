#include <cstdio>
#include <algorithm>
#define rep(i,j,k) for (i=j;i<=k;i++)
using namespace std;
const int N=2e5+5;
int n,i,j,l,r,fl,mid,pos,a[N],b[N],c[N];
bool judge()
{
	int i,l,r,fix;
	rep(i,1,n) b[i]=(a[i]>=mid);
	b[0]=b[1]; b[n+1]=b[n];
	rep(i,1,n) c[i]=!(b[i]!=b[i-1] && b[i]!=b[i+1]);
	if (c[pos]) return b[pos];
	for (l=pos;!c[l];l--);
	for (r=pos;!c[r];r++);
	fix=min(pos-l,r-pos);
	if (fix>=fl-1) return b[pos]^!(fl&1);
	if (pos-l<r-pos) return b[l];
	return b[r];
}
int main()
{
//	freopen("pyramid.in","r",stdin);
//	freopen("pyramid.out","w",stdout);
	scanf("%d",&fl); n=fl*2-1; pos=fl;
	rep(i,1,n) scanf("%d",&a[i]);
	l=1; r=n;
	while (l<r)
	{
		if (r-l>1) mid=(l+r)>>1;
		else mid=r;
		if (judge()) l=mid;
		else r=mid-1;
	}
	printf("%d\n",l);
	return 0;
}