#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	long long int A[300001];
	for (int i = 0; i < n * 3; ++i)
	{
		cin >> A[i];
	}
	sort(A, A + 3 * n);
	long long int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		ans += A[n + 2 * i];
	}
	cout << ans << endl;
	return 0;
}