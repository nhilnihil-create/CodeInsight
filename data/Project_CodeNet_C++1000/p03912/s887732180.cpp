#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <map>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define brep(i, n) for (int i = (int)n - 1; i >= 0; i--)
#define orep(i, n) for (int i =  1; i <= (int)n; i++)
#define vec vector
#define pb push_back
#define mp make_pair
#define pii pair<int, int>

int main(void)
{
	int n, m;
	cin >> n >> m;
	vec<int> x(n);
	rep(i, n) cin >> x[i];
	sort(x.begin(), x.end());
	vec<int> y(m, 0);
	vec<int> same(m, 0);
	int prev = - 1;
	rep(i, n) {
		y[x[i] % m]++;
		if (i && x[i] == x[i - 1]) {
			if (prev != x[i]) {
				prev = x[i];
				same[x[i] % m]++;
			} else prev = - 1;
		} 
	}
	int ans;
	ans = y[0] / 2;
	if (m % 2 == 0) ans += y[m / 2] / 2;
	for (int i = 1; i <= (m - 1) / 2; i++) {
		int a = i;
		int b = m - i;
		if (y[a] <= y[b]) {
			ans += y[a];
			ans += min((y[b] - y[a]) / 2, same[b]);
		} else {
			ans += y[b];
			ans += min((y[a] - y[b]) / 2, same[a]);
		}
	}
	cout << ans << endl;
	return 0;
}
