#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, k = 1, a, ans;
signed main() {
	cin >> n;
	while (n--) {
		cin >> a;
		if (k == a)k++;
		else ans += (a - 1) / k;
		if (k == 1)k++;
	}
	cout << ans << endl;
}