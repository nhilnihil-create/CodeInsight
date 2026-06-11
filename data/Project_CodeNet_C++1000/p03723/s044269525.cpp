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

int main() {
	int a, b, c;
	scanf ("%d%d%d", &a, &b, &c);
	int ans = 0;
	while (!(a & 1) & !(b & 1) & !(c & 1)) {
		if (a == c) {
			printf ("-1\n");
			return 0;
		}
		int x = (a + b) / 2;
		int y = (b + c) / 2;
		int z = (a + c) / 2;
		ans++;
		a = x, b = y, c =z;
	}
	printf ("%d\n", ans);
	return 0;
}
