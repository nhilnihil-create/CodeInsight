#include <iostream>
#include <algorithm>
using namespace std;
const int N = 200005;
long long a[N];
int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		a[i] += a[i - 1];
	}
	long long ans = 1e18;
	for (int i = 1; i < n; i++)
		ans = min(ans, abs(a[i] - (a[n] - a[i])));
	cout << ans << endl;
	return 0;
}