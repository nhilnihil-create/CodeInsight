#include <iostream>
#include <string>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <queue>
#include <stack>
#include <iomanip>


using namespace std;

#define REP(i, n) for(ll i = 0;i < n;i++)
#define REPR(i, n) for(ll i = n;i >= 0;i--)
#define FOR(i, m, n) for(ll i = m;i < n;i++)
#define FORR(i, m, n) for(ll i = m;i >= n;i--)
#define REPO(i, n) for(ll i = 1;i <= n;i++)
#define ll long long
#define INF 1999999999
#define MINF -1999999999
#define INF64 1999999999999999999
#define ALL(n) n.begin(),n.end()
#define MOD 1000000007

ll n, m, x[110000], y[110000], a1 = 0, a2 = 0;
int main() {
	cin >> n >> m;
	REP(i, n)cin >> x[i];
	REP(i, m)cin >> y[i];
	REP(i, n - 1) {
		a1 += abs(x[i] - x[i + 1]) * ((n - i - 1) * (i + 1) % MOD) % MOD;
		a1 %= MOD;
	}
	REP(i, m - 1) {
		a2 += abs(y[i] - y[i + 1]) * ((m - i - 1) * (i + 1) % MOD) % MOD;
		a2 %= MOD;
	}
	cout << a1 * a2 % MOD << endl;
}
