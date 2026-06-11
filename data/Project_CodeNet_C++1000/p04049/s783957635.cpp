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
struct Grid{ll x,y,t;};
struct Edge{ll to,cost;};
struct Graph{vector<vector<Edge>>E;int V;
  const ll Inf = llINF;const int MAX_V=201010;vector<ll>d;
  Graph(int n):E(n){d.resize(MAX_V);E.resize(n);V=n;}
  void init(){for(int i=0;i<MAX_V;i++)d[i]=Inf;}
  void add_edge(ll from,ll to,ll cost){E[from].pb({to,cost});}
};
vvi E(10010);
ll n,k;
vector<pair<ll,pair<ll,ll>>> par;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin>>n>>k;
  par.resize(n);
  for(int i=0;i<n+10;i++)par[i].S.S=INF;
  for(int i=0;i<n-1;i++){
    ll a,b;cin>>a>>b;
    E[--a].pb(--b);
    E[b].pb(a);
  }
  /*
  ll d=0;
  for(int i=0;i<n;i++){
    if(E[i].size()!=1)continue;
    queue<pair<ll,ll>>que;
    bool visited[10000]={};
    que.push(mp(i,0));
    ll cnt=0;
    while(que.empty()==false){
      pair<ll,ll>now=que.front();
      que.pop();
      for(int j=0;j<E[now.F].size();j++){
	if(visited[E[now.F][j]]==false){
	  visited[E[now.F][j]]=true;
	  que.push(mp(E[now.F][j],now.S+1));
	  cnt=max(cnt,now.S+1);
	}
      }
    }
    d=max(d,cnt);
    }*/
  ll ans=INF;
  if(k%2){
    for(int i=0;i<n;i++){
      for(int j=0;j<E[i].size();j++){
      bool vis[2010]={};
      queue<pair<ll,ll>>que;
      que.push(mp(i,0));
      que.push(mp(E[i][j],0));
      vis[i]=true;
      vis[E[i][j]]=true;
      ll cnt=0;
      while(!que.empty()){
	pair<ll,ll>now=que.front();
	que.pop();
	for(int j=0;j<E[now.F].size();j++){
	  if(vis[E[now.F][j]]==false){
	    vis[E[now.F][j]]=true;
	    cnt+=(now.S+1>((k-1)/2));
	    que.push(mp(E[now.F][j],now.S+1));
	  }
	}
      }
      ans=min(ans,cnt);
      }
    }
  }else{
    for(int i=0;i<n;i++){
      bool vis[2010]={};
      queue<pair<ll,ll>>que;
      que.push(mp(i,0));
      ll cnt=0;
      vis[i]=true;
      while(!que.empty()){
	pair<ll,ll>now=que.front();
	que.pop();
	for(int j=0;j<E[now.F].size();j++){
	  if(vis[E[now.F][j]]==false){
	    vis[E[now.F][j]]=true;
	    cnt+=(now.S+1>(k/2));
	    que.push(mp(E[now.F][j],now.S+1));
	  }
	}
      }
      ans=min(ans,cnt);
    }
  }
  cout<<ans<<endl;
  return 0;
}
