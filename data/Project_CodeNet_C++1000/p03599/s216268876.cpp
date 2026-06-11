#include "bits/stdc++.h"
using namespace std;

#define ASC(vec) vec.begin(), vec.end()    // 昇順ソート 例：sort(ASC(vec));
#define DESC(vec) vec.rbegin(), vec.rend() // 降順ソート 例：sort(DESC(vec));
#define rep(i, n) for (int i = 0; i < (n); i++)
#define Rep(i, n) for (int i = 1; i < n; i++)
#define REP(i, vec) for (auto i = vec.begin(); i != vec.end(); ++i)

const int       mod = 1000000007;
const int       inf = (1 << 21);
const long long INF = 1LL << 60;

using ll  = long long;
using ii  = pair<int, int>;
using vi  = vector<int>;
using vd  = vector<double>;
using vb  = vector<bool>;
using vl  = vector<ll>;
using vs  = vector<string>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;
using vvb = vector<vector<bool>>;
using vii = vector<pair<int, int>>;
using vll = vector<pair<ll, ll>>;

template<class T>
inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T>
inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T>
T GCD(T a, T b) { if (b == 0) return a; else return GCD(b, a % b); }
template<class T>
T LCM(T a, T b) { return a / GCD(a, b) * b; }

constexpr array<int, 9> dx = { 0, 1, 0, -1, -1, 1, 1, -1, 0 };
constexpr array<int, 9> dy = { 1, 0, -1, 0, 1, 1, -1, -1, 0 };

// ──────────────────────────────────────────────────────────────────

int main() {
	int a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;

	double con = 0.0;
	int w = 0, s = 0;

	for (int i = 0; i <= 30; ++i) {
		for (int j = 0; j <= 30; ++j) {
			for (int k = 0; k <= ceil((double)f / c); ++k) {
				for (int l = 0; l <= ceil((double)f / d); ++l) {
					int water = a * i + b * j;
					int suger = c * k + d * l;
					int total = 100 * water + suger;

					if (total <= f && suger <= water * e) {
						if (con < (double)suger / total) {
							con = (double)suger / total;
							w = 100 * water;
							s = suger;
						}
					}
				}
			}
		}
	}
	if (con == 0) w = 100 * a;

	cout << w + s << " " << s << endl;

}