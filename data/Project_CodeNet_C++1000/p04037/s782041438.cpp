#include <bits/stdc++.h>
#include <ext/rope>
using namespace std;
using namespace __gnu_cxx;
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
inline void W(int x) {
	static int buf[50];
	if(!x) {putchar('0'); return;}
	if(x<0) {putchar('-'); x=-x;}
	while(x) {buf[++buf[0]]=x%10; x/=10;}
	while(buf[0]) {putchar(buf[buf[0]--]+'0');}
}

const int N=1e5+50;
int n,a[N];
inline int gs(int x,int y) {
	if(y>=a[x+1]) return 0;
	return gs(x+1,y)+1;
} 
inline bool mustwin(int x,int y) {
	if(y>=a[x+1]) return true;
	if((a[x+1]-y+gs(x,y)-2)&1) return true;
	return false;
}
int main() {
	n=rd();
	for(int i=1;i<=n;i++) a[i]=rd();
	sort(a+1,a+n+1); reverse(a+1,a+n+1);
	int l=1, r=n-1, ans=0;
	while(l<=r) {
		int mid=(l+r)>>1;
		if(a[mid+1]>mid) ans=mid, l=mid+1;
		else r=mid-1;
	}
	if(mustwin(ans,ans+1) && mustwin(ans+1,ans)) puts("Second");
	else puts("First");
}