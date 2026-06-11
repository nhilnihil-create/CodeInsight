#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	long long int n,a,b;

	cin >> n >> a >> b;
	long long int hi = (n-1)*b + a;
	long long int lo = (n-1)*a + b;
	
	cout << max(0LL,hi-lo+1) << '\n';

	return 0;
}