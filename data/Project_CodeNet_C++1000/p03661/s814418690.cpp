#include<bits/stdc++.h>
#define ll long long
#define For(i,a,b) for (int i=a;i<=b;i++)
#define Rep(i,a,b) for (int i=b;i>=a;i--)
using namespace std;
inline ll read()
{
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
    return x*f;
}
ll a[200200];
int main()
{
	ll n=read();
	For(i,1,n)
	{
		a[i]=read();
		a[i]+=a[i-1];
	}
	ll ans=1e18;
	For(i,1,n-1)ans=min(ans,abs(a[i]-a[n]+a[i]));
	cout<<ans<<endl;
	return 0;
}
