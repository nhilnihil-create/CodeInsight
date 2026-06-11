#include <bits/stdc++.h>
using namespace std;
 
const int N = 100005;
const int M = 3;
const long long inf = 1e18+7;
 
#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
 
int n, a[N];
char c;
long long f[N][M+1];
 
int main() {
	ios::sync_with_stdio(false);
 
	cin >> n >> a[0];
	for (int i = 1; i < n; ++i) {
		cin >> c >> a[i];
		if (c == '-') a[i] *= -1;
	}
	REP(i, n+1) REP(a, M+1) {
		f[i][a] = -inf;
	}
	f[0][0] = 0;
	REP(i, n) REP(x, M) {
		if (f[i][x] == -inf) continue;
		long long val = f[i][x] + (x%2?-1:+1)*a[i];
		f[i+1][x] = max(f[i+1][x], val);
		if (a[i] < 0) f[i+1][min(x+1,M)] = max(f[i+1][min(x+1,M)], val);
		if (x > 0) f[i+1][max(x-1,0)] = max(f[i+1][max(x-1,0)], val);
	}
	long long result = -inf;
	REP(a, M) result = max(result, f[n][a]);
	cout << result << endl;
	return 0;
}