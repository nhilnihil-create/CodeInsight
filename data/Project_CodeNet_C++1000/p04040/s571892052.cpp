
//include
//------------------------------------------
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
#include <sstream>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <string>
#include <cstring>
#include <ctime>
#include <climits>
#include <limits>

using namespace std;

//conversion
//------------------------------------------
inline int toInt(string s) { int v; istringstream sin(s); sin >> v; return v; }
template<class T> inline string toString(T x) { ostringstream sout; sout << x; return sout.str(); }

//math
//-------------------------------------------
template<class T> inline T sqr(T x) { return x * x; }

//typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long LL;

//container util
//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define EXISTch(s,c) ((((s).find_first_of(c)) != std::string::npos)? 1 : 0)//cがあれば1 if(1)
#define SORT(c) sort((c).begin(),(c).end())

#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)

//constant
//--------------------------------------------
const double EPS = 1e-10;
const double PI = acos(-1.0);
const int INF = (int)1000000007;
const LL MOD = (LL)1000000007;//10^9+7
const LL INF2 = (LL)100000000000000000;//10^18


template< int mod >
struct Combination
{
	vector< int64_t > mfact, rfact;

	Combination(int sz) : mfact(sz + 1), rfact(sz + 1)
	{
		mfact[0] = 1;
		for (int i = 1; i < mfact.size(); i++) {
			mfact[i] = mfact[i - 1] * i % mod;
		}
		rfact[sz] = inv(mfact[sz]);
		for (int i = sz - 1; i >= 0; i--) {
			rfact[i] = rfact[i + 1] * (i + 1) % mod;
		}
	}

	int64_t fact(int k) const
	{
		return (mfact[k]);
	}

	int64_t pow(int64_t x, int64_t n) const
	{
		int64_t ret = 1;
		while (n > 0) {
			if (n & 1) (ret *= x) %= mod;
			(x *= x) %= mod;
			n >>= 1;
		}
		return (ret);
	}

	int64_t inv(int64_t x) const
	{
		return (pow(x, mod - 2));
	}

	int64_t P(int n, int r) const
	{
		if (r < 0 || n < r) return (0);
		return (mfact[n] * rfact[n - r] % mod);
	}

	int64_t C(int p, int q) const
	{
		if (q < 0 || p < q) return (0);
		return (mfact[p] * rfact[q] % mod * rfact[p - q] % mod);
	}

	int64_t H(int n, int r) const
	{
		if (n < 0 || r < 0) return (0);
		return (r == 0 ? 1 : C(n + r - 1, r));
	}
};


int main() {

	Combination<MOD> com(200010);
	
	int h, w, a, b; cin >> h >> w >> a >> b;

	LL ans = 0;
	for (int mw = b+1; mw<=w ; mw++) {
		//中継点の高さ
		int mh = h - a;

		//始点(1,1)からw1,h1動く
		int w1 = mw - 1;
		int h1 = mh - 1;

		LL route1=com.C(w1 + h1, w1);

		//中継点から高さ+1した位置からゴール(h,w)へ移動する
		//w2,h2動く

		int w2 = w - mw;
		int h2 = h - (mh+1);

		LL route2 = com.C(w2 + h2, w2);

		ans = (ans+route1*route2) % MOD;
		
		
	}

	cout << ans << endl;

	return 0;
}