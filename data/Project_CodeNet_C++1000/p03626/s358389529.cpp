#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using V = vector<int>;
using VV = vector<V>;
using VVV = vector<VV>;
using VL = vector<ll>;
using VVL = vector<VL>;
using VVVL = vector<VVL>;
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
// const ll MOD = 998244353;
ll upper = MOD + MOD;
ll under = -upper;
ll UPPER = MOD * MOD;
ll UNDER = -UPPER;
const long double pi = 3.141592653589793;
int main() {
	int n;
	cin >> n;
	vector<string> s(2);
	rep(i, 2) {
		cin >> s[i];
	}
	ll ans = 1;
	ll prev = 3;
	for (int i = 0; i < n;) {
		if (s[0][i] == s[1][i]) {
			ans *= prev;
			ans %= MOD;
			prev = 2;
			i++;
		}
		else {
			if (prev == 1) {
				ans *= 3;
				ans %= MOD;
				prev = 1;
				i += 2;
			}
			else {
				ans *= prev;
				ans *= (prev - 1);
				ans %= MOD;
				prev = 1;
				i += 2;
			}
		}
	}
	cout << ans << endl;
	return 0;
}