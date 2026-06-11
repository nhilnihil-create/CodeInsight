//### In The Name Of GOD ###

//%% Remember; (((He))) is The (((Accepter))) %%

// GOD IS GREATER ...

#include <bits/stdc++.h>

using namespace std;

typedef long long ll ;
typedef long double ld ;

//#define int ll
#define pb push_back
#define bp pop_back
#define pf push_front
#define fp pop_front
#define X first
#define Y second
#define IO ios_base::sync_with_stdio(false);
#define sz(a) (int)(a.size())
#define sg(a, b) (a + b - 1) /b

const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 1 * 1000 * 1000 * 1000 + 200;
const int MAXN = 100 * 1000 + 10;
const int MLOG = 30;
const int NMAX = 20;

signed main() {
	int n;
	cin >> n;
	int a[MAXN], ans = 0;
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++) {
		if(a[i] == i + 1) swap(a[i], a[i + 1]), ans++;
	}
	cout << ans;
}

