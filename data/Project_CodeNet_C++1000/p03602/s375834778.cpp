#include <bits/stdc++.h>
#define rep(n) for (int i = 0; i < n; ++i)
#define REP(n,i) for (int i = 0; i < n; ++i)
#define mod 1000000007
#define sp ' '
#define intmax 2147483647
#define intinf 1000000000
#define llmax 9223372036854775807
#define nyan "(=^･ω･^=)"
#define mkp make_pair
#define mkt make_tuple
#define P pair<ll, ll>
#define iP pair<int,int>
typedef long long ll;
using namespace std;

#include <bits/stdc++.h>
#define rep(n) for (int i = 0; i < n; ++i)
#define REP(n,i) for (int i = 0; i < n; ++i)
#define mod 1000000007
#define sp ' '
#define intmax 2147483647
#define llmax 9223372036854775807
#define nyan "(=^･ω･^=)"
#define mkp make_pair
#define mkt make_tuple
#define P pair<ll, ll>
#define iP pair<int,int>
typedef long long ll;
using namespace std;

int n, a[300][300];
bool b;
ll ans = 0;

int main() {
	cin >> n;
	rep(n) {
		REP(n, j) {
			cin >> a[i][j];
		}
	}
	rep(n) {
		REP(n, j) {
			b = true;
			REP(n, k) {
				if (k != i&&k != j) {
					if (a[i][j] > a[i][k] + a[k][j]) {
						cout << -1 << endl;
						return 0;
					}
					if (a[i][j] == a[i][k] + a[k][j])
						b = false;
				}
			}
			if (b)
				ans += a[i][j];
		}
	}
	cout << ans / 2 << endl;
	return 0;
}
