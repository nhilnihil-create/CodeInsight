#include <cstdio>
#include <algorithm>
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while (c<'0'||c>'9') {if (c=='-') f=-1;c=getchar();}
	while (c>='0'&&c<='9') {x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
const int maxn(1e5+5);
ll n,l,q;
ll s[maxn],f[maxn][35];

void swap(ll &a,ll &b){int t=a;a=b;b=t;}
void init(){
	n=read();
	for (int i(1);i<=n;++i) s[i]=read();
	l=read(),q=read();
	for (int i(1);i<=n;++i) f[i][0]=upper_bound(s+1,s+n+1,s[i]+l)-s-1;
	for (int i(1);i<=30;++i)
		for (int j(1);j<=n;++j)
			f[j][i]=f[f[j][i-1]][i-1];
}

signed main(){
	init();
	while (q--){
		int a=read(),b=read(),tot=0;
		if (a>b) swap(a,b);
		int v=a;
		for (int i=30;~i;--i){
			if (f[v][i]<b){
				tot+=1<<i;
				v=f[v][i];
			}
		}
		printf("%d\n",tot+1);
	}
	return 0; 
}
