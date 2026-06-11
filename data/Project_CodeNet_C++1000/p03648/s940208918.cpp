#include <bits/stdc++.h>
 
using namespace std;
 
#define debug(a) cerr << #a << ": " << a << endl
 
typedef long long ll;
typedef pair<int, int> ii;
 
#define x first
#define y second
 
const int N = 1e5 + 10;

ll k;
const int n = 50;
ll a[n + 1];

void simulate(ll a[], int n, int times) {
	while (times--) {
		int maxi = max_element(a + 1, a + n + 1) - a;
		for (int i = 1; i <= n; i++) {
			if (i == maxi) a[i] -= n;
			else a[i]++;
		}
	}
}

int main() {
	#ifdef LOCAL
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
	#endif
 
	cin >> k;

	ll init = (n - 1) + (k + n - 1) / n;
	fill(a + 1, a + n + 1, init);

	ll need = (init - (n - 1)) * n;
	simulate(a, n, need - k);

	cout << n << endl;
	for (int i = 1; i <= n; i++)
		cout << a[i] << " ";
 
	return 0;
}