
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
#include <complex>
#include <cstdint>
#include <tuple>
#include <numeric>
#define M_PI       3.14159265358979323846


using namespace std;

//conversion
//------------------------------------------
inline int toInt(string s) { int v; istringstream sin(s); sin >> v; return v; }
template<class T> inline string toString(T x) { ostringstream sout; sout << x; return sout.str(); }

//typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
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
#define MT make_tuple
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())
#define FILL(a, x) memset(a, x, sizeof(a))

//repetition
//------------------------------------------
#define FOR(i,s,n) for(int i=s;i<(int)n;++i)
#define REP(i,n) FOR(i,0,n)

const int N = 100005;
LL a[N], cnt[2*N], cnt2[2*N];

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	REP(i, n)scanf("%lld", &a[i]);
	LL bias = 0;
	REP(i, n - 1) {
		int p = a[i];
		int q = a[i + 1];
		if (q < p)q += m;
		bias += q - p;
		if (q >= p + 2) {
			cnt[p + 2]++;
			cnt[q + 1]--;
			cnt2[q + 1] -= q - p - 1;
		}
	}
	FOR(i, 1, 2 * m + 2)cnt[i] += cnt[i - 1];
	FOR(i, 1, 2 * m + 2)cnt[i] += cnt2[i];
	FOR(i, 1, 2 * m + 2)cnt[i] += cnt[i - 1];
	LL ans = bias;
	FOR(i, 1, m+1) {
		ans = min(ans, bias - cnt[i] - cnt[i + m]);
	}
	printf("%lld\n", ans);
	return 0;
}