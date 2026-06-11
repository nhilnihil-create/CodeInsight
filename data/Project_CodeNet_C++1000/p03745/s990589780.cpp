#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define mp make_pair
#define ff first
#define ss second
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define all(v) v.begin(),v.end()

const int maxn = 1e5 + 100;
const ll inf = 2e18, mod = 1e9 + 7;

int n, a[maxn];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int lastVal = a[0], ans = 1;
	char state = 'n';
	for (int i = 1; i < n; i++) {
		if (state == 'n') {
			if (a[i] > lastVal) {
				state = 'i';
			}
			else if (a[i] < lastVal) {
				state = 'd';
			}
		}
		else if (state == 'i') {
			if (a[i] < lastVal) {
				state = 'n';
				ans++;
			}
		}
		else {
			if (a[i] > lastVal) {
				state = 'n';
				ans++;
			}
		}
		lastVal = a[i];
	}
	cout << ans << endl;
}

