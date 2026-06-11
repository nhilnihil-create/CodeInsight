#include <cmath>
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
#include<set>
#include<tuple>
#include<bitset>
#include<iomanip>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
ll inf = 1000000007;
ll t[1000005];
int main() {
	ll n, c, k;
	cin >> n >> c >> k;
	for (int i = 0; i < n; i++) {
		cin >> t[i];
	}
	sort(t,t+n);
	int ans = 0;
	for (int i = 0; i < n;) {
		++ans;
		int start = i;
		while (i < n && t[i] - t[start] <= k && i - start < c) {
			++i;
		}
	}
	cout << ans << endl;
	return 0;
}