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

int a[M+4];
int pre[M+4];
int lft[M+4];
int rgt[M+4];

 main()

{
    fast
    int n,k;
    cin>>n>>k;
    int ses=0;
    f(i,1,n)
    {
        cin>>a[i];
        ses+=a[i];
        pre[i]=a[i]+pre[i-1];
        lft[i]=lft[i-1];
        if(a[i]>0)lft[i]+=a[i];
    }
    ses=max(ses,0LL);
    rf(i,n,1)
    {
        rgt[i]=rgt[i+1];
        if(a[i]>0)rgt[i]+=a[i];
    }
    for(int i=1;i<=n-k+1;i++)
    {
        int l=i;
        int r=i+k-1;
        int sum=pre[r]-pre[l-1];
        sum=max(sum,0LL);
        sum+=rgt[r+1];
        sum+=lft[l-1];
        ses=max(ses,sum);
    }
    cout<<ses<<endl;
    return 0;

}











