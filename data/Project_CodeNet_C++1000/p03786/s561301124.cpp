#include <iostream>
#include <iomanip>
#include <string>
#include <string.h>
#include <math.h>
#include <cmath>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <utility>
#include <deque>
#include <queue>
#include <functional>

#define rep(i, n) for(int i = 0; i < n; ++i)
#define REP(i, m, n) for(int i = m; i < n; ++i)
#define rrep(i,n) for(int i = n; i >= 0; --i)
#define RREP(i, m, n) for(int i = n; i >= m; --i)
#define llrep(i, n) for(ll i = 0; i < n; ++i)
#define llREP(i, m, n) for(ll i = m; i < n; ++i)
#define llrrep(i,n) for(ll i = n; i >= 0; --i)
#define llRREP(i, m, n) for(ll i = n; i >= m; --i)

using ll = long long;
using ull = unsigned long long;
using pii = std::pair<int, int>;
using pll = std::pair<long long, long long>;
using pli = std::pair<long long, int>;
using plpii = std::pair<long long, std::pair<int, int>>;
using pdd = std::pair<double, double>;

using namespace std;

const long long _MOD = 1000000007;
const long long MOD = 998244353;
const int ALPHABET = 27;
const double pi = 3.14159265358979;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	ll* a = new ll[n];
	rep(i, n) cin >> a[i];
	sort(a, a + n);

	ll* sum = new ll[n];
	sum[0] = a[0];
	REP(i, 1, n) sum[i] = sum[i - 1] + a[i];

	int ans = 1;
	rrep(i, n-2) {
		if (sum[i] * 2 >= a[i + 1]) ++ans;
		else break;
	}

	cout << ans << "\n";

	return 0;
}

