#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
//#define int ll
#define F first
#define S second

const int MOD = 1e9 + 7;
void add(int &a, int b) {
	a += b;
	if (a >= MOD) {
		a -= MOD;
	}
}

int mult(int a, int b) {
	return (a * 1ll * b) % MOD;
}

int sub(int a, int b) {
	return (a - b + MOD) % MOD;
}

const int N = 5010;
int calc[N][N], calc2[N][N], pw[N];

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
	int n;
	cin >> n;
	pw[0] = 1;
	for (int i = 1; i <= n; i++) {
		pw[i] = mult(pw[i - 1], 2);
	}
	string s;
	cin >> s;
	calc[0][0] = 1;
	calc2[0][0] = 1;	
	for (int i = 0; i < n; i++) {
		for (int balance = 0; balance <= i; balance++) {
			add(calc[i + 1][balance + 1], calc[i][balance]);
			if (balance > 1) {
				add(calc[i + 1][balance - 1], calc[i][balance]);
			}

			add(calc2[i + 1][balance + 1], mult(calc2[i][balance], 2));
			add(calc2[i + 1][max(0, balance - 1)], calc2[i][balance]);
		}
	}
	//cout << calc2[2][0] << '\n';
	int ans = 0;
	for (int pref = 0; pref <= n; pref++) {
		if (n - pref >= SZ(s) && (n - pref) % 2 == SZ(s) % 2) {
			int cur = mult(calc[n - pref][SZ(s)], pw[(n - pref - SZ(s)) / 2]);
			//cout << pref << ' ' << cur << '\n';
			add(ans, mult(cur, calc2[pref][0]));
		}
	}
	cout << ans << '\n';
}