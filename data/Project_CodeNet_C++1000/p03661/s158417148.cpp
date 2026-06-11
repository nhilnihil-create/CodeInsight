#include <iostream>
#include <string>
#include <utility>
#include <algorithm>
#include <map>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <queue>
#include <stack>

using namespace std;

#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = n;i >= m;i--)
#define REPO(i, n) for(int i = 1;i <= n;i++)
#define ll long long
#define INF 1999999999
#define MINF -1999999999
#define INF64 5999999999999999999
#define ALL(n) n.begin(),n.end()
#define ABS(a,b) max(a,b) - min(a,b)

ll n, s[300000], ans = INF64;

int main() {
	cin >> n;
	REP(i, n) {
		ll a;
		cin >> a;
		s[i + 1] = s[i] + a;
	}
	FOR(i, 1, n) {
		ans = min(ans, ABS(s[n] - s[i], s[i]));
	}
	cout << ans << endl;
}