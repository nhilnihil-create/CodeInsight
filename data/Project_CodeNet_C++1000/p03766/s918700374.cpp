#include<bits/stdc++.h>
#define LL long long
#define db double
#define il inline
#define re register
#define mkpr make_pair

using namespace std;
const int N=1e6+10,mod=1e9+7;
il LL rd()
{
    LL x=0,w=1;char ch=0;
    while(ch<'0'||ch>'9') {if(ch=='-') w=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') {x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
    return x*w;
}
int n,m,f[N],ans;

int main()
{
    //???
	n=rd();
	m=(1ll*(n-1)*(n-1))%mod;
	ans=m+1+(n>2);
	int sm=f[0]=1;
	for(int i=1;i<n;++i)
	{
		f[i]=sm;
		if(i-2>=0) f[i]=(f[i]-f[i-2]+mod)%mod;
		sm=(sm+f[i])%mod;
		if(i!=n-1) ans=(ans+1ll*f[i]*(m+min(i+2,n-1))%mod)%mod;
		else ans=(ans+1ll*f[i]*n%mod)%mod;
	}
	printf("%d\n",ans);
    return 0;
}

