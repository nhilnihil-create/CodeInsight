#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
ll inf = 1000000007;
ll t[200005];
int main() {
	ll n, T;
	cin >> n >> T;
	for (int i = 0; i < n; i++) {
		cin >> t[i];
	}
	ll ans = 0;
	for (int i = 0; i < n - 1; i++) {
		if (t[i] + T <= t[i + 1]){
			ans += T;
		}
		else {
			ans += t[i + 1] - t[i];
		}
	}
	cout << ans + T << endl;
	return 0;
}