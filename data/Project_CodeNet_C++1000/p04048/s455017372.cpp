#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define inf 1e9
#define eps 1e-10
using namespace std;

inline ll read()
{
	ll x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

int main()
{
	ll n=read(),x=read(),ans=0; ans+=n;
	ll p1=x,p2=n-x; if(p1<p2) swap(p1,p2);
	ll c1=0,c2=0,p=0;
	while(p2!=0)
	{
		//cout<<p1<<" "<<p2<<" "<<ans<<endl;
		c1=p1/p2,c2=p1%p2;
		ans+=c1*p2*2;
		p1=p2; p2=c2;
	}
	cout<<ans-p1<<endl;
	return 0;
}