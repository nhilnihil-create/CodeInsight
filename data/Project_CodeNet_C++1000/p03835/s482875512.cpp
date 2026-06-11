
#include<bits/stdc++.h>
#define lld         long long int
#define llf         long double
#define pb          push_back
#define mp          make_pair
#define IN          insert
#define loopN(n)    for(lld i=0;i<n;i++)
#define loop(p,n)   for(lld i=p;i<=n;i++)
#define rloop(p,n)  for(lld i=n;i>=p;i--)
#define loop2(p,n)  for(lld j=p;j<=n;j++)
#define all(v)      v.begin(),v.end()
#define F1          first
#define F2          second
#define INF         2e18
#define FILE        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout)
#define PI          2*acos(0.0);
#define ISO         ios::sync_with_stdio(false);cin.tie(0)
#define mod         100000007
#define mem(a,b)    memset(a,b,sizeof(a))
using namespace std;

lld n;
lld dp[3*2500+5][4];


lld fun(lld k,lld z)
{
    if(k==0)
    {
        return 1;
    }
    if(k<0)
    {
        return 0;
    }
    if(z==0)
    {
        return 0;
    }
    if(dp[k][z]!=-1)
    {
        return dp[k][z];
    }

    lld ans=0;
    loop(0,n)
    {
        ans+=fun(k-i,z-1);
    }
    return dp[k][z]=ans;
}

int main()
{
    ISO;
    lld k;
    cin>>n>>k;
    mem(dp,-1);
    cout<<fun(k,3)<<endl;
    return 0;
}
