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

const int N = 1e5 + 10101;

int n;
int a[N];

int main() {		
	scanf ("%d", &n);
	rep(i, 1, n) scanf ("%d", a + i);
	sort(a + 1, a + n + 1);
	reverse(a + 1, a + n + 1);
	int x = 0;
	int y = 0;
	while (true) {
		if (x + 2 > n || a[x + 2] <= y + 1) break;
		x++;
		y++;
	}
	int q = a[x + 1] - y;
	int w = 0;
	while (x + 1 <= n && y < a[x + 1]) {
		w++;
		x++;
	}
	if (q % 2 == 0 || w % 2 == 0) printf ("First\n");
	else printf ("Second\n");
	
	return 0;
}
