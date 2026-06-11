#include <bits/stdc++.h>

using namespace std;

#define ldouble long double
#define llong long long int
#define print(x) cout << x << endl
#define ternary(condition, x, y) ((condition) ? x : y) 
#define rep(i, n) for (int i = 0; i < n; ++i)
#define all(STL) STL.begin(), STL.end()
#define stl_rep(itr, STL) for (auto itr = STL.begin(); itr != STL.end(); ++itr)

const static long long int MOD = 1000000000 + 7;
const static int dy[] = {0, 1, 0, -1};
const static int dx[] = {1, 0, -1, 0};

int main (int argc, char *argv[]) {
    cin.tie(0); 
    ios::sync_with_stdio(false);

    llong n;
	cin >> n;
	vector<llong> a(n), t(n);
	for (int i = 0; i < n; i++) cin >> t[i];
	for (int i = 0; i < n; i++) cin >> a[i];

	if (a[0] != t[n-1]){
		cout << 0 << endl;
        return 0;
	} else {
		llong ans = 1;
		for (int i = 1; i < n-1; i++) {
			if (t[i] == t[i - 1] && a[i] == a[i + 1]){
				ans *= min(t[i], a[i]);
                ans %= MOD;
			} else if (t[i] > t[i - 1] && a[i] == a[i + 1] && a[i] < t[i]){
				cout << 0 << endl;
                return 0;
			} else if (t[i] == t[i - 1] && a[i] > a[i + 1] && a[i] > t[i]){
				cout << 0 << endl;
                return 0;
			} else if (t[i] > t[i - 1] && a[i] > a[i + 1] && a[i] != t[i]){
				cout << 0 << endl;
                return 0;
			}
		}
		cout << ans << endl;
	}

	return 0;
}
