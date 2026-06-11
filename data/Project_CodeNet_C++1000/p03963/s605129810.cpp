#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 30;
 
int main() {
	int n, k;
	cin >> n >> k;
	int ans = k;
	if (n==1) {
		cout << ans << endl;
		return 0;
	}
	rep(i, n-1) ans *= (k-1);
	cout << ans << endl;
	return 0;
}