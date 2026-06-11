// #pragma GCC optimize("Ofast,O3,unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")

#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <complex>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

#define endl '\n'
#define hoise cerr<<"hoise - "<<__LINE__<<"\n"
#define tham getchar()
#define set0(ar) memset(ar, 0, sizeof ar)
#define setinf(ar) memset(ar, 126, sizeof ar)
#define vsort(v) sort(v.begin(), v.end())
#define all(x) (x).begin(), (x).end()
#define FASTIO ios::sync_with_stdio(false);cin.tie(nullptr);

using ll = long long;
using pii = pair <int, int>;
using pll = pair <ll, ll>;
using vi = vector <int>;
using vl = vector <ll>;
using vpii = vector < pii >;
using vpll = vector < pll >;

const int MXN = (int)2e5+6;
const double PI = acos(-1.0);
const ll MOD = 1e9 + 7;
const int INF = 1e9;
const double EPS = 1e-6;
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};

#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cerr << *it << " = " << a << endl;
    err(++it, args...);
}

int flipBit (int mask, int k) { return mask = mask ^ (1 << k); }
bool checkBit (int mask, int k) { return (mask >> k) & 1; }
int setBit (int mask, int k) { return mask = mask | (1 << k); }
int resetBit (int mask, int k) { if (checkBit (mask, k)) { mask = flipBit (mask, k); } return mask; }

inline void normal(ll &a) { a %= MOD; (a < 0) && (a += MOD); }
inline ll modMul(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a * b) % MOD; }
inline ll modAdd(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a + b) % MOD; }
inline ll modSub(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); a -= b; normal(a); return a; }
inline ll modPow(ll b, ll p) { ll r = 1; while (p) { if (p & 1) r = modMul(r, b); b = modMul(b, b); p >>= 1; } return r; }
inline ll modInverse(ll a) { return modPow(a, MOD - 2); }
inline ll modDiv(ll a, ll b) { return modMul(a, modInverse(b)); }

template <typename T> using orderedSet = tree<T, null_type, greater<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T> using orderedSet1 = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

bool approximatelyEqual(float a, float b, float epsilon) {
    return fabs(a - b) <= ( (fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * epsilon);
}
bool essentiallyEqual(float a, float b, float epsilon) {
    return fabs(a - b) <= ( (fabs(a) > fabs(b) ? fabs(b) : fabs(a)) * epsilon);
}
bool definitelyGreaterThan(float a, float b, float epsilon) {
    return (a - b) > ( (fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * epsilon);
}
bool definitelyLessThan(float a, float b, float epsilon) {
    return (b - a) > ( (fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * epsilon);
}

/*--------------------------------------------------------------------------------------------------------------------------*/



void solve () {
	
	int n, L;
	cin >> n >> L;
	
	vl a (n);
	
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	
	int f = -1;
	
	for (int i = 1; i < n; ++i) {
		if (a[i] + a[i - 1] >= L) {
			f = i - 1;
			break;
		}
	}
	
	if (f == -1) {
		cout << "Impossible\n";
		return;
	}
	cout << "Possible\n";
	for (int i = 0; i < f; ++i) {
		cout << i + 1 << endl;
	}
	for (int i = n - 1; i > f; --i) {
		cout << i << endl;
	}
}

int main(){
	// FASTIO
	
	int t;
	// cin >> t;
	t = 1;
	
	while (t--) {
		solve ();
	}
	
    return 0;
}

/*
 * be careful before submitting in Lightoj, SPOJ, UVA
*/
