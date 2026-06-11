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

inline int mini(int a,int b,int c,int d)
{
    return min(a,min(b,min(c,d)));
}
 main()

{
    fast
    int q,h,s,d;
    cin>>q>>h>>s>>d;
    int n;
    cin>>n;
    int yo=n/2;
    int x=q*8;
    int y=h*4;
    int z=s*2;
    int mn=mini(x,y,z,d);
    int ses=mn*yo;
    n=n%2;
    x=q*4;
    y=h*2;
    z=s;
    mn=min(x,min(y,z));
    ses+=(mn*n);
    cout<<ses<<endl;
    return 0;

}



































