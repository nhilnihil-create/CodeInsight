#include <bits/stdc++.h>
#include <unordered_map>

const double PI = acos(-1);

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

map<ll, ll> ret;

// 素因数分解
void prime_factor(ll n) {
	//map<ll, ll> ret;
	for (ll i = 2; i * i <= n; i++) {
		while (n % i == 0) {
			ret[i]++;
			n /= i;
		}
	}
	if (n != 1) ++ret[n];
}

void solve_abc_c() {
	ll n, m;
	ll x;
	ll a;
	string s;
	string s_ans;
	ll l_ans = 0;
	double d_ans = 0;
	
	cin >> n;

	rep1(i, n) {
		prime_factor(i);
	}

	l_ans = 1;
	for (auto itr : ret) {
		l_ans *= itr.second + 1;
		l_ans %= MOD;
	}

	cout << l_ans << "\n";
}

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed;
	cout << setprecision(15);

	solve_abc_c();

	return 0;
}
