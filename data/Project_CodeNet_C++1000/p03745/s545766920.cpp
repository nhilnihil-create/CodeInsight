#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ull unsigned long long
#define db long double
#define pb push_back
#define ppb pop_back
#define F first
#define S second
#define mp make_pair
#define all(x) (x).begin(), (x).end()
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef vector <int> vi;
typedef vector <ll> vl;
 
const int N = 1e5 + 123;
int n, a[N], comp[N], dir[N], cnt;
 
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL);
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
	#endif
	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int cnt = 0;
	comp[1] = ++cnt;
	memset(& dir, -1, sizeof(dir));
	// -1 equal
	// 0 >=
	// 1 <=
	for (int i = 2; i <= n; i++) {
		if (dir[comp[i - 1]] == -1) {
			comp[i] = comp[i - 1];
			if (a[i] != a[i - 1]) {
				if (a[i - 1] < a[i]) {
					dir[comp[i]] = 1;
				}	else {
					dir[comp[i]] = 0;
				}
			}
		}	else {
			if (dir[comp[i - 1]] == 0) {
				if (a[i] > a[i - 1]) {
					comp[i] = ++cnt;
				}	else {
					comp[i] = comp[i - 1];
				}
			}	else {
				if (a[i] < a[i - 1]) {
					comp[i] = ++cnt;
				}	else {
					comp[i] = comp[i - 1];
				}
			}
		}
	}
	cout << cnt;
}
