#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define ss(x) (int) x.size()
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
#define all(x) x.begin(), x.end()
#define ld long double

using namespace std;	

const int N = 1e5 + 101;

int n, m, a, b, d[N];

int main() {
	scanf ("%d%d", &n, &m);
	rep(i, 1, m) {
		scanf ("%d%d", &a, &b);
		d[a]++; d[b]++;
	}
	rep(i, 1, n)
		if (d[i] & 1) return printf ("NO\n"), 0;
	printf ("YES\n");
	
	return 0;
}
