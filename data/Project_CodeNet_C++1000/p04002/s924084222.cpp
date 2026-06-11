// see https://gist.github.com/LumaKernel/ff55d49ee1af69b7388f15b707e75c15
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <complex>
#include <random>
#include <iomanip>

using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef vector<int> VI;
typedef vector<P> VP;

#define omajinai ios::sync_with_stdio(false);cin.tie(0)

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define RFOR(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define RREP(i,n) RFOR(i,0,n)

#define LFOR(i,a,b) for(ll i=(a);i<(b);++i)
#define RLFOR(i,b,a) for(ll i=(b)-1;i>=(a);--i)

#define ALL(a) (a).begin(),(a).end()
#define UNIQUE(a) (a).erase(unique((a).begin(),(a).end()),(a).end())
#define MP make_pair
#define PB push_back
#define EACH(i,c) REP(i,(int)(c).size())
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())

#define dump(x) cerr << "[L " << __LINE__ << "] " << #x << " = " << (x) << "\n";
#define dump2(x,y) cerr << "[L " << __LINE__ << "] " << #x << " = " << (x)\
			<< " , " << #y << " = " << (y) << "\n";

const int INF = 1e9;
const double EPS = 1e-10;

ll n, h, w;
P p[100000];
set<P> st,ext;
ll cs[10];

int main() {
	cin >> h >> w >> n;

	REP(i, n){
		int x,y;
		cin >> y >> x;
		x--;y--;
		p[i] = MP(x, y);
		ext.insert(p[i]);
	}

	ll sum = 0;
	REP(i, n){
		FOR(dx, -2, 1)FOR(dy, -2, 1){
			int nx = p[i].first + dx, ny = p[i].second + dy;
			P t = MP(nx, ny);
			if(nx < 0) continue;
			if(ny < 0) continue;
			if(nx >= w - 2) continue;
			if(ny >= h - 2) continue;
			if(EXIST(st, t))continue;
			st.insert(t);

			int c = 0;
			REP(px, 3)REP(py, 3){
				int sx = nx + px, sy = ny + py;
				if(EXIST(ext, MP(sx, sy)))c++;
			}
			cs[c]++;
			sum++;
		}
	}

	cs[0] = (ll)(w-2) * (h-2) - sum;

	REP(i, 10){
		cout << cs[i] << endl;
	}
}
