#include <bits/stdc++.h>
#define ll long long
#define lf double
#define E complex<lf>
#define eps 1e-9
#define inf 0x7fffffff
#define l(x) (x<<1)
#define r(x) (x<<1|1)
#define pa pair<int,int>
#define pb push_back
#define mod
#define FIO "problem"
#define N 100010
using namespace std;
inline int read() {
	int x=0,f=1;char c=getchar();
	while (c<'0'||c>'9') f=(c=='-')?-1:1,c=getchar();
	while (c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
	return x*f;
}
inline void fre() {
	freopen(FIO".in","r",stdin);
	freopen(FIO".out","w",stdout);
}
int n;
int num[N],opt[N];
ll sum;
int sta[N],top=0;
int main() {
	n=read();
	for (int i=1; i<n; i++) {
		num[i]=read(),sum+=num[i];
		char s[5];
		scanf("%s",s);
		if (s[0]=='-') opt[i]=-1;
		else opt[i]=1;
	}
	num[n]=read(),sum+=num[n];
	ll ans=-inf,hhh=0;
	for (int i=1; i<n; i++) if (opt[i]==-1) {
		ll tmp=sum;
		ll sum2=num[i+1];
		for (int j=i+1; j<n; j++) {
			if (opt[j]==1) sum2+=num[j+1];
			else break;
		}
		tmp-=2*(sum2+hhh);
		ans=max(ans,tmp);
		hhh+=num[i+1];
	}
	ans=max(ans,sum-2*hhh);
	cout << ans << endl;
}