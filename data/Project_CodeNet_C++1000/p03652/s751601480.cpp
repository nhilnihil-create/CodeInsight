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
int n, m, a[310][310], b[310], c[310];
signed main() {
	cin >> n >> m;
	rep(i, n) {
		REP(j, m)cin >> a[i][j];
	}
	REP(i, m)b[i] = true;
	int ans = INF;
	rep(i,m) {
		REP(j, m)c[j] = 0;
		rep(j, n) {
			REP(k, m) {
				if (b[a[j][k]]) {
					c[a[j][k]]++;
					break;
				}
			}
		}
		int cnt = 0, tar = -1;
		REP(j, m) {
			if (cnt < c[j]) {
				cnt = c[j];
				tar = j;
			}
		}
		ans = min(ans, cnt);
		if (tar != -1)b[tar] = false;
	}
	cout << ans << endl;
	return 0;
}