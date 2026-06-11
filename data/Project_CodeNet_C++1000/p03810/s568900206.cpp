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
int n, a[N];
 
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
		if (a[1] == 1) {
			cout << "Second";
		}	else {
			cout << "First";
		}
		return 0;
	}
	if ((s - n) & 1) {
		cout << "First";
	}	else {
		int x = 0;
		while (true) {
			int cnt = 0;
			for (int i = 1; i <= n; i++) {
				if (a[i] == 1) {
					break;
				}
				cnt += a[i] & 1;
			}
			if (cnt != 1) {
				break;
			}
			int g = 0;
			for (int i = 1; i <= n; i++) {
				if (a[i] & 1) {
					a[i]--;
				}
				g = __gcd(g, a[i]);
			}
			int d = 0;
			for (int i = 1; i <= n; i++) {
				d ^= (a[i] - a[i] / g) & 1;
				a[i] /= g;
			}
			if (d == 0) {
				break;
			}
			x++;
		}
		if (x & 1) {
			cout << "First";
		}	else {
			cout << "Second";
		}
	}
}
