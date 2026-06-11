#include<bits/stdc++.h>
#define MAX 3000
#define MOD 1000000007
using namespace std;
vector<int> v,a;
bool check()
{
	sort(a.begin(),a.end());
	sort(v.begin(),v.end());
	for(int i=0;i<a.size();++i)
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
		a.push_back(x);
		v.push_back(abs(n-i-1-i));
	}
	if(!check())
		cout<<"0"<<endl;
	else
	{
		n >>= 1;
		long long ans = 1;
		for(int i=1;i<=n;++i)
			ans *= 2LL, ans %= MOD;
		cout<<ans<<endl;
	}
	return 0;
}