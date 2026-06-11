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
using namespace std;
using LL = long long;
using ULL = unsigned long long;
constexpr int INF = 2000000000;
constexpr int HINF = INF / 2;
constexpr double DINF = 100000000000000000.0;
constexpr long long LINF = 9223372036854775807;
constexpr long long HLINF = 4500000000000000000;
const double PI = acos(-1);
int dx[4] = { 0,1,0,-1 }, dy[4] = { 1,0,-1,0 };
# define ALL(x)     (x).begin(),(x).end()
# define UNIQ(c)    (c).erase(unique(ALL((c))), end((c)))
# define mp         make_pair
# define eb         emplace_back
# define FOR(i,a,b) for(int i=(a);i<(b);++i)
# define REP(i,n)   FOR(i,0,n)
# define INIT       std::ios::sync_with_stdio(false);std::cin.tie(0);

LL w, h;
int main() {
	cin >> w >> h;
	vector<pair<LL, int>>v;//コスト、縦0横1
	for (int i = 0; i < w; i++) {
		int a;
		cin >> a;
		v.emplace_back(mp(a, 0));
	}
	for (int i = 0; i < h; i++) {
		int a;
		cin >> a;
		v.emplace_back(mp(a, 1));
	}
	sort(ALL(v));
	w++, h++;
	LL ans = 0;
	for (int i = 0; i < v.size(); i++) {
		if (v[i].second == 0) {
			ans += v[i].first*h;
			w--;
		}
		else {
			ans += v[i].first*w;
			h--;
		}
	}
	cout << ans << endl;
}