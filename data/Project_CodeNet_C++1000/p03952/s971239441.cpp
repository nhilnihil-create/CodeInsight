#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define ss(x) (int) x.size()
#define sz(x) (int) x.size()
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
#define all(x) x.begin(), x.end()

using namespace std;

int n, x;
int used[300005];
int ans[300005];

void put(int pos, int x) {
	used[x] = 1;
	ans[pos] = x;
}

int main() {
	scanf ("%d%d", &n, &x);
	if (x == 1 || x == 2 * n - 1) return printf ("No\n"), 0;
	printf ("Yes\n");
	if (n == 2) 
		return printf ("1 2 3\n"), 0;
	if (x < 2 * n - 2) {
		put(n, 1);
		put(n + 1, x);
		put(n + 2, x + 1);
		put(n - 1, x + 2);
	}
	else {
		put(n, 2 * n - 1);
		put(n + 1, x);
		put(n + 2, x - 1);
		put(n - 1, x - 2);
	}
	int j = 1;
	rep(i, 1, 2 * n - 1) {
		if (ans[i]) {
			printf ("%d\n", ans[i]);
		}
		else {
			while (used[j]) j++;
			printf ("%d\n", j);
			j++;
		}
	}
		
		
	
		
	
    return 0;
}

