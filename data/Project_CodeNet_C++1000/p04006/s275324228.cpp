#include <bits/stdc++.h>
using namespace std;

const int N = 2000 + 7;

long long n, x;
long long a[N];
long long mn[N], p[N], res;

int main() {
	cin >> n >> x;
	for (long long i = 1; i <= n; i++)
		cin >> a[i], res += a[i], p[i] = i, mn[i] = a[i];
	for (long long k = 1; k <= n; k++) {
		long long nres = 0;
		for (long long i = 1; i <= n; i++) {
			p[i]--;
			if (p[i] == 0)
				p[i] = n;
			mn[i] = min(mn[i], a[p[i]]); 
			nres += mn[i];	
		}
		res = min(res, nres + k * x);
	//	cout << k << " " << nres + k * x << " " << res << endl;
	}
	cout << res;
	return 0;
}
 












