#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef pair<ll, ll> P;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define REP(i, a, b) for(ll i = a; i <= b; i++)
#define out(x) std::cout << x << '\n'
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
#define sz(x) ((int)(x).size())
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { ll g = gcd(a, b); return a / g * b; }
const int dx[4] = { 1, 0, -1,  0 };
const int dy[4] = { 0, 1,  0, -1 };
const int INF = (int)1e9;
const ll  inf = (ll)1e18;
const int mod = 1000000007;
const int MAX_N = 100010;
const double PI = acos(-1);

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(10);
	/*------------------------------*/

	int a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;

	double con = 0.0;
	int water = 0, sugar = 0;
	
	//水入れる回数
	for (int w = 0; w <= 30; w++) {
		for (int x = 0; x <= 30; x++) {
			//砂糖入れる回数
			for (int y = 0; y <= ceil((double)f / c); y++) {
				for (int z = 0; z <= ceil((double)f / d); z++) {
					int water_weight = a * w + b * x;
					int sugar_weight = c * y + d * z;
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

	if (con == 0.0) water = 100 * a;

	cout << water + sugar << " " << sugar << endl;

	return 0;
}