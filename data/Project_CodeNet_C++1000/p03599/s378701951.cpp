#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <cmath>
#include <queue>
#include <map>
#include <stack>
#include <bitset>
#include <numeric> //lcm
#include <iomanip> //double精度 setprecision

using namespace std;

#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = n-1; i >= 0; --i)
#define rep1(i,n) for(int i = 1; i <= (n); ++i)
#define rrep1(i,n) for(int i = (n); i >= 1; --i)
#define REP(i,n,m) for(int i = (n); i < (m); ++i)
#define all(vec) (vec).begin(),(vec).end()

#define debug(vec) for(auto v : vec) cerr << v << " "; cerr << endl;
#define debug2D(vec2D) for(auto vec : vec2D) { for (auto v : vec) cerr << v << " "; cerr << endl; } 
#define debugP(vec) for(auto v : vec) cerr << "(" << v.first << "," << v.second << ") "; cerr << endl;
#define debug2DP(vec2D) for(auto vec : vec2D) { for (auto v : vec) cerr << "(" << v.first << "," << v.second << ") "; cerr << endl; } 

typedef long long ll;

constexpr ll INF = 1000000000; //10^10
//const ll MOD = 998244353;
constexpr ll MOD = 1000000007;

template<class T>inline bool chmax(T& a, T b) { if (a <= b) { a = b; return true; } else return false; }
template<class T>inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } else return false; }


int main() {
	int a,b,c,d,e,f; cin >> a >> b >> c >> d >> e >> f;

	vector<ll> suma(31), sumb(31);
	suma[0] = 0;
	sumb[0] = 0;
	rep(i, 30) {
		suma[i+1] = suma[i] + 100*a;
		sumb[i+1] = sumb[i] + 100*b;
	}

	vector<ll> water(961);
	rep(i, 31) rep(j, 31) {
		water[i*31 + j] = suma[i] + sumb[j];
	}

	vector<ll> sumc(1501), sumd(1501);
	sumc[0] = 0;
	sumd[0] = 0;
	rep(i, 1500) {
		sumc[i + 1] = sumc[i] + c;
		sumd[i + 1] = sumd[i] + d;
	}

	vector<ll> sugar(2253001);
	rep(i, 1501) rep(j, 1501) {
		sugar[i * 1501 + j] = sumc[i] + sumd[j];
	}

	sort(all(water));
	sort(all(sugar));

	auto bs = [&sugar, e, f](int l, int r, int w) {
		while (l+1 < r) {
			int mid = (l + r) / 2, s = sugar[mid];
			bool ok = s <= (w / 100)*e && s + w <= f;

			if (ok) l = mid;
			else r = mid;
		}
		
		return l;
	};
  
	ll anss = -1, answ = -1;
	double per = 0;
	for (int w : water) {
		int ix = bs(-1, 2253001, w);
		if (ix >= 0 && chmax(per, 100.0*sugar[ix]/(w+sugar[ix]))) {
			anss = sugar[ix];
			answ = w;
		}
		
	}
	cout << answ + anss << " " << anss << endl;
}