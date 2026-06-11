#include <bits/stdc++.h>
#define LL long long
#define LD long double
#define pb push_back
#define mp make_pair
#define ss(x) (int) x.size()
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
#define all(x) x.begin(), x.end()

using namespace std;

int n;
pair <int, int> a[100005];

int main() {		
	scanf ("%d", &n);
	rep(i, 1, n) {
		scanf ("%d", &a[i].fi);
		a[i].se = i;
	}
	sort(a + 1, a + n + 1);
	int ans = 0;
	rep(i, 1, n) if (i % 2 != a[i].se % 2) ans++;
	printf ("%d\n", ans / 2);
	return 0;
}
