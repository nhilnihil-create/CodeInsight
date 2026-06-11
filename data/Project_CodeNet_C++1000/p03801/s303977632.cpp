/*input
10
1 2 1 3 2 4 2 5 8 1
*/

#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <cassert>
#include <algorithm>
#include <cstdlib>
#include <numeric>
#include <utility>
#include <tuple>
#include <climits>
#include <fstream>
#include <bitset>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <stack>
#include <queue>
#include <random>
#include <chrono>
#include <ios>
#include <iomanip>
#include <functional>
#include <array>

using namespace std;

#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define FORA(i, a) for (auto &i : a)
#define FORB(i, a, b) for (int i = a; i >= b; --i)
#define SZ(a) ((int) a.size())
#define ALL(a) begin(a), end(a)

typedef int64_t ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
#define fi first
#define se second

// start of code

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int N;
	cin >> N;
	vector<pii> vec(N + 1);
	vec[0] = pii(0, 0);
	FOR(i, 1, N) {
		cin >> vec[i].fi;
		vec[i].se = i;
	}

	sort(ALL(vec));
	vl ans(N + 1);
	FOR(i, 1, N) {
		ans[vec[i].se] = (ll) (vec[i].fi - vec[i - 1].fi) * (N - i + 1);
	}

	int curMin = N + 1;
	FORB(i, N, 1) {
		curMin = min(curMin, vec[i].se);
		if (curMin != vec[i].se) {
			ans[curMin] += ans[vec[i].se];
			ans[vec[i].se] = 0;
		}
	}
	FOR(i, 1, N) cout << ans[i] << '\n';
	return 0;
}
