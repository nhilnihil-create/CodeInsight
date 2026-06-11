#include <cmath>
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<iomanip>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
ll inf = 1000000007;
int a[200];
int main() {
	int n;
	cin >> n;
	ll ans = inf;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int j = -200; j <= 200; j++) {
		ll kai = 0;
		for (int i = 0; i < n; i++) {
			kai += pow((a[i] - j), 2);
		}
		ans = min(ans, kai);
	}
	cout << ans << endl;
	return 0;
}
