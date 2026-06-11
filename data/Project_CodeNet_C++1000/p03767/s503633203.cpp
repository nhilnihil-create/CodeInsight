#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	int n; cin >> n;
	int a[3*n];
	for (int i = 0; i < 3*n; ++i)
		cin >> a[i];
	sort(a, a+3*n);
	ll ans = 0;
	for (int i = 3*n-2; i > n-1; i -= 2) ans += a[i];
	cout << ans << endl;
}

