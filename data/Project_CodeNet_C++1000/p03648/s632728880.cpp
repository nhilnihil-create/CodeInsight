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

ll n, ans[50];
int main() {
	cin >> n;
	REP(i, 50)ans[i] = 49 - i;
	REP(i, 50)ans[i] += n / 50;
	n %= 50;
	REP(i, n)ans[i]++;
	cout << 50 << endl;
	REP(i, 50) {
		if (i != 0)cout << " ";
		cout << ans[i];
	}
	cout << endl;
}
