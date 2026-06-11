#include <iostream>
#include <vector>
#include <cassert>
#include <string>
#include <map>
#include <algorithm>
#define REP(i, n) for(int i = 0; i < (n); ++i)
#define RREP(i, n) for(int i = n - 1; i >= 0; --i)
using namespace std;
using ll = long long;

constexpr ll MOD = 1000000007;
constexpr int MAX = 10010;

ll n, m;

int main() {
	cin >> n >> m;
	if (n < m) swap(n, m);
	if (n - m > 1) {
		cout << 0;
		return 0;
	}

	ll ans = 1;
	REP(i, n) (ans *= i + 1) %= MOD;
	REP(i, m) (ans *= i + 1) %= MOD;
	if (n == m) ans = ans * 2 % MOD;
	cout << ans;
	return 0;
}