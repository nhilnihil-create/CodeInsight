#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <stack>
#include <queue>

#define FOR(i, b, e) for(ll i = (ll)(b); i < (ll)(e); ++i)
#define RFOR(i, b, e) for(ll i = (ll)(e-1); i >= (ll)(b); --i)
#define REP(i, n) FOR(i, 0, n)
#define RREP(i, n) RFOR(i, 0, n)
#define REPC(x,c) for(const auto& x:(c))
#define VS vector<string>
#define VL vector<long long>
#define VI vector<int>
#define VVI vector<vector<int>>
#define VVL vector<vector<ll>>
#define ALL(x) (x).begin(),(x).end()
#define SORT(x) sort(ALL(x))
#define RSORT(x) sort((x).rbegin(),(x).rend())
#define PAIR pair<ll,ll>
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );

using  ll = long long;
constexpr ll MOD = 1000000007;
using std::cout;
using std::endl;
using std::cin;
using std::sort;
using std::pair;
using std::string;
using std::stack;
using std::vector;
using std::list;
using std::map;
using std::unordered_map;
using std::multimap;
using std::unordered_multimap;
using std::set;
using std::unordered_set;
using std::multiset;

ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
ll pow(ll a, ll b) {
	ll ans = 1;
	while (b > 0) {
		if (b % 2 == 1) {
			ans *= a;
			ans %= MOD;
		}
		b /= 2;
		a *= a;
		a %= MOD;
	}
	return ans;
}
ll comb(ll a, ll b) {
	if (a - b < b) { return comb(a, a - b); }
	ll c = 1;
	FOR(i, a - b + 1, a + 1) {
		c *= i;
		c %= MOD;
	}
	ll k = 1;
	FOR(i, 2, b + 1) {
		k *= i;
		k %= MOD;
	}
	c *= pow(k, MOD - 2);
	return c % MOD;
}
multiset<ll> prime_decomposition(ll n) {
	ll i = 2;
	multiset<ll> table{};
	while (i * i <= n) {
		while (n % i == 0) {
			n /= i;
			table.emplace(i);
		}
		++i;
	}
	if (n > 1) {
		table.emplace(n);
		return table;
	}
	return table;
}

int main() {
	int n;
	cin >> n;
	VL v(n);
	REP(i, n) { cin >> v[i]; }

	ll c = 0;
	REP(i, n - 1) {
		if (v[i] == i + 1) {
			++c;
			std::swap(v[i], v[i + 1]);
		}
	}
	cout << ((v[n - 1] == n) ? c + 1 : c) << endl;
}