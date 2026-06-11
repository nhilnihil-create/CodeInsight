#include<iostream>
using namespace std;
typedef long long int ll;
ll mod=1e9+7;
ll fac[200009];
ll inv[200009];
ll nCr(int i , int j)
{
    return ((fac[i]*inv[j])%mod*inv[i-j])%mod;
}
int main()
{
    fac[0]=1;
    for(int i=1;i<=200000;i++) fac[i]=(i*fac[i-1])%mod;
    inv[0]=inv[1]=1;
    for(int i=2;i<=200000;i++) inv[i] = (mod - (mod/i) * inv[mod%i] % mod) % mod;
    for(int i=2;i<=200000;i++) inv[i]=(inv[i]*inv[i-1])%mod;
    int h,w,a,b;
    cin>>h>>w>>a>>b;
    ll ans=(((fac[h+w-2])*(inv[h-1]))%mod*inv[w-1])%mod;
    //cout<<ans<<"\n";
    for(int i=1;i<=b;i++) {ans=((ans-(nCr(h-a-1+i-1,i-1)*nCr(a-1+w-i,w-i))%mod)%mod+mod)%mod;}// cout<<ans<<"\n";}
    cout<<ans;
}
