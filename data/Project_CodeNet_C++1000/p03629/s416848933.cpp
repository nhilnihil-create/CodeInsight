#include <iostream>
#include <cstdio>
using namespace std;
 
int n, mn, x, v[30], d[200005], ju[200005], u[200005];
string a, ans;
int main()
{
	int i, j, t;
	cin >> a;
	n = a.size();
	a = '.' + a;
	for (i = 0; i < 26; i++) v[i] = n + 1;
	for (i = n; i >= 0; i--) {
		mn = 2e9;
		for (j = 0; j < 26; j++) {
//			if (a[i] - 'a' == j) t = d[v[j]] + 1;
			t = d[v[j]];
			if (t < mn) {
				mn = t;
				x = j;
			}
		}
		ju[i] = v[x];
		d[i] = mn + 1;
		if (i > 0) v[a[i] - 'a'] = i;
		u[i] = x;
	}
	i = 0;
	do {
		ans += (char)(u[i] + 'a');
		i = ju[i];
	} while (i <= n);
	cout << ans;
    return 0;
}