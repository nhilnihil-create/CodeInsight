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

const int inf=1e5;
const int mod=1e9+7;
const int M=20009;

inline int bigmod(int B,int P){int R=1;while(P>0){if(P&1){R=(R*B)%mod;}P>>=1;B=(B*B)%mod;}return R;}
inline int ad(int x,int y){int ret=(x%mod+y%mod)%mod;if(ret<0){ret+=mod,ret=ret%mod;}return ret;}
inline int sub(int x,int y){int ret=((x%mod)-(y%mod)+mod)%mod;if(ret<0){ret+=mod,ret=ret%mod;}return ret;}
inline int gun(int x,int y){int ret=((x%mod)*(y%mod))%mod;if(ret<0){ret+=mod,ret=ret%mod;}return ret;}

int id[M+3];
int pup[M+4];
int pdown[M+4];
int a[M+4];
int b[M+4];
 void solve()

{

    int n;
    cin>>n;
    f(i,1,n)
    {
        cin>>id[i];
    }
    f(i,1,n)
    {
        a[i]+=i;
    }
    for(int i=n,j=1;i>=1;i--,j++)
    {
        b[i]+=j;
    }
    for(int i=1;i<=n;i++)
    {
        int idx=id[i];
        b[idx]+=i;
        pdown[idx-1]+=i;
        pup[idx-1]-=i;
    }
    int yo=0;
    int cry=0;
    for(int i=n;i>=1;i--)
    {
         yo+=pdown[i];
         b[i]+=yo;
         cry+=pup[i];
         a[i]+=cry;
    }
    int mn=0;
    f(i,1,n)
    {
        mn=min(mn,a[i]);
    }
    f(i,1,n)
    {
        mn=min(mn,b[i]);
    }
    if(mn>0)mn=0;
    else mn=-mn+2;
    f(i,1,n)
    {
        cout<<a[i]+mn<<" ";
    }
    cout<<endl;
    f(i,1,n)
    {
        cout<<b[i]+mn<<" ";
    }
    cout<<endl;

}
 main()
 {
     //freopen("001.txt", "r", stdin);
     int t;
     t=1;
     while(t--)
     {
         solve();
     }
     return 0;
 }











