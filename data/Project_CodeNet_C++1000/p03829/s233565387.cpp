#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int MAX = 1e5;

int main()
{
	ll n, a, b, arr[MAX], ans = 0;
	cin >> n >> a >> b;
	
	for (int i=0; i<n; ++i) {
		cin >> arr[i];
	}
	
	for (int i=0; i<n-1; ++i) {
		ans += min ((arr[i+1] - arr[i]) * a, b);
	}
	
	cout << ans;
	
	return 0;
}
