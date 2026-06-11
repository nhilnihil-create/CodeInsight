#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
#define rep(i,a,b) for(register int i=(a);i<=(b);i++)
#define dep(i,a,b) for(register int i=(a);i>=(b);i--)
using namespace std;
#define maxn 200005
#define mod 1000000007
///(a/b)%mod=(a*pow(b,(mod-2)))%mod;
ll fac[maxn];
ll pow_mod(ll n,ll k)
{
    ll res=1;
    while(k>0)
    {
        if(k&1)
            res=res*n%mod;
        n=n*n%mod;
        k>>=1;
    }
    return res;
}

void init_fac()
{
    fac[0]=fac[1]=1;
    for(int i=2;i<maxn;++i)
    {
        fac[i]=(i*fac[i-1])%mod;
    }
}
ll C(ll A,ll B)
{
    //cout<<A<<" "<<fac[A]<<" "<<pow_mod(fac[B],mod-2)<<" "<<pow_mod(fac[A-B],mod-2)<<"!!!"<<endl;
    return (((fac[A]*pow_mod(fac[B],mod-2))%mod)*pow_mod(fac[A-B],mod-2)%mod)%mod;
}
ll H,W,A,B;
ll ans;
int main()
{
    init_fac();
    scanf("%lld%lld%lld%lld",&H,&W,&A,&B);
    ans=0;
    A=H-A+1;H--;W--;
    A--;B--;
    for(int i=1+B;i<=min(A+B,W);i++)
    {
        ans+=(C(A+B,i)*C(H+W-A-B,W-i))%mod;
        ans%=mod;
        //cout<<i<<" "<<ans<<" "<<C(A+B,i)<<" "<<C(H+W-A-B,W-i)<<endl;

    }
    cout<<ans%mod<<endl;
}

