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
int n, a[N], cnt[N];

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL);
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
	#endif
	
	cin >> n;
	int mn = N, mx = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		cnt[a[i]]++;
		mn = min(mn, a[i]);
		mx = max(mx, a[i]);
	}
	if (mx - mn > 1) {
		cout << "No";
		return 0;
	}
	if (mn == mx) {
		int x = mn;
		if (x == n - 1 || x <= n / 2) {
			cout << "Yes";
		}	else {
			cout << "No";
		}
		return 0;
	}
	if (cnt[mn] + 1 <= mx && cnt[mn] + cnt[mx] / 2 >= mx) {
		cout << "Yes";
	}	else {
		cout << "No";
	}
}
