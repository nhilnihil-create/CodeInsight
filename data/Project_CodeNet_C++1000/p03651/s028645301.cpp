#include <iostream>
#include <algorithm>
#define flush fflush(stdout)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<P, P> PP;
typedef pair<ll, ll> Pl;
const int mod = (int)1e9 + 7, INF = (int)1e9;
const int di[4] = { 1,0,-1,0 }, dj[4] = { 0,1,0,-1 };


int gcd(int a, int b) {
	if (a > b) swap(a, b);
	if (a == 0) return b;
	return gcd(b % a, a);
}

int main(void) {
	int n, k, i, a[100003], agcd, amax;

	scanf("%d%d", &n, &k);
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	agcd = 0;
	amax = 0;
	for (i = 0; i < n; i++) {
		agcd = gcd(agcd, a[i]);
		amax = max(amax, a[i]);
	}

	if (k% agcd == 0 && k <= amax) {
		printf("POSSIBLE\n");
	}
	else {
		printf("IMPOSSIBLE\n");
	}

	return 0;
}