#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 25;
const int MOD = 1e9+7;
P a[100010];
int main() {
	int n;
	cin >> n;
	rep(i,n) cin >> a[i].first >> a[i].second;
	sort(a,a+n,greater<P>());
	int x = a[0].first, y = a[0].second;
	cout << x + y << endl;
	return 0;
}