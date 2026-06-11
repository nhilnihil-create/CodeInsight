#include<iostream>
#include<iomanip>
#include<map>
#include<unordered_map>
#include<set>
#include<unordered_set>
#include<vector>
#include<array>
#include<string>
#include<stack>
#include<queue>
#include<algorithm>
#include<cassert>
#include<functional>
#include<random>
#include<complex>
#include<bitset>
#include<chrono>
//#include<boost/multiprecision/cpp_int.hpp>
#define int int64_t
#define uint uint64_t
#define REP(i, a, b) for (int64_t i = (int64_t)(a); i < (int64_t)(b); i++)
#define rep(i, a) REP(i, 0, a)
#define SZ(X) ((int64_t)((X).size()))
#define ITR(x, a) for (auto x = a.begin(); x != a.end(); x++)
#define ALL(a) (a.begin()), (a.end())
#define HAS(a, x) (a.find(x) != a.end())
#define Min(x) *min_element(ALL(x))
#define Max(x) *max_element(ALL(x))
#define Unique(L) (L.erase(unique(ALL(L)), L.end()))
#define intmax (std::numeric_limits<int64_t>::max() / 4)
#define doublemax (std::numeric_limits<double>::max() / 4)
using namespace std;
//typedef boost::multiprecision::cpp_int bigint;
const double EPS = 1e-9;
const double PI = acos(-1.0);





signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;
	vector<vector<int>>g(N);
	rep(i, M) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	int one = 0, bip = 0, nbg = 0;

	vector<int>searched(N, 0);
	rep(i, N)if (searched[i] == 0) {
		if (g[i].size() == 0) {
			one++;
			continue;
		}
		bool bipartile_flag = true;
		stack<array<int,2>>dfs;
		dfs.push({ i,1 });
		while (!dfs.empty()) {
			auto x = dfs.top(); dfs.pop();
			int pos = x[0], color = x[1];
			if (searched[pos]) {
				if (searched[pos] != color) {
					bipartile_flag = false;
				}
				continue;
			}
			searched[pos] = color;
			for (int y : g[pos]) {
				dfs.push({ y,color == 1 ? 2 : 1 });
			}
		}
		if (bipartile_flag)bip++;
		else nbg++;
	}
	
	int ans = 0;
	ans += one * one;
	ans += 2 * one * (N - one);
	ans += nbg * nbg + 2 * bip * nbg + 2 * bip * bip;
	cout << ans << endl;

	return 0;
}