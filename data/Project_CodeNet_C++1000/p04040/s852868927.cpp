#include <iostream>

using namespace std;
typedef long long ll;
const int N=2e5+10;
const int mod=1e9+7;
int inv[N];
int p[N];
int qmi(int a,int b)
{
    int ans=1;
    while(b){
        if(b&1)ans=(ll)ans*a%mod;
        a=(ll)a*a%mod;
        b>>=1;
    }
    return ans;
}
int C(int a,int b)
{
    int ans=1;
    ans=(ll)ans*p[a]%mod;
    ans=(ll)ans*inv[b]%mod;
    ans=(ll)ans*inv[a-b]%mod;
    return ans;
}
int main()
{
    int n,m,a,b;
    cin>>n>>m>>a>>b;
    p[0]=1,inv[0]=1;
    for(int i=1;i<=n+m;i++)
    {
        p[i]=(ll)i*p[i-1]%mod;
        inv[i]=(ll)inv[i-1]*qmi(i,mod-2)%mod;
    }
    ll res=0;
    for(int i=0;i<=n-a-1;i++)
    {
        res=((ll)res+(ll)C(n-a+b-2-i,b-1)%mod*C(m+a-b+i-1,m-b-1)%mod)%mod;
        // cout<<(m+a-b+i-2)<<' '<<(m-b-1)<<endl;
    }
    cout<<res<<endl;
}