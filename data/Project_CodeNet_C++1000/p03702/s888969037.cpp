#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <bitset>
#include <stack>
#include <cmath>
#define ll long long
#define LINF 0x3f3f3f3f3f3f3f3f
#define INF 0x3f3f3f3f
using namespace std;
const int MAX = 1e5 + 10;
const ll MOD = 1e9 + 7;
int N, M, K, Q;
ll H[MAX];
ll psum[MAX], A, B;

bool check(ll m) {
	ll dmg = B * m;
	ll extra = A - B;
	ll cnt = m;
	for (int i = 1; i <= N; ++i) {
		if (H[i] <= dmg) continue;
		ll need = ((H[i] - dmg) + extra - 1) / extra;
		cnt -= need;
		if (cnt < 0) return false;
	}
	return true;
}

int main()
{
	int i, j, k;
	scanf("%d%lld%lld", &N, &A, &B);
	ll maxi = 0;
	for (i = 1; i <= N; ++i) {
		scanf("%lld", &H[i]);
		maxi = max(maxi, H[i]);
		psum[i] = psum[i - 1] + H[i];
	}

	ll l = 1;
	ll h = (maxi + B)/B;
	ll m;
	sort(H, H + N);
	while (l < h) {
		m = l + (h - l) / 2;
		if (check(m)) {
			h = m;
		}
		else l = m + 1;
	}
	if (check(l)) m = l;
	printf("%lld", m);
}
