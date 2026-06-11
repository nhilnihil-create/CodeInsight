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

int n,m,Q;
char a[N],b[N];
int sa[N],sb[N];

int main() {
	scanf("%s",a+1),n=strlen(a+1);
	scanf("%s",b+1),m=strlen(b+1);
	for (int i=1;i<=n;++i) sa[i]=sa[i-1]+1+(a[i]=='B');
	for (int i=1;i<=m;++i) sb[i]=sb[i-1]+1+(b[i]=='B');
	Q=read();
	while (Q--) {
		int la=read(),ra=read(),lb=read(),rb=read();
		puts((sa[ra]-sa[la-1])%3==(sb[rb]-sb[lb-1])%3?"YES":"NO");
	}
	return 0;
}