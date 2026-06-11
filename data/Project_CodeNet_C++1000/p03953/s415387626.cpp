#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 100000;
typedef long long ll;
ll x[MAXN + 5], d[MAXN + 5];
int a[MAXN + 5]; bool tag[MAXN + 5];
int b[MAXN + 5], ans[MAXN + 5];
int main() {
	int N, M; ll K;
	scanf("%d", &N);
	for(int i=1;i<=N;i++) {
		scanf("%lld", &x[i]);
		if( i != 1 ) d[i-1] = x[i] - x[i-1];
	}
	scanf("%d%lld", &M, &K);
	for(int i=1;i<N;i++)
		a[i] = i;
	for(int i=1;i<=M;i++) {
		int x;
		scanf("%d", &x);
		swap(a[x-1], a[x]);
	}
	for(int i=1;i<N;i++) {
		if( tag[i] ) continue;
		int p = i, siz = 0;
		do {
			tag[p] = true;
			b[siz++] = p;
			p = a[p];
		}while( p != i );
		int q = 0;
		for(int j=0;j<siz;j++) {
			ans[b[j]] = b[(j+K)%siz];
		}
	}
	ll nw = x[1];
	for(int i=1;i<=N;i++) {
		printf("%lld\n", nw);
		if( i != N ) nw += d[ans[i]];
	}
}