#include<iostream>
#include<vector>
#include<set>
#include<queue>
#include<map>
#include<algorithm>
#include<cstring>
#include<string>
#include<cassert>
#include<cmath>
#include<climits>
#include<iomanip>
#include<stack>
#include<unordered_map>
#include<bitset>
#include<limits>
#include<complex>
#include<array>
#include<numeric>
#include<functional>

using namespace std;
#define ll long long
#define ull unsigned long long
#define rrep(i,m,n) for(ll (i)=(ll)(m);(i)>=(ll)(n);(i)--)
#define rep(i,m,n) for(ll (i)=(ll)(m);i<(ll)(n);i++)
#define REP(i,n) rep(i,0,n)
#define FOR(i,c) for(decltype((c).begin())i=(c).begin();i!=(c).end();++i)
#define all(hoge) (hoge).begin(),(hoge).end()
typedef pair<ll, ll> P;
constexpr long double m_pi = 3.1415926535897932L;
constexpr ll MOD = 1000000007;
constexpr ll INF = 1LL << 61;
constexpr long double EPS = 1e-10;
template<typename T> using vector2 = vector<vector<T>>;
template<typename T> using vector3 = vector<vector2<T>>;
typedef vector<ll> Array;
typedef vector<Array> Matrix;
string operator*(const string& s, int k) {
	if (k == 0) return "";
	string p = (s + s) * (k / 2);
	if (k % 2 == 1) p += s;
	return p;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);


	ll h, w, d;
	cin >> h >> w >> d;
	vector2<char> ans(h, vector<char>(w));
	REP(i, h) REP(j, w) {
		ll x = i + j, y = i - j + 500;
		if ((x / d) % 2 == 0) {
			if ((y / d) % 2 == 0)ans[i][j] = 'R';
			else ans[i][j] = 'G';
		}
		else {
			if ((y / d) % 2 == 0)ans[i][j] = 'B';
			else ans[i][j] = 'Y';
		}
	}
	REP(i, h)REP(j, w)cout << ans[i][j] << (j == w - 1 ? "\n" : "");

	
	return 0;
}
