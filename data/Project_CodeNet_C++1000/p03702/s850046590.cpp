#include <bits/stdc++.h>
using namespace std;

const int N = 100 * 1000 + 10;
long long h[N], n, a, b;

bool is_val(long long t)
{
	long long cnt = 0;
	for (int i = 0; i < n; i++)
	{
		long long x = h[i];
		x -= t * b;
		if(x <= 0)
			continue;
		cnt += (x / (a - b)) + min(1ll, x % (a - b));
	}
	return cnt <= t;
}

long long bin_search()
{
	long long low = 0, high = 1000 * 10000 * 1000 + 5;
	while(high - low > 1)
	{
		long long mid = (low + high) / 2;
		if(is_val(mid))
			high = mid;
		else
			low = mid;
	}
	return high;
}

int main()
{
	cin >> n >> a >> b;
	for (int i = 0; i < n; i++)
		cin >> h[i];
	cout << bin_search() << endl;
}