#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define forr(i,p,n) for(ll i=p;i<n;i++)
#define tam 2010
#define offset 50000
using namespace std;
typedef long long  ll;
typedef pair<ll,ll> ii;
typedef pair<ll,ii> iii;
const ll MOD=1e9+7;
int n,m;

int dp[5200][5200];
void mod(int &tot)
{
    while(tot>=MOD)
        tot-=MOD;
}
int go(int pos,int acarreo)
{
    if (pos==n)
    {
        if (acarreo==m)
            return 1;
        return 0;
    }
    if (dp[pos][acarreo]!=-1)
        return dp[pos][acarreo];
    int tot=0;
    tot+=go(pos+1,acarreo+1)*2;
    mod(tot);
    tot+=go(pos+1,max(0,acarreo-1));
    mod(tot);
    return dp[pos][acarreo]=tot;
}
ll pot(ll base,ll exp)
{
    base%=MOD;
    ll res=1;
    while(exp>0)
    {
        if (exp&1)
            res*=base,res%=MOD;
        base*=base;base%=MOD;
        exp/=2;
    }
    return res;
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);
    
    cin>>n;
    string txt;
    cin>>txt;
    m=txt.size();
    memset(dp,-1,sizeof dp);
    ll ans=go(0,0);
    //cout<<ans<<endl;
    //return 0;
    //cout<<ans<<endl;
    //cout<<pot(2,m)<<" "<<pot(pot(2,m),MOD-2)<<endl;
    ans*=pot(pot(2,m),MOD-2);ans%=MOD;
    cout<<ans<<endl;

}   
