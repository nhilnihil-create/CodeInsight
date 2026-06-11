#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
#include <functional>
#include <unordered_set>
#include <bitset>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define szz(x) (int)x.size()
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) x.begin(),x.end()
typedef tuple<int, int, int> t3;

const int MOD = 1e9 + 7;
int pw(int x, int y = MOD - 2) {
	int res = 1;
	while(y) {
		if(y & 1) res = (ll) res * x % MOD;
		x = (ll) x * x % MOD;
		y >>= 1;
	}
	return res;
}

ll F[200020];

ll C(int a, int b) {
	return F[a+b] * pw(F[a]) % MOD * pw(F[b]) % MOD;
}

int main() {
	F[0] = 1;
	for(int i=1;i<200020;i++) F[i] = i * F[i-1] % MOD;
	int h, w, a, b; scanf("%d%d%d%d", &h, &w, &a, &b);
	int x = min(h-a, w-b);
	ll ans = 0;
	for(int i=0;i<x;i++) {
		ans = (ans + C(h - a - 1 - i, b + i) * C(w - b - 1 - i, a + i)) % MOD;
	}
	printf("%lld\n", ans);
	return 0;
}
