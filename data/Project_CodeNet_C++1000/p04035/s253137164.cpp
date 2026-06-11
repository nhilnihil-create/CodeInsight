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

const int N = 1e5 + 100;

int n, L;
int a[N];

int main() {		
	scanf ("%d%d", &n, &L);
	rep(i, 1, n) scanf ("%d", a + i);
	rep(i, 1, n - 1) {
		if (a[i] + a[i + 1] >= L) {
			printf ("Possible\n");
			vector <int> v;
			rep(j, 1, i - 1)
				v.pb(j);
			per(j, i + 1, n - 1)
				v.pb(j);
			v.pb(i);
			for (auto it : v) printf ("%d\n", it);
			return 0;
		}
	}
	printf ("Impossible\n");
	
	return 0;
}
