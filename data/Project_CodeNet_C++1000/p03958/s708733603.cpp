#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
#define all(x) (x).begin(), (x).end()
#define fsp(x) fixed << setprecision(x)
const ll inf = LLONG_MAX;
const long double pi = acos(-1);
void Yes() {cout << "Yes" << endl;}
void No() {cout << "No" << endl;}
void YES() {cout << "YES" << endl;}
void NO() {cout << "NO" << endl;}

int main() {
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//const ll p = 1e9 + 7;
	//const ll p = 998244353;

	ll k, t;
	cin >> k >> t;
	vll a(t);
	priority_queue<vll> pq;
	for (ll i = 0; i < t; i++) {
		cin >> a[i];
		pq.push({a[i], i});
	}

	ll ans = 0;
	ll prev = -1;
	while (k--) {
		vll v = pq.top();
		pq.pop();
		if (v[1] != prev) {
			v[0]--;
			if (v[0] > 0) pq.push(v);
			prev = v[1];
		}
		else if (pq.empty()) {
			v[0]--;
			if (v[0] > 0) pq.push(v);
			prev = v[1];
			ans++;
		}
		else {
			vll w = pq.top();
			pq.pop();
			w[0]--;
			pq.push(v);
			if (w[0] > 0) pq.push(w);
			prev = w[1];
		}
	}
	cout << ans << endl;
}
