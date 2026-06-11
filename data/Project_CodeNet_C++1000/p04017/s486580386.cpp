
#include <vector>
#include <list>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
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
#include <cstdio>
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
int x[N];
int nex[2][N][31];

int main() {
	int n, l, q;
	scanf("%d", &n);
	REP(i, n)scanf("%d", &x[i]);
	scanf("%d%d", &l, &q);
	REP(i, n) {
		nex[0][i][0] = upper_bound(x, x + n, x[i] + l) - x - 1;
		nex[1][i][0] = lower_bound(x, x + n, x[i] - l) - x;
	}
	FOR(j, 1, 31) {
		REP(i, n) {
			nex[0][i][j] = nex[0][nex[0][i][j - 1]][j - 1];
			nex[1][i][j] = nex[1][nex[1][i][j - 1]][j - 1];
		}
	}
	REP(qq, q) {
		int a, b;
		scanf("%d%d", &a, &b);
		a--, b--;
		int s = 20;
		int mask = 0;
		while (s > 0) {
			s--;
			if (a < b) {
				if (nex[0][a][s] < b) {
					mask |= 1 << s;
					a = nex[0][a][s];
				}
			}
			else{
				if (nex[1][a][s] > b) {
					mask |= 1 << s;
					a = nex[1][a][s];
				}
			}
		}
		printf("%d\n", mask + 1);
	}
	return 0;
}