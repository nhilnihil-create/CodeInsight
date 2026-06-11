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

const int N=100000+10;

int n,f[N]; char s[N];

int trans(char c,int x,int y) {
	if (y) {
		if (c=='x') return x;
		else return !x;
	} else {
		if (c=='o') return x;
		else return !x;
	}
}

bool check(int a,int b) {
	f[1]=a,f[2]=b;
	for (int i=3;i<=n;++i)
		f[i]=trans(s[i-1],f[i-2],f[i-1]);
	if (trans(s[n],f[n-1],f[n])!=f[1]) return 0;
	if (trans(s[1],f[2],f[1])!=f[n]) return 0;
	return 1;
}

int main() {
	n=read(); scanf("%s",s+1);
	if (check(0,0)) {
		for (int i=1;i<=n;++i) putchar("SW"[f[i]]);
		return 0;
	}
	if (check(0,1)) {
		for (int i=1;i<=n;++i) putchar("SW"[f[i]]);
		return 0;
	}
	if (check(1,0)) {
		for (int i=1;i<=n;++i) putchar("SW"[f[i]]);
		return 0;
	}
	if (check(1,1)) {
		for (int i=1;i<=n;++i) putchar("SW"[f[i]]);
		return 0;
	}
	puts("-1");
	return 0;
}