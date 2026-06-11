#include<bits/stdc++.h>
using namespace std;
inline char nchar() {
	static const int bufl=1<<20;
	static char buf[bufl],*a=NULL,*b=NULL;
	return a==b && (b=(a=buf)+fread(buf,1,bufl,stdin),a==b)?EOF:*a++;
}
inline int read() {
	int x=0,f=1;
	char c=nchar();
	for (;!isdigit(c);c=nchar()) if (c=='-') f=-1;
	for (;isdigit(c);c=nchar()) x=x*10+c-'0';
	return x*f;
}
const int maxn=1e5+1;
int n,a[maxn];
bool f() {
	int odd=0,even=0,id=0;
	for (int i=1;i<=n;++i) {
		odd+=(a[i]&1);
		even+=(~a[i]&1);
		if (a[i]&1) id=i;
	}
	if (even&1) return true;
	if (odd>1) return false;
	if (a[id]==1) return false;
	--a[id];
	int g=a[1];
	for (int i=2;i<=n && g>1;++i) g=__gcd(g,a[i]);
	if (g>1) for (int i=1;i<=n;++i) a[i]/=g;
	return f()^true;
}
int main() {
	n=read(),generate_n(a+1,n,read);
	puts(f()?"First":"Second");
	return 0;
}
