#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 30;

int a[100010]; 

int main() {
	int n;
	cin >> n;
	rep(i,n) cin >> a[i];
	sort(a,a+n);
	int ans = 1;
	ll sum = 0;
	rep(i,n-1) {
		sum += a[i];
		if (sum *2 >= a[i+1]) ans++;
		else ans = 1;
	}
	cout << ans << endl;
	return 0;
}