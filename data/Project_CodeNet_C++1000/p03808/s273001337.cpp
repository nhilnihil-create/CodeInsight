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
ll n, a[N], d[N];

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL);
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
	#endif
	
	cin >> n;
	ll s = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		s += a[i];
	}
	if (n == 1) {
		cout << "YES";
		return 0;
	}
	ll step = n * (n + 1) / 2;
	if (s % step) {
		cout << "NO";
		return 0;
	}
	s /= step;
	for (int i = 1; i <= n; i++) {
		a[i] -= s * i;
	}
	for (int i = 1; i <= n; i++) {
		d[i] = a[i] - a[i - 1];
	}
	for (int i = 2; i <= n; i++) {
		if (d[i] > 0 || (-d[i]) % n) {
			cout << "NO";
			return 0;
		}
		ll num = (-d[i]) / n;
		d[1] -= num * (n - (i - 1));
	}
	if (d[1] == 0) {
		cout << "YES";
	}	else {
		cout << "NO";
	}
}
