#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <map>
#include <queue>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using p = pair<int, int>;
int main()
{
	int k, t, tmp;
	cin >> k >> t;
	vector<int> a(t);
	int old = -1, next = 0;
	int m = 0;
	rep(i, t) cin >> a[i];
	sort(a.rbegin(), a.rend());
	int ans = 0;
	rep(i, k) {
		if (old == next)	ans++;
		a[next]--;
		old = next;
		m = 0;
		rep(j, t) {
			if (old == j)	continue;
			if (a[j] != 0) {
				if (m < a[j]) {
					next = j;
					m = a[j];
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}