#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const ll INF = 1LL<<60;
const ll mod = 1000000007LL;

struct dijkstra{
  struct Node{
    vector<ll> edges_to;
    vector<ll> edges_cost;
    bool done;
    ll cost;
  };
  vector<Node> graph;
  void init(ll N){
    graph.resize(N);
  }
  void add(ll from, ll to, ll cost){
    graph[from].edges_to.push_back(to);
    graph[from].edges_cost.push_back(cost);
  }
  void shortest(ll start){
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> d;
    d.push(make_pair(0,start));
    while(!d.empty()){
      pair<ll,ll> p = d.top();
      d.pop();
      Node &point = graph[p.second];
      if(point.done) continue;
      point.done = true;
      point.cost = p.first;
      for(ll i = 0; i < (ll)point.edges_to.size(); i++){
        if(graph[point.edges_to[i]].done)continue;
        d.push(make_pair(point.cost+point.edges_cost[i],point.edges_to[i]));
      }
    }
  }
};

int main() {
  ll N,M,R;
  cin>>N>>M>>R;
  vector<ll> v(R);
  for(ll i = 0; i<R; i++){
    ll x;
    cin>>x;
    v[i]=x-1;
  }
  dijkstra tree;
  tree.init(N);
  for(ll i = 0; i < M; i++){
    ll a,b,c;
    cin>>a>>b>>c;
    tree.add(a-1,b-1,c);
    tree.add(b-1,a-1,c);
  }
  map<pair<ll,ll>,ll> m;
  for(ll i = 0; i < R; i++){
    dijkstra T = tree;
    T.shortest(v[i]);
    for(ll j = 0; j < R; j++){
      pair<ll,ll> p = make_pair(i,j);
      m[p]=T.graph[v[j]].cost;
    }
  }
  vector<ll> P(R);
  for(ll i = 0; i < R; i++) P[i]=i;
  vector<vector<ll>> all;
  do{
    all.push_back(P);
  }while(next_permutation(P.begin(),P.end()));
  /*for(auto x:all){
    for(auto y:x)cout<<y<<" ";
    cout<<endl;
  }*/
  ll ans = INF;
  for(auto x:all){
    ll d=0LL;
    for(ll i = 0; i < (ll)x.size()-1;i++){
      d+=m[make_pair(x[i],x[i+1])];
    }
    chmin(ans,d);
  }
  cout<<ans<<endl;
}