#define _USE_MATH_DEFINES 
#include<iomanip> 
#include<cmath>  
#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<bitset>
#include<map>
#include<unordered_map>
#include<set>
#include<unordered_set>
#include<queue>
#include<deque>
#include<stack>
using namespace std;
typedef long long ll;
#define repi(i,a,b) for(ll i = (ll)(a) ; i < (ll)(b) ; i++)
#define repd(i,a,b) for(ll i = (ll)(a) ; i > (ll)(b) ; i--)
#define rd(x) cin >> x
#define wr(x)  cout << x
#define wrln(x) cout << x << endl
const ll MAX_10p5 = 100010;
const ll MAX_10p9 = 1000000010;
const ll MAX_10p18 = 1000000000000000010;
const ll MOD = 1000000007;
const ll m4x[4] = { 1,0,-1,0 };
const ll m4y[4] = { 0,1,0,-1 };
const ll m8x[8] = { 1,1,0,-1,-1,-1,0,1 };
const ll m8y[8] = { 0,1,1,1,0,-1,-1,-1 };
const ll m9x[9] = { 1,1,0,-1,-1,-1,0,1,0 };
const ll m9y[9] = { 0,1,1,1,0,-1,-1,-1,0 };

struct edge {
	ll to, cost;
	bool operator<(const edge& right) const {
		return cost == right.cost ? to < right.to : cost < right.cost;
	}
};
struct point {
	ll x, y;
	bool operator<(const point& right) const {
		return x == right.x ? y < right.y : x < right.x;
	}
};

///////////////////////////////////////////////////////////////////////////////////////

ll H, W, N;
vector<point> PV;
set<point> PM;
set<point> visited;
ll ans[10];

ll solv(ll x, ll y) {
	ll count = 0;
	if (x > 1 && x < H && y>1 && y < W) {
		repi(i, 0, 9) {
			point tp;
			tp.x = x + m9x[i], tp.y = y + m9y[i];
			if (PM.find(tp) != PM.end()) count++;
		}
	}
	return count;
}

int main() {
	cin >> H >> W >> N;
	repi(i, 0, N) {
		point P;
		cin >> P.x >> P.y;
		PV.push_back(P);
		PM.insert(P);
	}
	repi(i, 0, N) {
		repi(j, 0, 9) {
			point tp;
			tp.x = PV[i].x + m9x[j], tp.y = PV[i].y + m9y[j];
			if (visited.find(tp) == visited.end()) {
				ll tsum = solv(tp.x, tp.y);
				ans[tsum]++;
				visited.insert(tp);
			}
		}
	}
	ans[0] = (H - 2)*(W - 2);
	repi(i, 1, 10) ans[0] -= ans[i];
	repi(i, 0, 10) wrln(ans[i]);
	return 0;
}
