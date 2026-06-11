#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long n, t; cin >> n >> t;

	vector<long long> c(n); 
	
	for (long long i = 0; i < n; i++) cin >> c[i];
	
	long long ans = t;
	for (long long i = 0; i < n - 1; i++) {
		ans += min(c[i + 1] - c[i], t);
	}
	
	cout << ans << endl;
	
	return 0;
}