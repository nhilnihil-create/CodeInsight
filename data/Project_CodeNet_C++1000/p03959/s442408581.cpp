#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cmath>
#include<map>
#include<iomanip>
#include<queue>
#include<stack>
#include<time.h>
#define rep(i,n)for(ll i=0;i<n;i++)
#define ll long long
#define double long double
#define pi 3.141592653589
using namespace std;
ll n, ans = 1; ll a[114514], b[114514];
signed main() {
	cin >> n;
	rep(i, n)cin >> a[i];
	rep(i, n)cin >> b[i];
	if (n == 1 && a[0] != b[0]) {
		puts("0");
		return 0;
	}
	for (int i = 1; i < n - 1; i++) {
		if (a[i] != a[i - 1] && b[i] != b[i + 1] && a[i] != b[i]) {
			puts("0");
			return 0;
		}
		if (a[i] == a[i - 1] && b[i] != b[i + 1] && b[i] > a[i]) {
			puts("0");
			return 0;
		}
		if (a[i] != a[i - 1] && b[i] == b[i + 1] && b[i] < a[i]) {
			puts("0");
			return 0;
		}
		if (a[i - 1] == a[i] && b[i] == b[i + 1]) {
			ans *= min(a[i], b[i]);
			ans %= 1000000007;
		}
	}
	cout << ans << endl;
	getchar(); getchar(); return 0;
}