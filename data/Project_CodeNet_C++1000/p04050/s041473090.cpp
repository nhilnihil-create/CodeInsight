#include <bits/stdc++.h>
using namespace std;

const int RLEN=1<<18|1;
inline char nc() {
	static char ibuf[RLEN],*ib,*ob;
	(ib==ob) && (ob=(ib=ibuf)+fread(ibuf,1,RLEN,stdin));
	return (ib==ob) ? -1 : *ib++;
}
inline int rd() {
	char ch=nc(); int i=0,f=1;
	while(!isdigit(ch)) {if(ch=='-')f=-1; ch=nc();}
	while(isdigit(ch)) {i=(i<<1)+(i<<3)+ch-'0'; ch=nc();}
	return i*f;
}
const int N=1e5+50;
int n,m,a[N],b[N],tot,c1,c[N];
int main() {
	n=rd(), m=rd();
	for(int i=1;i<=m;i++) a[i]=rd(), c1+=a[i]&1;
	if(c1>2) {puts("Impossible"); return 0;}
	for(int i=1;i<=m;i++) if(a[i]&1) b[++tot]=a[i];
	for(int i=1;i<=m;i++) if(!(a[i]&1)) b[++tot]=a[i];
	if(tot>=2) swap(b[2],b[tot]);
	for(int i=1;i<=m;i++) printf("%d ",b[i]);
	putchar('\n');
	c[1]=b[1]-1;
	for(int i=2;i<=m;i++) c[i]=b[i]+(i==m);
	int tot=0;
	for(int i=1;i<=m;i++) if(c[i]) b[++tot]=c[i];
	printf("%d\n",tot+(m==1));
	for(int i=1;i<=tot;i++) printf("%d ",b[i]);
	if(m==1) printf("%d ",1);
}