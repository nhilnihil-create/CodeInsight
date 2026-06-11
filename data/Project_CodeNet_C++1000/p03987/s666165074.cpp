#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,ans;
int a[N],LOG[N],f[N][21];

inline int jay(int x,int y,int now)
{
	int s=(int)LOG[y-x+1];
	if (min(f[x][s],f[y-(1<<s)+1][s])==now) return true;
	return false;
}

signed main(){
	scanf("%lld",&n); 
	for (register int i=1; i<=n; ++i) scanf("%lld",&a[i]);
	LOG[0]=-1;
	for (register int i=1; i<=n; ++i) LOG[i]=LOG[i>>1]+1;
	for (register int i=1; i<=n; ++i) f[i][0]=a[i];
	for (register int j=1; j<=20; ++j)
	for (register int i=1; i+(1<<j)-1<=n; ++i) f[i][j]=min(f[i][j-1],f[i+(1<<(j-1))][j-1]); 
	
	for (register int i=1; i<=n; ++i)
	{
		int l,r,pos1,pos2;
		l=1; r=i;
		while (l<=r)
		{
			int mid=l+r>>1;
			if (jay(mid,i,a[i])) pos1=mid,r=mid-1;
			else l=mid+1;	
		}
		l=i; r=n;
		while (l<=r)
		{
			int mid=l+r>>1;
			if (jay(i,mid,a[i])) pos2=mid,l=mid+1;
			else r=mid-1;
		}
		ans+=a[i]*(i-pos1+1)*(pos2-i+1);
	}
	printf("%lld\n",ans);
return 0;
}