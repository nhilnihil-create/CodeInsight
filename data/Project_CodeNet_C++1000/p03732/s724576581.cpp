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
template<class T> using VE = vector<T>;
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
// const ll MOD = 1e9 + 7;
const ll MOD = 998244353;
ll upper = MOD + MOD;
ll under = -upper;
ll UPPER = MOD * MOD;
ll UNDER = -UPPER;
const long double pi = 3.141592653589793;
int main() {
	ll n, w;
	cin >> n >> w;
	VL w1, w2, w3, w4;
	ll Base;
	rep(i, n) {
		int a, b;
		cin >> a >> b;
		if (i == 0) {
			Base = a;
			w1.push_back(b);
		}
		else {
			if (a - Base == 0) w1.push_back(b);
			if (a - Base == 1) w2.push_back(b);
			if (a - Base == 2) w3.push_back(b);
			if (a - Base == 3) w4.push_back(b);
		}
	}
	ll ans = 0;
	sort(all(w1), greater<ll>()); sort(all(w2), greater<ll>()); sort(all(w3), greater<ll>()); sort(all(w4), greater<ll>());
	w1.insert(w1.begin(), 0); w2.insert(w2.begin(), 0); w3.insert(w3.begin(), 0); w4.insert(w4.begin(), 0);
	rep1(i, w1.size() - 1) w1[i] += w1[i - 1];
	rep1(i, w2.size() - 1) w2[i] += w2[i - 1];
	rep1(i, w3.size() - 1) w3[i] += w3[i - 1];
	rep1(i, w4.size() - 1) w4[i] += w4[i - 1];
	rep(i, w1.size()) rep(j, w2.size()) rep(k, w3.size()) rep(l, w4.size()) {
		ll W = i * Base + j * (Base + 1) + k * (Base + 2) + l * (Base + 3);
		if (W > w) continue;
		ll tmp = w1[i] + w2[j] + w3[k] + w4[l];
		chmax(ans, tmp);
	}
	cout << ans << endl;
	return 0;
}