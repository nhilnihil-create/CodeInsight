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

#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define REPO(i, n) for(int i = 1;i <= n;i++)
#define ll long long
#define INF 1999999999
#define MINF -1999999999
#define INF64 1999999999999999999
#define ALL(n) n.begin(),n.end()
#define MOD 1000000007


ll n, s[114514],ans = 0, cnt = 0;
int main() {
	cin >> n;
	REPO(i, n)cin >> s[i];
	REPO(i, n + 1) {
		if (i == s[i])cnt++;
		else if (cnt > 0) {
			ans += max(1ll, (cnt + 1) / 2);
			cnt = 0;
		}
	}
	cout << ans << endl;
}
