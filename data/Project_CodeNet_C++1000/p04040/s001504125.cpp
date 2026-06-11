#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N = 2e5 + 7;
const int mod = 1e9+7;
ll jc[N];
void init()
{
    jc[0]=1;
    jc[1]=1;
    for(int i=2;i<=N-2;i++){
        jc[i]=jc[i-1]*i%mod;
    }
}
ll qp(ll a,ll b)
{
    ll ret=1;
    while(b){
        if(b&1)ret = ret*a%mod;
        a = a*a %mod;
        b>>=1;
    }return ret;
}
ll c(ll n,ll m)
{
    return jc[n]* qp(jc[m]*jc[n-m]%mod,mod-2) %mod;
}
int main()
{
    init();
    ll n,m,a,b,ans=0;
    cin>>n>>m>>a>>b;
    ll d=b+n-1-a;
    ll d2=n+m-2-d;
    if(n-a<=m-b){
        for(int i=0;i<n-a;i++){
            ans = ans + c(d,i)*c(d2,n-1-i)%mod;
            ans%=mod;
        }
    }
    else{
        for(int i=0;i<m-b;i++){
            ans = ans + c(d,m-1-i)*c(d2,i)%mod;
            ans%=mod;
        }
    }
    cout<<ans<<endl;
}
