#include <bits/stdc++.h>
#define ll long long
#define ld long double
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
ll a, b, c, d;

int main() {
	scanf ("%d%lld%lld%lld%lld", &n, &a, &b, &c, &d);
	ll dif = d - c;
	rep(i, 0, n - 1) {
		ll A = a + -d * i + c * (n - i - 1);
		if (A <= b && b <= A + (n - 1) * dif) {
			printf ("YES\n");
			return 0;
		}
	}
	printf ("NO\n");
	return 0;
}	
