#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using p = pair<int, int>;
using P = pair<ll, ll>;
using V = vector<int>;
using VV = vector<vector<int>>;
using VVV = vector<vector<vector<int>>>;
using VL = vector<ll>;
using VVL = vector<vector<ll>>;
using VVVL = vector<vector<vector<ll>>>;
using Graph = VV;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define all(a) (a).begin(),(a).end()
#define output(x,y) cout << fixed << setprecision(y) << x << endl;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
int Inf = (1 << 30);
ll inf = (1LL << 60);
const int MOD = 1e9 + 7;
int main() {
	int n, k;
	cin >> n >> k;
	V a(n);
	int M = 0;
	rep(i, n) {
		cin >> a[i];
		chmax(M, a[i]);
	}
	int GCD = a[0];
	rep1(i, n - 1) {
		GCD = gcd(GCD, a[i]); // GCDをとるという発想はあるべきだった
	}
	if (M < k || k % GCD) {
		cout << "IMPOSSIBLE" << endl;
	}
	else {
		cout << "POSSIBLE" << endl;
	}
	return 0;
}