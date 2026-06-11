#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
#define rep(i,st,ed) for (int i=st;i<=ed;++i)

typedef long long LL;
const int N=20005;

int tot;

std:: deque <int> L,R;

void solve(LL n) {
	if (n==1) return ;
	solve(n/2);
	L.push_front(++tot);
	R.push_front(tot);
	if (n&1) {
		L.push_front(++tot);
		R.push_back(tot);
	}
}

int main(void) {
	LL n; scanf("%lld",&n);
	solve(n+1);
	printf("%d\n", L.size()+R.size());
	for (int i=0;i<L.size();++i) printf("%d ", L[i]);
	for (int i=0;i<R.size();++i) printf("%d ", R[i]);
	puts("");
	return 0;
}