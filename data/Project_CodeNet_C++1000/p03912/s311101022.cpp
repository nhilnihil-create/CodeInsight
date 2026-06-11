#include<bits/stdc++.h>
#define INF 1e9
#define llINF 1e18
#define MOD 1000000007
#define pb push_back
#define mp make_pair 
#define F first
#define S second
#define ll long long
#define vi vector<ll>
#define vvi vector<vi>
#define substr(s,f,t) (s.substr(f-1,t-f+1))
#define ALL(a) (a).begin(),(a).end()
#define Yes(hoge) cout<<((hoge)?"Yes":"No")<<endl;
#define YES(hoge) cout<<((hoge)?"YES":"NO")<<endl;
using namespace std;
struct Grid{int x,y,t;};
struct Edge{int to,cost;};
struct Graph{vector<vector<Edge>>E;int V;
  const ll Inf = llINF;const int MAX_V=1010;vector<ll>d;
  Graph(int n):E(n){d.resize(MAX_V);E.resize(n);V=n;}
  void init(){for(int i=0;i<MAX_V;i++)d[i]=Inf;}
  void add_edge(int from,int to,int cost){E[from-1].pb({to-1,cost});}
};
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n,m;cin>>n>>m;
  vector<pair<ll,ll> > cnt(100010);
  vector<ll>pll(100010);
  for(int i=0;i<n;i++){
    int num;cin>>num;
    pll[num]++;
  }

  for(int i=0;i<100010;i++){
    if(pll[i]>0){
      cnt[i%m].F+=pll[i];
      cnt[i%m].S+=pll[i]/2;
    }
  }
  ll ans=0;
  ans+=cnt[0].F/2;
  for(int i=1;i<=m/2;i++){
    if(i==m-i){
      ans+=cnt[i].F/2;
    }else{
      ans+=min(cnt[i].F,cnt[m-i].F);
      if(cnt[i].F>cnt[m-i].F){
	ans+=min(cnt[i].S,(cnt[i].F-cnt[m-i].F)/2);
      }else{
	ans+=min(cnt[m-i].S,(cnt[m-i].F-cnt[i].F)/2);
      }
    }
  }
  cout<<ans<<endl;
  return 0;
}
