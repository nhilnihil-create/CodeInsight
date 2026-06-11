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
 
int n;
string s;
 
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL);
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
	#endif
	
	cin >> s;
	n = s.size();
	for (int j = n; j >= 1; j--) {
		int can = n - j + 1;
		for (int i = 0; i < 26; i++) {
			int bad = 0;
			for (int k = 1; k <= j; k++) {
				int ok = 0;
				for (int l = k; l <= k + can - 1; l++) {
					if (s[l - 1] - 'a' == i) {
						ok = 1;
					}
				}
				if (!ok) {
					bad = 1;
					break;
				}
			}
			if (!bad) {
				cout << n - j;
				return 0;
			}
		}
	}
}
