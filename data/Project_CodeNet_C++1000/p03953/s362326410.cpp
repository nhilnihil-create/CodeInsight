#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int RLEN=1<<18|1;
inline char nc() {
	static char ibuf[RLEN],*ib,*ob;
	(ib==ob) && (ob=(ib=ibuf)+fread(ibuf,1,RLEN,stdin));
	return (ib==ob) ? -1 : *ib++;
}
inline LL rd() {
	char ch=nc(); LL i=0,f=1;
	while(!isdigit(ch)) {if(ch=='-')f=-1; ch=nc();}
	while(isdigit(ch)) {i=(i<<1)+(i<<3)+ch-'0'; ch=nc();}
	return i*f;
}

const int N=1e5+50;
int n, m, b[N], cir[N], vis[N], tot;
LL k, a[N], c[N];
int main() {
	n=rd();
	for(int i=1;i<=n;i++) a[i]=rd();
	for(int i=0;i<n;i++) a[i]=a[i+1]-a[i];
	m=rd(); k=rd();
	for(int i=1;i<n;i++) b[i]=i;
	for(int i=1;i<=m;i++) {int x=rd(); swap(b[x], b[x-1]);}
	for(int i=1;i<n;i++) {
		if(!vis[i]) {
			cir[tot=1]=i; vis[i]=1;
			for(int p=b[i];!vis[p]; p=b[p]) cir[++tot]=p, vis[p]=1;
			int t=k%tot;
			for(int j=1;j<=tot;j++) {
				int now=cir[j], tar=cir[((j+t)>tot) ? (j+t-tot) : (j+t)];
				c[now]=a[tar];
			}
		}
	}
	for(int i=1;i<=n;i++) a[i]=a[i-1]+c[i-1], printf("%lld.0\n",a[i]);
}