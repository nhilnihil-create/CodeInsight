#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <queue>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <fstream>
#include <stdio.h>
#include <complex>
#include <cstdint>
#include <tuple>

#define M_PI       3.14159265358979323846

using namespace std;

//conversion
//------------------------------------------
inline int toInt(string s) { int v; istringstream sin(s); sin >> v; return v; }
template<class T> inline string toString(T x) { ostringstream sout; sout << x; return sout.str(); }
inline int readInt() { int x; scanf("%d", &x); return x; }

//typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef pair<int, PII> TIII;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<LL> VLL;
typedef vector<VLL> VVLL;

//container util

//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define SQ(a) ((a)*(a))
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())

//repetition
//------------------------------------------
#define FOR(i,s,n) for(int i=s;i<(int)n;++i)
#define REP(i,n) FOR(i,0,n)
#define MOD 1000000007

const int N = 100005;
LL cost_x[N], cost_y[N];

int main() {
	int wh[2];
	REP(i, 2)scanf("%d", &wh[i]);
	vector<pair<LL, LL>> cost_xy(wh[0] + wh[1]);
	int idx = 0;
	REP(i, 2) {
		REP(j, wh[i]) {
			int x;
			scanf("%d", &x);
			cost_xy[idx++] = MP(x, i);
		}
	}
	SORT(cost_xy);
	int cnt[2] = { 0, };
	LL ret = 0;
	REP(i, wh[0] + wh[1]) {
		LL cost = cost_xy[i].first;
		int d = cost_xy[i].second;
		ret += (wh[1 - d] + 1 - cnt[1 - d])*cost;
		cnt[d]++;
	}
	cout << ret << endl;
	return 0;
}