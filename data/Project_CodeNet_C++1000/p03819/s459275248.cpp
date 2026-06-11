# include <iostream>
# include <algorithm>
# include <vector>
# include <string>
# include <set>
# include <map>
# include <cmath>
# include <iomanip>
# include <functional>
# include <utility>
# include <stack>
# include <queue>
# include <list>
# include <tuple>
# include <unordered_map>
# include <numeric>
# include <complex>
# include <bitset>
# include <random>
# include <chrono>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<LL, LL> P;
constexpr int INF = 2000000000;
constexpr int HINF = INF / 2;
constexpr double DINF = 100000000000000000.0;
constexpr long long LINF = 9223372036854775807;
constexpr long long HLINF = 4500000000000000000;
const double PI = acos(-1);
int dx[4] = { 0,1,0,-1 }, dy[4] = { 1,0,-1,0 };
# define ALL(x)      (x).begin(),(x).end()
# define UNIQ(c)     (c).erase(unique(ALL((c))),(c).end())
# define mp          make_pair
# define eb          emplace_back
# define FOR(i,a,b)  for(int i=(a);i<(b);i++)
# define RFOR(i,a,b) for(int i=(a);i>=(b);i--)
# define REP(i,n)    FOR(i,0,n)
# define INIT        std::ios::sync_with_stdio(false);std::cin.tie(0)

struct BIT {
	int s[1 << 18];
	void init() {
		REP(i, (1 << 18))s[i] = 0;
	}
	void add(int k, int x) {
		while (k > 0) {
			s[k] += x;
			k -= k&-k;
		}
	}
	int sum(int k) {
		int ret = 0;
		while (k < (1 << 18)) {
			ret += s[k];
			k += k&-k;
		}
		return ret;
	}
}bit;

int n, m, l[303030], r[303030];
int main() {
	cin >> n >> m;
	REP(i, n)cin >> l[i] >> r[i];
	vector<pair<int, int>>v;
	bit.init();
	REP(i, n)v.emplace_back(mp(r[i] - l[i] + 1, i));
	sort(ALL(v));
	int k = 0;
	for (int i = 1; i <= m; i++) {
		while (k < v.size() && v[k].first < i) {
			bit.add(l[v[k].second] - 1, -1);
			bit.add(r[v[k].second], 1);
			k++;
		}
		int ret = n - k;
		for (int j = 1; i*j <= m; j++) {
			ret += bit.sum(i*j);
		}
		cout << ret << endl;
	}
}