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

using ii = pair<int, int>;
using ll = long long;
using vi = vector<int>;
using vd = vector<double>;
using vb = vector<bool>;
using vl = vector<ll>;
using vs = vector<string>;
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
template<class T>
inline T upper(T a, T b) { return (a + (b - 1)) / b; }

constexpr array<int, 9> dx = { 0, 1, 0, -1, -1, 1, 1, -1, 0 };
constexpr array<int, 9> dy = { 1, 0, -1, 0, 1, 1, -1, -1, 0 };

// ──────────────────────────────────────────────────────────────────

int main() {
	int a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;

	double con = 0.0;
	int water = 0, sugar = 0;

	for (int w = 0; w <= 30; w++) {
		for (int x = 0; x <= 30; x++) {
			for (int y = 0; y <= ceil((double)f / c); y++) {
				for (int z = 0; z <= ceil((double)f / d); z++) {
					int water_weight = a * w + b * x, sugar_weight = c * y + d * z;
					int total = 100 * water_weight + sugar_weight;

					if (total <= f && sugar_weight <= water_weight * e) {
						if (con < (double)sugar_weight / total) {
							con = (double)sugar_weight / total;
							water = 100 * water_weight;
							sugar = sugar_weight;
						}

					}
				}
			}
		}
	}
	if (con == 0) water = 100 * a;

	cout << water + sugar << " " << sugar << endl;
}
