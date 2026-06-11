#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,ans = 0;
	int a[202];
	cin >> n;
	for (int i = 1; i <= n * 2; i++) cin >> a[i];
	sort(a+1,a+n+n+1);
	for (int i = n * 2 - 1; i >= 1; i -= 2) ans += a[i];
	cout << ans << endl;
 } 