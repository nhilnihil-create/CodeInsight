#include <iostream>
#include <string>
#include <utility>
#include <algorithm>
#include <map>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <queue>
#include <numeric>
#include <set>

using namespace std;

#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define REPO(i, n) for(int i = 1;i <= n;i++)
#define ll long long
#define INF 999999999
#define MINF -999999999
#define ALL(n) n.begin(),n.end()
ll s[110000], ma,sama;

int main() {
	set<int> a;
	ll m,n,ans = 0;
	cin >> n >> m;
	m /= 2;
	REP(i, n) {
		cin >> s[i];
	}
	REPR(i, n - 1) {
		ma = max(ma, s[i]);
		sama = max(sama, ma - s[i]);
	}
	REP(i, n) {
		a.insert(s[i]);
		if (a.find(s[i] - sama) != a.end()) ans++;
	}
	cout << ans << endl;
}

