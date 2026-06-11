#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	int n;
	cin >> n;
	vector<ll> a(n),b(n);
	for(int i = 0;i<n;i++)
	{
		cin >> a[i] >> b[i];
	}
	ll ans = 0;
	for(int i = n-1;i>=0;i--)
	{
		a[i]+=ans;
		ans += b[i]-a[i]%b[i]==b[i]?0:b[i]-a[i]%b[i];
	}
	cout<<ans<<endl;
	return 0;
}