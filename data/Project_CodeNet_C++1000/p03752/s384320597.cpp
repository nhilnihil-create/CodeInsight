#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = n; i >= 0; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 30;
 
int main() {
	int n, k;
	cin >> n >> k;
	int h[20];
	rep(i,n) cin >> h[i];

	ll ans = 1e12;
	rep(s, 1<<n) {
		ll sum = 0, now = 0;
		int can_see = 0;

		rep(i,n) {
			if (now < h[i]) {now = h[i]; can_see++;} 		
			else if (s>>i&1) {
				sum += now - h[i] + 1;
				now++;
				can_see++;
			}
		}
		if (can_see>= k) ans = min(ans, sum);
	} 
	cout << ans << endl;
	return 0;
}