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

int vis[M+5];

 main()

{
    fast
    int n,c,k;
    cin>>n>>c>>k;
    priority_queue<pair<int,pi>>yo,Magic;
    f(i,1,n)
    {
        int lft;
        cin>>lft;
        int rgt=lft+k;
        yo.push(mp(-rgt,mp(-lft,-i)));
        Magic.push(mp(-lft,mp(-rgt,-i)));
    }
    int cnt=0;
    int ses=0;
    while(!yo.empty())
    {

          pair<int,pi>cur=yo.top();
          yo.pop();
          int rgt=-cur.fi;
          int lft=-cur.si.fi;
          int idx=-cur.si.si;
          if(vis[idx])continue;
          vector<int>store;
          store.pb(idx);
          while(!yo.empty())
          {
              int tmp_rgt=-yo.top().fi;
              int tmp_idx=-yo.top().si.si;
              if(tmp_rgt==rgt)
              {
                  if(vis[tmp_idx]==0)store.pb(tmp_idx);
                  yo.pop();
              }
              else
              {
                  break;
              }
          }
          cnt=store.size();
          for(auto x:store)vis[x]=1;
          int bundle=cnt/c;
          ses+=bundle;
          int baki=cnt%c;
          if(baki==0)
          {
              continue;
          }
          baki=c-baki;
          while(!Magic.empty())
          {
              int tmp_lft=-Magic.top().fi;
              int tmp_rgt=-Magic.top().si.fi;
              int tmp_idx=-Magic.top().si.si;
              if(tmp_lft>rgt)break;
              if(baki<=0)break;
              if(vis[tmp_idx]==0)
              {
                   vis[tmp_idx]=1;
                   baki--;
              }
               Magic.pop();
          }
          ses++;

    }
    cout<<ses<<endl;
    return 0;

}




