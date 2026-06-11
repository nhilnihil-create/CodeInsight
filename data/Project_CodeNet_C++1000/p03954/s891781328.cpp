#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;
typedef long long ll;

const int N = 200 * 1000 + 10;

ll a[N], n, b[N];

bool ok(int k)	{
	for (int i = 1; i < n + n; i++)
	{
		b[i] = (a[i] >= k);
	}
	for (int i = 0; i < n; i++)
	{
		if(b[n + i] == b[n + i + 1])
			return b[n + i];
		if(b[n - i] == b[n - i - 1])
			return b[n - i];
	}
	return b[1];
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= 2 * n - 1; i++)
		cin >> a[i];
	ll low = 0, high = 2 * n - 1;
	while(high - low > 1)
	{
		ll mid = (low + high) >> 1;
		if(ok(mid))
			low = mid;
		else
			high = mid;
	}
	cout << low << "\n";
}