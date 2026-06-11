
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

int main() {
	int n; cin >> n;
	vector<vector<LL>> d(n, vector<LL>(n));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> d[i][j];
		}
	}

	//a+b<cとなってると、cが矛盾する
	for (int m = 0; m < n; m++) {
		for (int s = 0; s < n; s++) {
			for (int t = 0; t < n; t++) {

				if (d[s][m] + d[m][t] < d[s][t]) {
					cout << "-1" << endl;
					return 0;
				}

			}
		}
	}
	

	//a+b==cとなってるcは渡れないことにする
	for (int m = 0; m < n; m++) {
		for (int s = 0; s < n; s++) {
			for (int t = 0; t < n; t++) {
				if (s == t || t == m || s == m)continue;

				if (d[s][m] + d[m][t] == d[s][t]) {
					d[s][t] = INF2;
				}
			}
		}
	}
	

	LL ans = 0;

	//生き残った辺を足し上げていく
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			if (d[i][j] != INF2)ans += d[i][j];
		}
	}

	cout << ans << endl;

	return 0;
}