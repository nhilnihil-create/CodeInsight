/* it was worth becoming a chemist */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double db;
typedef long double ld;
typedef unsigned int uni;
typedef unsigned long long unll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef pair<long long, int> pli;
typedef pair<int, long long> pil;
typedef vector<int> vi;
typedef vector<long long> vll;

#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)x.size()
#define NAME "puts"
#define F first
#define S second

const ll INF = 1e18;
const int inf = 1e9;
const int mod = 1e9 + 7;
const db EPS = (db) 1e-9;
const db pi = acos(-1.0);
const int MAXN = 1e5 + 5;

int n;
ll a[4005], x, mn[4005][4005];
ll res = INF;

int main() {
	
	cin >> n >> x;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = n + 1; i <= 2 * n; i++) {
		a[i] = a[i - n];
	}
	for (int i = 1; i <= 2 * n; i++) {
		for (int j = i; j <= 2 * n; j++) {
			mn[i][j] = INF;
			if (i == j) mn[i][j] = a[i];
		}	
	}
	for (int i = 1; i <= 2 * n; i++) {
		for (int j = i + 1; j <= 2 * n; j++) {
			mn[i][j] = min(mn[i][j - 1], a[j]);
		}
	}
	for (int i = 0; i <= n; i++) {
		ll val = i * x;
		for (int j = 1; j <= n; j++) {
			val += mn[j][j + i];
		}
		res = min(val, res);
	}
	cout << res;
    return 0;
}
