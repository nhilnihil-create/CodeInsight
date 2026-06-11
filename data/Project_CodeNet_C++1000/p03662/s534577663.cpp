#include<bits/stdc++.h>
using namespace std;

template <typename T>
vector<T> dijkstra(int s,vector< vector< pair<int, T> > > & G){
  const T INF = numeric_limits<T>::max();
  using P = pair<T, int>;
  int n=G.size();
  vector<T> ds(n,INF);
  vector<int> bs(n,-1);
  priority_queue<P, vector<P>, greater<P> > pq;
  ds[s]=0;
  pq.emplace(ds[s],s);
  while(!pq.empty()){
    P p=pq.top();pq.pop();
    int v=p.second;
    if(ds[v]<p.first) continue;
    for(auto& e:G[v]){
      int u=e.first;
      T c=e.second;
      if(ds[u]>ds[v]+c){
        ds[u]=ds[v]+c;
        bs[u]=v;
        pq.emplace(ds[u],u);
      }
    }
  }
  return ds;
}

int main() {
    int N; cin >> N;
    vector<vector<pair<int,int>>> G(N);
    for(int i=0;i<N-1;i++){
       int a,b; 
       cin >> a >> b;
       a--; b--;
       G[a].emplace_back(b,1);
       G[b].emplace_back(a,1);
    }
    vector<int> f,s;
    f=dijkstra(0,G);
    s=dijkstra(N-1,G);
    int cnt=0;
    for(int i=0;i<N;i++){
       if(f[i]<=s[i]){
          cnt++;
       }
    }
    if(N/2<cnt){
       cout << "Fennec" << endl;
    } else {
       cout << "Snuke" << endl;
    }
}