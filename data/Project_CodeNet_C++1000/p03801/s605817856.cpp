
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
LL a[N];
int pre[N];
LL ans[N];

int main() {
	int n;
	scanf("%d", &n);
	REP(i, n)scanf("%lld", &a[i+1]);
	int prev = 0;
	FOR(i, 1, n+2) {
		pre[i] = prev;
		if (a[i] > a[prev])prev = i;
	}
	priority_queue<PII> q;
	int idx = n+1;
	while (idx>0) {
		int target = pre[idx];
		while (target < idx) {
			q.push(MP(a[idx], 1));
			idx--;
		}
		int cnt = 0;
		LL ret = 0;
		while (!q.empty() && q.top().first >= a[pre[idx]]) {
			ret += ((LL)(q.top().first - a[pre[idx]])) * q.top().second;
			cnt += q.top().second;
			q.pop();
		}
		q.push(MP(a[pre[idx]], cnt));

		ret += a[idx] - a[pre[idx]];
		ans[idx] = ret;
		a[idx] = a[pre[idx]];
	}
	FOR(i, 1, n + 1)printf("%lld\n", ans[i]);
	return 0;
}