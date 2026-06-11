#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using ull = unsigned long long;

typedef pair<ll, ll> P;
typedef pair<ll, P> PP;

const ll MOD = 1e9 + 7;
const ll INF = 9e18;
const double eps = -1e10;
const int di[4] = { 1,0,-1,0 }, dj[4] = { 0,1,0,-1 };

#define ALL(x) (x).begin(),(x).end()
#define pb push_back
#define eb emplace_back
#define fr first
#define sc second

ll n, K, a[100010], b[100010], ans;

bool check(ll cul, ll need) {
	for (int i = 0;i < 30;i++) {
		if (!(need&(1 << i)) && (cul&(1 << i)))return false;
	}
	return true;
}

int main() {
	cin >> n >> K;
	for (int i = 0;i < n;i++) {
		cin >> a[i] >> b[i];
	}
	for (int i = 0;i < 31;i++) {
		if ((1 << i) > K)break;
		ll now = 0, need = K, sum = 0;
		if (need&(1 << i)) {
			need &= ~(1 << i);
			for (int j = 0;j < i;j++)need |= (1 << j);
		}
		for (int j = 0;j < n;j++) {
			ll cul = now;
			cul |= a[j];
			if (check(cul, need)) {
				sum += b[j];
				now |= a[j];
			}
		}
		ans = max(ans, sum);
	}
	ll now = 0, need = K, sum = 0;
	for (int j = 0;j < n;j++) {
		ll cul = now;
		cul |= a[j];
		if (check(cul, need)) {
			sum += b[j];
			now |= a[j];
		}
	}
	ans = max(ans, sum);
	cout << ans << endl;
	return 0;
}
