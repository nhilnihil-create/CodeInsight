#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int INF = 1 << 29;
const long long int Mod = 1000000007;
using ll = long long int;
#define all(x) (x).begin(),(x).end()
#define rep(i,N) for(ll i = 0; i < (ll)N; ++i)
#define repi(i,a,b) for(ll i = ll(a); i < ll(b); ++i)

ll a[100010];

int main() {
	int n;
	cin >> n;
	

	rep(i, n) cin >> a[i];

	int change = 0;
	int ans = 0;
	rep(i, n - 1) {
		if (change == 0) {
			if (a[i] < a[i + 1]) change = 1;
			else if (a[i] > a[i + 1]) change = -1;
		}
		else if (change == 1) {
			if (a[i] > a[i + 1]) {
				++ans;
				change = 0;
			}
		}
		else {
			if (a[i] < a[i + 1]) {
				++ans;
				change = 0;
			}
		}
	}
	if (change == 0) ++ans;
	else if (change == 1) {
		if (a[n - 2] <= a[n - 1]) {
			++ans;
		}
		else {
			ans += 2;
		}
	}
	else {
		if (a[n - 2] >= a[n - 1]) ++ans;
		else ans += 2;
	}

	cout << ans << endl;
}