#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T = double>
using point = complex<T>; // 2D point only

using ll = long long;
using ull = unsigned long long;
using ldob = long double;

template <typename T = int>
using ii = pair<T,T>;
template <typename T = int>
using iii = pair<T,ii<T>>;
template <typename T = int>
using ii_i = pair<ii<T>,T>;
template <typename T = int>
using vi = vector<T>;
template <typename T = int>
using vvi = vector<vi<T>>;
template <typename T = int>
using vii = vector<ii<T>>;
template <typename T = int>
using viii = vector<iii<T>>;
template <typename T = int>
using lim = numeric_limits<T>;

#ifdef _DEBUG
#define debug_text(...) printf(__VA_ARGS__)
#else
#define debug_text(...) /* --- NOTHING --- */
#endif

#define re real()
#define im imag()
#define fi first
#define se second
#define sz(v) (v).size()
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

// OST
template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// from: https://codeforces.com/blog/entry/62393
// struct custom_hash {
// 	static uint64_t splitmix64(uint64_t x) {
// 		// http://xorshift.di.unimi.it/splitmix64.c
// 		x += 0x9e3779b97f4a7c15;
// 		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
// 		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
// 		return x ^ (x >> 31);
// 	}

// 	size_t operator()(uint64_t x) const {
// 		static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
// 		return splitmix64(x + FIXED_RANDOM);
// 	}
// };

const int INF = ~(1<<31);
const ll LINF = (1LL << 60);
const long double EPS = 1e-9;
const long double PI = acos(-1);

const int N = 1005;
const int M = 1 << 19;
const int MOD = 1e9+7; // 998244353;
const int MOD2 = 1e9+9;
const int IMAX = 1e9+7;
const ll LMOD = 1LL << 59;
const ll LMAX = 1e16+7;
const ll P = 131;
const ll P2 = 151;
const int dx[4] = {0,0,-1,1};
const int dy[4] = {-1,1,0,0};
const int dx8[8] = {-1,-1,-1,0,0,1,1,1};
const int dy8[8] = {-1,0,1,-1,1,-1,0,1};

void solution() {
	ll x; cin >> x;
	ll l = 0, r = 1e9+1;
	for (int i = 0; i < 100; ++i) {
		ll mid = l + (r - l) / 2;
		if (mid*(mid+1)/2 >= x) {
			r = mid;
		} else {
			l = mid;
		}
	}
	cout << l+1 << endl;
}

void pregen() {
	
}

void prepare() {
	
}

int main () {
	ios_base::sync_with_stdio(false); cin.tie(0); // cout.tie(0);
	// cout.precision(2); cout << fixed;

	int T = 1;
	// cin >> T;
	pregen();
	for (int i = 1; i <= T; ++i) {
		prepare();
		solution();
	}

	return 0;
}