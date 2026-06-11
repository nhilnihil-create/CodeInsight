#include <bits/stdc++.h>
#define pb push_back
#define tam 102
#define offset 320000
#define se second
#define fi first
#define pitem item*
#define ptr tre*
#define forr(i,p,n) for(int i=p;i<n;i++)
using namespace std;
typedef long long ll;
const ll MOD=1000000007 ;
ll mult(ll a,ll b, ll p=MOD){return ((a%p)*(b%p))%p;}
ll add(ll a, ll b, ll p=MOD){return (a%p + b%p)%p;}
typedef pair<ll,ll> ii;
typedef pair<ll,ii> iii;
typedef pair<double,double> pt;
ll peso[tam],valor[tam],dp[tam][tam][tam*3];
int n,W;
ll f(int pos,int celem,int suma)
{
    if (celem*peso[0]+suma>W)
        return -1e9;
    if (pos==n)
        return 0;
    if (dp[pos][celem][suma]!=-1)
        return dp[pos][celem][suma];
    return dp[pos][celem][suma]=max(f(pos+1,celem,suma),f(pos+1,celem+1,peso[pos]-peso[0]+suma)+valor[pos]);
}
int main()
{
    
    cin>>n>>W;
    forr(i,0,n)
    {
        cin>>peso[i]>>valor[i];
    }
    memset(dp,-1,sizeof dp);
    cout<<f(0,0,0)<<endl;
    
}