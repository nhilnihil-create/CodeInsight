// ====================================
//   author: M_sea
//   website: https://m-sea-blog.com/
// ====================================
#include <bits/stdc++.h>
#define file(x) freopen(#x".in","r",stdin); freopen(#x".out","w",stdout)
#define debug(...) fprintf(stderr,__VA_ARGS__)
using namespace std;
typedef long long ll;

int read() {
	int X=0,w=1; char c=getchar();
	while (c<'0'||c>'9') { if (c=='-') w=-1; c=getchar(); }
	while (c>='0'&&c<='9') X=X*10+c-'0',c=getchar();
	return X*w;
}

const int N=200000+10;

int n,k,a[N]; ll s[N];
ll S[N]; int top=0;

int c[N];
void add(int x,int y) { for (;x<=top;x+=x&-x) c[x]+=y; }
int sum(int x) { int s=0; for (;x;x-=x&-x) s+=c[x]; return s; }

int main() {
	n=read(),k=read();
	for (int i=1;i<=n;++i) a[i]=read();
	for (int i=1;i<=n;++i) s[i]=s[i-1]+a[i];
	for (int i=0;i<=n;++i) S[++top]=s[i]-1ll*k*i;
	sort(S+1,S+top+1); top=unique(S+1,S+top+1)-S-1;
	ll ans=0;
	for (int i=0;i<=n;++i) {
		int p=lower_bound(S+1,S+top+1,s[i]-1ll*k*i)-S;
		if (i) ans+=sum(p);
		add(p,1);
	}
	printf("%lld\n",ans);
	return 0;
}