#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 100000;
int N, M; ll K;
int x[MAXN + 5];
int a[MAXN + 5], b[MAXN + 5], res[MAXN + 5];
void Pow(ll p) {
	for(int i=1;i<N;i++)
		res[i] = i;
	while( p ) {
		if( p & 1 ) {
			for(int i=1;i<N;i++)
				res[i] = a[res[i]];
		}
		p >>= 1;
		for(int i=1;i<N;i++)
			b[i] = a[a[i]];
		for(int i=1;i<N;i++)
			a[i] = b[i];
	}
}
int main() {
	scanf("%d", &N);
	for(int i=0;i<N;i++)
		scanf("%d", &x[i]);
	for(int i=N-1;i>0;i--)
		x[i] = x[i] - x[i-1];
	scanf("%d%lld", &M, &K);
	for(int i=1;i<N;i++)
		a[i] = i;
	for(int i=1;i<=M;i++) {
		int k;
		scanf("%d", &k);
		swap(a[k-1], a[k]);
	}
	Pow(K);
	ll nw = x[0];
	printf("%lld\n", nw);
	for(int i=1;i<N;i++) {
		nw = nw + x[res[i]];
		printf("%lld\n", nw);
	}
}