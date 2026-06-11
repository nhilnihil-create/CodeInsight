#include <iostream>
#include <cstdio>
#include <algorithm>
#define S second
using namespace std;
typedef long long ll;

ll n, k, a, s, ans, tr[200005];
pair<ll, ll> b[200005];

ll qry(ll p) {
	ll re = 0;
	for(; p; p -= p & -p) re += tr[p];
	return re;
}

void upd(ll p) {
	for(; p<=n+1; p += p & -p) tr[p]++;
}

int main() {
	ll i, j;
	cin >> n >> k;
	for(i=1; i<=n; i++) {
		scanf("%lld", &a);
		s += a;
		b[i] = {s-k*i, i};
	}
	sort(b, b+n+1);
	for(i=0; i<=n; i++) {
		ans += qry(b[i].S);
		upd(b[i].S + 1);
	}
	cout << ans;
	return 0;
}
