#include<bits/stdc++.h>
using namespace std;

inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

typedef long long ll;
ll mod=1000000007;

int main()
{
	int n=read(),p=0;
	ll ans=1;
	for(int i=1;i<=n;i++)
	{
		int x=read();
		if (x>=2*p+1) ans=ans*(++p)%mod;
		else ans=ans*(p+1)%mod;
	}
	cout<<ans<<endl;
	return 0;
}
