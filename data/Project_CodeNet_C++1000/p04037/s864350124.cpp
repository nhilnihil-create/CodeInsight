#include<bits/stdc++.h>
using namespace std;
#define reg register
#define ll long long
inline ll read()
{
    ll x=0,w=0;char ch=getchar();
    while(!isdigit(ch))w|=ch=='-',ch=getchar();
    while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return w?-x:x;
}
bool com(ll x,ll y){return x>y;}
ll n,a[100005];
int main()
{
    n=read();
	for(reg ll i=1;i<=n;++i)
		a[i]=read();
	sort(a+1,a+1+n,com);
	for(reg ll i=1;i<=n;++i)
	{
		if(i+1>a[i+1])
		{
			ll j=i+1,an=0;
			while(a[j]==i)an++,j++;
			an%=2;
			if(an||((a[i]-i)&1))puts("First");
			else puts("Second");
			return 0;
		}
	}
}
