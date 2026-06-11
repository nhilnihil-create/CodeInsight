#include <bits/stdc++.h>
#define LL long long
#define LD long double
#define pb push_back
#define mp make_pair
#define ss(x) (int) x.size()
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl
#define rep2(i, j, n) for (LL i = j; i <= n; ++i)
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
#define boost cin.tie(0);ios_base::sync_with_stdio(0);
#define all(x) x.begin(), x.end()

using namespace std;

int n;

int main() {		
	scanf ("%d", &n);
	vector <int> v(2 * n);
	for (int &x : v) scanf ("%d", &x);
	sort(all(v));
	reverse(all(v));
	int ans = 0;
	rep(i, 0, 2 * n - 1)	
		if (i & 1) ans += v[i];
	printf ("%d ", ans);
	
	return 0;
}
