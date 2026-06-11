
/* 

И пусть меня погубит, то к чему я
Бегу, не жалея ног.
И если мне суждено сгореть на восходе,
Я буду идти вперёд.

*/

#include <bits/stdc++.h>

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

#define ll long long
#define pb push_back
#define mp make_pair
#define sz(x) (int)(x).size()
#define S second
#define F first
#define all(x) (x).begin(), (x).end()

using namespace std;

const bool dbg_flg = 0;
#define debug(x) if (dbg_flg) cerr << #x << ' ' << x << '\n'
#define debug_pair(x) if (dbg_flg) cerr << #x << ' ' << x.F << ' ' << x.S << '\n' 

const int inf = 1e9 + 7;
const int MAXN = 2e5 + 5;

int n;
int x;
int a[MAXN];

void solve() {
	cin >> n >> x;	

	if (x == 1 || x == 2 * n - 1) {
		cout << "No";

		return;
	}

	memset(a, -1, sizeof(a));

	a[n - 1] = x - 1;
	a[n] = x;
	a[n + 1] = x + 1;

	int cur = 1;

	for (int i = 1; i <= 2 * n - 1; i++) {
		if (a[i] == -1) {
	    	while (abs(cur - x) <= 1) cur++;
			a[i] = cur++;
		}		
	}

	cout << "Yes\n";

	for (int i = 1; i <= 2 * n - 1; i++) {
		cout << a[i] << '\n';
	}
}

int main() {
	
	//~ freopen(".in", "r", stdin);
	//~ freopen(".out", "w", stdout);
	
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	int tt = 1;
	// cin >> tt;
	while (tt--) {
		solve();
	}

	return 0;
}