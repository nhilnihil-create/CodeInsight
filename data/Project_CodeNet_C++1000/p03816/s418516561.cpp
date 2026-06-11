#include <bits/stdc++.h>
#include <unordered_set>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
using P = pair<ll, ll>;
using V = vector<ll>;
#define rep(i, n) for(ll i=0;i<(ll)(n);i++)
#define rep1(i, n) for(ll i=1;i<=(ll)(n);i++)
#define rep2(i, m, n) for(ll i=m;i<(ll)(n);i++)
#define rrep(i, n, m) for(ll i=n;i>=(ll)(m);i--)
#define ALL(obj) (obj).begin(), (obj).end()
#define RALL(obj) (obj).rbegin(), (obj).rend()
#define MOD 1000000007
#define INF 1000000000

void solve_abc_d() {
	ll n;
	ll x;
	ll k;
	ll l_ans = 0;
	cin >> n;

	map<ll, ll> m;
	ll a;
	rep(i, n) {
		cin >> a;
		++m[a];
	}

	ll sum = 0;
	ll num = 0;
	for (auto itr = m.begin(); itr != m.end(); itr++) {
		if (itr->second % 2 == 1) {
			sum += itr->second - 1;
		}
		else {
			sum += itr->second - 2;
			if (num == 0) {
				num++;
			}
			else {
				sum += 2;
				num = 0;
			}
		}
	}

	l_ans = n - sum - num * 2;

	cout << l_ans << "\n";
	return;
}

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed;
	cout << setprecision(7);

	solve_abc_d();

	return 0;
}
