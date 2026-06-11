#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
ll inf = 1000000007;
ll a[100005];
int main() {
	int n, k;
	cin >> n >> k;
	if (n == 1) {
		cout << k << endl;
		return 0;
	}
	ll ans = k;
	int i = 1;
	while (i != n ) {
		i++;
		ans *= (k - 1);
		
	}
	cout << ans << endl;
	return 0;
}
