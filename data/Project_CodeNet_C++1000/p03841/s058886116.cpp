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
#define ull unsigned long long

using namespace std;

const int N = 505 * 505;

int n;
int x[N];
vector <int> v;
int L[N], R[N];
int a[N];

int main() {
	scanf ("%d", &n);
	rep(i, 1, n) {
		scanf ("%d", x + i);
		a[x[i]] = i;
		L[i] = i - 1;
		R[i] = n - i;
	}
	rep(i, 1, n * n) {
		if (a[i]) {
			v.pb(a[i]);
			if (L[a[i]] != 0) return printf ("No\n"), 0;
			continue;
		}
		// 1. L
		int best = -1;
		rep(j, 1, n)
			if (i < x[j] && (best == -1 || x[j] < x[best]) && L[j] > 0)
				best = j;
		if (best != -1) {
			v.pb(best);
			L[best]--;
			continue;
		}
		// 2. R
		rep(j, 1, n)
			if (x[j] < i && R[j]) {
				v.pb(j);
				R[j]--;
				break;
			}
		if (ss(v) != i) return printf ("No\n"), 0;
	}
	printf ("Yes\n");
	for (auto it : v)
		printf ("%d ", it);
	

    return 0;
}
