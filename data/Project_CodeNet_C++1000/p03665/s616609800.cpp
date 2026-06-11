///Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>

#define                           int                         long long
#define                           fi                          first
#define                           si                          second
#define                           mp                          make_pair
#define                           pb                          push_back
#define                           pi                          pair<int,int>
#define                           f(i,l,r)                    for(int i=l;i<=r;i++)
#define                           rf(i,r,l)                   for(int i=r;i>=l;i--)
#define                           done(i)                     cout<<"done = "<<i<<endl;
#define                           fast                        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);




using namespace std;

const int inf=1e18;
const int mod=1e9+7;
const int M=100009;

inline int bigmod(int B,int P){int R=1;while(P>0){if(P&1){R=(R*B)%mod;}P>>=1;B=(B*B)%mod;}return R;}
inline int ad(int x,int y){int ret=(x%mod+y%mod)%mod;if(ret<0){ret+=mod,ret=ret%mod;}return ret;}
inline int sub(int x,int y){int ret=((x%mod)-(y%mod)+mod)%mod;if(ret<0){ret+=mod,ret=ret%mod;}return ret;}
inline int gun(int x,int y){int ret=((x%mod)*(y%mod))%mod;if(ret<0){ret+=mod,ret=ret%mod;}return ret;}

int a[55],dp[55];
int ncr(int n,int r)
{
    int lob=1;
    f(i,1,n)lob=lob*i;
    int hor=1;
    f(i,1,r)hor=hor*i;
    f(i,1,n-r)hor=hor*i;
    return lob/hor;
}
int chk(int x)
{
    int ret=0;
    for(int i=0;i<=x;i+=2)
    {
        ret+=ncr(x,i);
    }
    return ret;
}
 main()

{
    fast
    int n,p;
    cin>>n>>p;
    int od=0;
    int ses=1;
    int total=1;
    f(i,1,n)
    {
        cin>>a[i];
        total=total*2;
        if(a[i]%2==0)
        {
            ses=ses*2;
        }
        else
        {
            od++;
        }
    }
    if(od==0)
    {
        if(p==1)
        {
            cout<<"0"<<endl;
        }
        else cout<<ses<<endl;
        return 0;
    }
    dp[0]=1;
    for(int i=1;i<=od;i++)
    {
        dp[i]=dp[i-1]*2;
    }
    ses=ses*dp[od-1];
    if(p==1)
    {
        ses=total-ses;
    }
    cout<<ses<<endl;
    return 0;

}



































