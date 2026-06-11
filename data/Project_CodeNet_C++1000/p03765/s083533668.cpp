#include <algorithm>
#include <assert.h>
#include <bitset>
#include <cfloat>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits.h>
#include <list>
#include <map>
#include <math.h>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <string.h>
#include <time.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<=n;i++)
#define int long long
#define ll long long
#define eps LDBL_EPSILON
#define mod (ll)1000000007
#define INF LLONG_MAX/10
#define P pair<int,int>
#define prique priority_queue
using namespace std;
string s, t;
int q, a[100010], b[100010];
int l1, r1, l2, r2;
signed main() {
	cin >> s >> t;
	rep(i, s.size()) {
		if (s[i] == 'A')a[i] = 1;
		else a[i] = 2;
		if (i)a[i] += a[i - 1];
		a[i] %= 3;
	}
	rep(i, t.size()) {
		if (t[i] == 'A')b[i] = 1;
		else b[i] = 2;
		if (i)b[i] += b[i - 1];
		b[i] %= 3;
	}
	cin >> q;
	rep(i, q) {
		cin >> l1 >> r1 >> l2 >> r2;
		l1--; r1--; l2--; r2--;
		int sh, th;
		if (l1)sh = (a[r1] - a[l1 - 1] + 3) % 3;
		else sh = a[r1];
		if (l2)th = (b[r2] - b[l2 - 1] + 3) % 3;
		else th = b[r2];
		if (sh == th)puts("YES");
		else puts("NO");
	}
}