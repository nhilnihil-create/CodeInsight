#include<iostream>
#define ll long long
using namespace std;
ll n,m,ans;
inline void dfs(ll x,ll y)
{
    if(x%y == 0)
	{
        ans+=x*2-y;
        return ;
    }
    else
	{
        ans+=(x-x%y)*2;
        dfs(y,x%y);
    }
}
main()
{
	cin>>n>>m;
	ans = n,n -= m;
	dfs(max(n,m),min(n,m));
	cout<<ans<<endl;
	return 0;
}