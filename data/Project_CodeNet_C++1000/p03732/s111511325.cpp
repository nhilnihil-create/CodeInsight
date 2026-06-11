#include <iostream>
#include <vector>
#include <set>
#include <cstring>
#define pb push_back
#define tam 520004
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
ll n,w;
ll dp[102][303][102];
ll peso[302],valor[302];
ll f(int pos,int suma,int cuantos)
{
    if (pos==n)
    {
        ll auxval=cuantos;auxval*=peso[0];auxval+=suma;
        if (auxval<=w)
            return 0;
        return -1e10;
    }
    if (dp[pos][suma][cuantos]!=-1)
        return dp[pos][suma][cuantos];
    return dp[pos][suma][cuantos]=max(f(pos+1,suma+peso[pos]-peso[0],cuantos+1)+valor[pos],
    f(pos+1,suma,cuantos));
}
int main()
{
    cin>>n>>w;
    forr(i,0,n)
    {
        cin>>peso[i]>>valor[i];

    }
    memset(dp,-1,sizeof dp);
    cout<<f(0,0,0)<<endl;
}
