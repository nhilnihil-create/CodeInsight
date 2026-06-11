#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define mp(x,y) make_pair(x,y)
#define all(x) (x).begin(),(x).end()
#define pb push_back
using ll = long long;
using vin=vector<int>;
using vll=vector<ll>;
using vst=vector<string>;
using P = pair<int, int>;
const int inf=1e9+7;
const ll INF=1e18;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }
template<class T> inline void Yes(T condition){ if(condition) cout << "Yes" << endl; else cout << "No" << endl; }
template<class T> inline void YES(T condition){ if(condition) cout << "YES" << endl; else cout << "NO" << endl; }
const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };

int n;
vector<vector<pair<ll,ll>>> gra;
vll dist;

int main(){cout<<fixed<<setprecision(10);
           cin>>n;
           gra.resize(n);
           dist.assign(n,-1);
           ll a,b,c;
           rep(i,0,n-1){
             cin>>a>>b>>c;
             a--;b--;
             gra[a].push_back(mp(b,c));
             gra[b].push_back(mp(a,c));
           }
           ll q,k;
           cin>>q>>k;
           k--;
           //bfs
           queue<ll> que;
           dist[k]=0;
           for(auto v:gra[k]){
             dist[v.first]=v.second;
          		 que.push(v.first);
             }
           while(!que.empty()){
            ll p=que.front();
             que.pop();
             for(auto v:gra[p]){
              ll next=v.first,cost=v.second;
              if(dist[next]!=-1)continue;
              dist[next]=dist[p]+cost;
              que.push(next);
             }
           }
           ll x,y;
           rep(i,0,q){
            cin>>x>>y;
             //
             x--;y--;
             cout<<dist[x]+dist[y]<<endl;
           }
}