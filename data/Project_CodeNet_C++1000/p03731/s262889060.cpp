#include <bits/stdc++.h>
#include <vector>
#include <math.h>
using namespace std;

int main() {
	int n, t;
	cin >> n >> t;
	vector<int> lag(n-1);
	vector<int> time(n+1);
	for (int i = 0; i < n; ++i)
	{
		cin >> time[i];
	}
	for (int i = 0; i< n - 1; ++i)
	{
		lag[i] = time[i + 1] - time[i];
	}
	int ans = 0;
	for (int i = 0; i < n-1; ++i)
	{
		ans += min(t, lag[i]);
	}
	ans += t;
	cout << ans << endl;
}