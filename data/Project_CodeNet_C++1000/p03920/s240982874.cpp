#include "bits/stdc++.h"
#include <unordered_set>

#define _CRT_SECURE_NO_WARNINGS

#define FOR(i, x, n) for(decltype(x) i = (x); i < (n); i++)
#define REP(i, n) for(decltype(n) i = 0; i < (n); i++)
#define RREP(i, n) for (decltype(n) i = (n) - 1; i >= 0; i--)

#define ALL(a) (a).begin(),(a).end()
#define SORT(c) sort((c).begin(),(c).end())
#define DESCSORT(c) sort(c.begin(), c.end(), greater<int>())

using namespace std;

const int dy[] = { 0, 1, 0, -1 };
const int dx[] = { 1, 0, -1, 0 };

using LL = long long int;
using LD = long double;

const int INF = (1 << 30) - 1;
const LL INF64 = ((LL)1 << 62) - 1;
const double PI = 3.1415926535897932384626433832795;

using pii = pair<int, int>;
using pll = pair<LL, LL>;
using pdd = pair<double, double>;
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using vl = vector<LL>;
using vvl = vector<vl>;
using vvvl = vector<vvl>;
using vd = vector<double>;
using vvd = vector<vd>;
using vs = vector<string>;
using vb = vector<bool>;
using vvb = vector<vb>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	int x = 0, y = 0;
	FOR(i, 1, 100001) {
		x += i;
		if (n <= x) {
			x = i;
			break;
		}
	}

	for (; n; x--) {
		if (x <= n) {
			cout << x << endl;
			n -= x;
		}
	}
	return 0;
}