#include<bits/stdc++.h>
using namespace std;
using ll = long long; 
using ull = unsigned long long;
using V = vector<int>;
using VV = vector<vector<int>>;
using VVV = vector<vector<vector<int>>>;
using VL = vector<ll>;
using VVL = vector<vector<ll>>;
using VVVL = vector<vector<vector<ll>>>;
template<class T> using pq = priority_queue<T>;
template<class T> using P = pair<T, T>;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define REP(i,k,n) for(int i=(k);i<(n);i++)
#define all(a) (a).begin(),(a).end()
#define output(x,y) cout << fixed << setprecision(y) << x << endl;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
const ll MOD = 1e9 + 7;
const ll BetsuMOD = 998244353;
ll upper = MOD + MOD;
ll under = -upper;
ll UPPER = MOD * MOD;
ll UNDER = -MOD * MOD;
const long double pi = 3.141592653589793;
int main() { // 問題文はしっかり読め!!!
	int n;
	cin >> n;
	V a(2 * n);
	rep(i, 2 * n) {
		cin >> a[i];
	}
	sort(all(a));
	ll ans = 0;
	for (int i = 0; i < 2 * n; i += 2) {
		ans += a[i];
	}
	cout << ans << endl;
	return 0;
}