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
constexpr long long MMOD = 500000004;
const double PI = acos(-1);
int dx[4] = { 0,1,0,-1 }, dy[4] = { 1,0,-1,0 };
# define ALL(x)     (x).begin(),(x).end()
# define UNIQ(c)    (c).erase(unique(ALL((c))), end((c)))
# define mp         make_pair
# define eb         emplace_back
# define FOR(i,a,b) for(int i=(a);i<(b);++i)
# define REP(i,n)   FOR(i,0,n)
# define INIT       std::ios::sync_with_stdio(false);std::cin.tie(0);

using P = pair<int, int>;

int main() {
	int N;
	cin >> N;

	vector<P> v(N);
	vector<int> x(N);
	for (int i = 0; i < N; i++) {
		cin >> x[i];
		x[i]--;

		v[i] = { x[i], i + 1 };
	}
	sort(ALL(v));

	static int num[510];

	vector<int> ans(N * N, -1);
	int idx = 0;

	for (int i = 0; i < N; i++) {
		int f = v[i].first;
		int s = v[i].second;

		while (idx < f && num[s] < s - 1) {
			if (ans[idx] < 0) {
				ans[idx] = s;
				num[s]++;
			}
			idx++;
		}
		if (num[s] != s - 1) {
			cout << "No" << endl;
			return 0;
		}
		ans[f] = s;
		num[s]++;
	}

	for (int i = 0; i < N; i++) {
		int n = v[i].second;
		while (idx < N * N && num[n] < N) {
			if (ans[idx] < 0) {
				ans[idx] = n;
				num[n]++;

				if (idx <= x[n - 1]) {
					cout << "No" << endl;
					return 0;
				}
			}
			idx++;
		}
	}

	int sum = 0;
	for (int n = 1; n <= N; n++) sum += num[n];

	if (sum != N * N) {
		cout << "No" << endl;
		return 0;
	}

	cout << "Yes" << endl;
	for (int a : ans) {
		cout << a << " ";
	}
	cout << endl;
}