#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define inf 1e9
#define pb push_back
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

ll a,b,c,d,e,f,g,ans;

inline ll X(ll w,ll x,ll y,ll z)
{
	ll tmp=x;
	tmp+=(w/2)*2; tmp+=(y/2)*2; tmp+=(z/2)*2;
	return tmp;
}

int main()
{
	cin>>a>>b>>c>>d>>e>>f>>g;
	ans=X(a,b,d,e);
	if(a&&d&&e) ans=max(ans,X(a-1,b,d-1,e-1)+3); cout<<ans<<endl;
	return 0;
}