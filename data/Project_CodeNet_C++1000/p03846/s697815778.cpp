#include<bits/stdc++.h>
#define MAX 100000
#define MOD 1000000007
using namespace std;
int v[MAX],a[MAX];
bool check(int n)
{
	for(int i=0;i<n;++i)
		if(a[i]^v[i])
			return false;
	return true;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	for(int i=0,x;i<n;++i)
	{
		cin>>x;
		a[x]++;
		++v[abs(n-1-(i<<1))];
	}
	long long ans = 0;
	if(check(n))
	{
		n >>= 1;
		ans = 1;
		for(int i=1;i<=n;++i)
			ans <<=1, ans %= MOD;
	}
	cout<<ans<<endl;
	return 0;
}