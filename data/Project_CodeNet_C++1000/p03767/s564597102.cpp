#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 30;
 
int main() {
	int n;
	cin >> n;
	vector<int> a(3*n);
	rep(i, 3*n) cin >> a[i];
	sort(a.begin(), a.end(), greater<int>());
	ll ans = 0;
	int j = 1;
	rep(i, n)
	{
		ans += a[j];
		j += 2; 
	}
	cout << ans << endl;
	return 0;
}