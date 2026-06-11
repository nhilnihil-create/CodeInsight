#define alphanso                  \
	ios_base::sync_with_stdio(0); \
	cin.tie(NULL)
#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
int main()
{
	alphanso;
	ull n, i, j, ans = 0;
	cin >> n;
	int arr[3 * n];
	for (i = 0; i < 3 * n; i++)
		cin >> arr[i];
	sort(arr, arr + 3 * n, greater<int>());
	for (i = 1, j = 1; j <= n; i += 2, j++)
		ans += arr[i];
	cout << ans;
	return 0;
}
