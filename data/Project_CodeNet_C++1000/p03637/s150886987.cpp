#include <bits/stdc++.h>
#include <unordered_map>

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

void solve_abc_c() {
	ll n;
	ll ans = 1;

	cin >> n;

	V a(n);
	V o, e4;
	rep(i, n) {
		cin >> a[i];
		if (a[i] % 2 == 1) {
			o.push_back(a[i]);
		}
		else if (a[i] % 4 == 0) {
			e4.push_back(a[i]);
		}
	}
	
	if (n % 2 == 0) {
		if (o.size() <= e4.size()) {
			cout << "Yes" << "\n";
		}
		else {
			cout << "No" << "\n";
		}
	}
	else {
		if (o.size() - 1 <= e4.size()) {
			cout << "Yes" << "\n";
		}
		else {
			cout << "No" << "\n";
		}
	}

}

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);

	solve_abc_c();

	return 0;
}
