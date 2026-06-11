#include <bits/stdc++.h>
using namespace std;

const long long MAXN = 2000 + 10, inf = 1e18;

long long n, x;
long long ans;
long long shift;
long long a[MAXN], b[MAXN];

int main() {
	cin >> n >> x;
	for (int i = 0; i < n; i++) {
	   	cin >> a[i];
		b[i] = a[i];
	}
 
	ans = inf;

	for(int k = 0; k < n; k++) {
		shift = k * x;
		
		for (int i = 0; i < n; i++) {
			b[i] = min(b[i], a[(i + n - k) % n]);
			shift += b[i];
		}

		ans = min(ans, shift);
	}
	cout << ans << '\n';
	return 0;
}
