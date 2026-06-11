// ====================================
//   author: M_sea
//   website: https://m-sea-blog.com/
// ====================================
#include <bits/stdc++.h>
#define file(x) freopen(#x".in","r",stdin); freopen(#x".out","w",stdout)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define mp make_pair
using namespace std;
typedef long long ll;

int read() {
	int X=0,w=1; char c=getchar();
	while (c<'0'||c>'9') { if (c=='-') w=-1; c=getchar(); }
	while (c>='0'&&c<='9') X=X*10+c-'0',c=getchar();
	return X*w;
}

const int N=200000+10;

int n,k,l;
struct DSU {
	int f[N];
	int find(int x) { return x==f[x]?x:f[x]=find(f[x]); }
	void merge(int x,int y) {
		x=find(x),y=find(y);
		if (x!=y) f[x]=y;
	}
} A,B;
map<pair<int,int>,int> M;

int main() {
	n=read(),k=read(),l=read();
	for (int i=1;i<=n;++i) A.f[i]=B.f[i]=i;
	for (int i=1;i<=k;++i) A.merge(read(),read());
	for (int i=1;i<=l;++i) B.merge(read(),read());
	for (int i=1;i<=n;++i) ++M[mp(A.find(i),B.find(i))];
	for (int i=1;i<=n;++i) printf("%d ",M[mp(A.find(i),B.find(i))]);
	return 0;
}