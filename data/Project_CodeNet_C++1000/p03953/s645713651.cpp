#include<bits/stdc++.h>
#define R register int
#define ll long long
using namespace std;
namespace Luitaryi {
inline ll g() { register ll x=0,f=1;
	register char ch; while(!isdigit(ch=getchar())) f=ch=='-'?-1:f;
	do x=x*10+(ch^48); while(isdigit(ch=getchar())); return x*f;
} const int N=100010;
ll n,m,k,a[N],p[N],stk[N],ans[N]; bool vis[N];
inline void main() {
	n=g(); for(R i=1;i<=n;++i) a[i]=g(),p[i]=i;
	for(R i=n;~i;--i) a[i]-=a[i-1];
	m=g(),k=g(); for(R i=1,x;i<=m;++i) x=g(),swap(p[x],p[x+1]);
	for(R i=1;i<=n;++i) {
		if(!vis[i]) { R top=0;
			for(R j=i;!vis[j];j=p[j]) stk[++top]=j,vis[j]=true;
			for(R j=1;j<=top;++j) ans[stk[j]]=a[stk[(k+j-1)%top+1]];
		}
	} for(R i=1;i<=n;++i) ans[i]+=ans[i-1],printf("%lld.0\n",ans[i]);
}
} signed main() {Luitaryi::main(); return 0;}