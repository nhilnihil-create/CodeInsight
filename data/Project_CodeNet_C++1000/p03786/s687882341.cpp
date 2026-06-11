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


vector<pi>vec;
int n;
bool chk(int id)
{
    int yo=vec[id].fi;
    for(int i=0;i<n;i++)
    {
          if(i==id)continue;
          if(vec[i].fi<=2*yo)
          {
              yo+=vec[i].fi;
          }
          else
          {
              return false;
          }
    }
    return true;
}
 main()

{
    fast
    int x;
    cin>>n;
    f(i,1,n)
    {
        cin>>x;
        vec.pb(mp(x,i));
    }
    sort(vec.begin(),vec.end());
    int lo=0;
    int hi=n-1;
    while(hi-lo>=2)
    {
        int mid=(lo+hi)>>1;
        if(chk(mid))
        {
            hi=mid;
        }
        else lo=mid+1;
    }
    f(i,lo,hi)
    {
        if(chk(i))
        {
            cout<<n-i<<endl;
            break;
        }
    }
    return 0;

}











