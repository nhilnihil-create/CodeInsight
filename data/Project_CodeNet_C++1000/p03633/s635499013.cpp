#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	int n;
	cin >> n;
	vector<ll> t(n);
	for(int i = 0;i<n;i++)cin >> t[i];

	ll ans  = 1;
	for(int i = 0;i<n;i++)
	{
		ans =ans/ __gcd(t[i],ans)*t[i];
	}
	cout << ans << endl;
}
