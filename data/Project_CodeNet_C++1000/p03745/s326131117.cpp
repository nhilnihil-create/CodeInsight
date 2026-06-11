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


 main()

{
    fast
    int n;
    cin>>n;
    int a[n+5];
    f(i,1,n)
    {
        cin>>a[i];
    }
    int dp_in[n+5],dp_dec[n+5];
    dp_in[n]=1;
    dp_dec[n]=1;
    rf(i,n-1,1)
    {
        if(a[i]<=a[i+1])
        {
            dp_in[i]=dp_in[i+1]+1;
        }
        else dp_in[i]=1;
         if(a[i]>=a[i+1])
        {
            dp_dec[i]=dp_dec[i+1]+1;
        }
        else dp_dec[i]=1;
    }
    int cnt=0;
    f(i,1,n)
    {
        int x=dp_in[i];
        int y=dp_dec[i];
        int r1=i+x-1;
        int r2=i+y-1;
        if(r1>=r2)
        {
            i=r1;
            cnt++;
        }
        else
        {
            i=r2;
            cnt++;
        }
    }
    cout<<cnt<<endl;
    return 0;

}



































