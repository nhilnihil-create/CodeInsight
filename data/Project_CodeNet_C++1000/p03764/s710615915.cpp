#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define REP(i,n) for(int i=0; i<int(n); i++)
#define FOR(i,m,n) for(int i=int(m); i<int(n); i++)
#define ALL(obj) (obj).begin(),(obj).end()
#define VI vector<int>
#define VLL vector<long long>
#define VVI vector<vector<int>>
#define VVLL vector<vector<long long>>
#define VC vector<char>
#define VS vector<string>
#define VVC vector<vector<char>>
#define fore(i,a) for(auto &i:a)

typedef pair <int, int> P;
template<class T> bool chmax(T &a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, T b) { if (a > b) { a = b; return true; } return false; }
const int  INF = 1 << 25;
const ll INFL = 1223372036854775807;
const ll mod = 1000000007;



int main() {

	int n, m;
	cin >> n >> m;

	VLL x(n), y(m);
	REP(i, n)cin >> x[i];
	REP(i, m)cin >> y[i];

	ll a = 0, b = 0;

	REP(i, n - 1) {
		a += (x[i + 1] - x[i]) % mod*(i + 1) % mod*(n - i - 1) % mod;
		a %= mod;
	}
	REP(i, m - 1) {
		b += (y[i + 1] - y[i]) % mod*(i + 1) % mod*(m - i - 1) % mod;
		b %= mod;
	}

	cout << a*b%mod << endl;




	return 0;
}