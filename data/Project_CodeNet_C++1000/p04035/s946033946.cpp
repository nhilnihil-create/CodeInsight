#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb emplace_back
const int maxn = 2e5;
int n;
ll lim, a[maxn];
signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n >> lim;
	for (int i = 1;i <= n;++i)
		cin >> a[i];
	for (int i = 1;i < n;++i) if (a[i] + a[i+1] >= lim) {
		cout << "Possible\n";
		for (int j = 1;j < i;++j)
			cout << j << '\n';
		for (int j = n-1;j > i;--j)
			cout << j << '\n';
		cout << i << '\n';
		return 0;
	}
	cout << "Impossible\n";
}

