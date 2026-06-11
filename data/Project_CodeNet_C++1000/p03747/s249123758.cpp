#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
 
const int RLEN=1<<18|1;
inline char nc() {
	static char ibuf[RLEN],*ib,*ob;
	(ib==ob) && (ob=(ib=ibuf)+fread(ibuf,1,RLEN,stdin));
	return (ib==ob) ? -1 : *ib++;
}
inline int rd() {
	char ch=nc(); int i=0,f=1;
	while(!isdigit(ch)) {if(ch=='-') f=-1; ch=nc();}
	while(isdigit(ch)) {i=(i<<1)+(i<<3)+ch-'0'; ch=nc();}
	return i*f;
}
 
const int N=1e5+50;
int n,cnt,L,T,a[N],b[N],w[N];
int main() {
	n=rd(), L=rd(), T=rd();
	for(int i=1;i<=n;i++) {
		a[i]=rd(), w[i]=(rd()==1 ? 1 : -1);
		b[i]=((a[i]+(LL)T*w[i])%L+L)%L;
		int dis=(w[i]>0 ? L-a[i] : a[i])+1;
		if(T>=dis) {
			cnt+=w[i]; int res=T-dis;
			cnt+=(res/L)*w[i];
			cnt=(cnt%n+n)%n;
		}
	} sort(b+1,b+n+1);
	for(int i=1;i<=n;i++) 
		printf("%d\n",b[(i+cnt-1)%n+1]);
}