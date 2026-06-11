#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(ll i = 0; i < n; ++i)
#define ALL(v) v.begin(), v.end()
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1000000005;

int main()
{
	ll n,l;
	cin >> n >> l;
	vector<ll> a(n);
	rep(i,n)cin >> a[i];
	ll ma = 0;

	rep(i,n-1)
	{
		if(a[i]+a[i+1]>a[ma]+a[ma+1])ma=i;
	}
	if(a[ma]+a[ma+1]<l)
	{
		cout<<"Impossible"<<endl;
		return 0;
	}
	cout<<"Possible"<<endl;
	rep(i,ma)
	{
		cout<<i+1<<endl;
	}
	for(ll i=n-2;i>ma;--i)
	{
		cout<<i+1<<endl;
	}
	cout<<ma+1<<endl;
	return 0;
}