#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using Graph=vector<vector<int>>;
#define MAX 5100000
#define MOD 10007
#define INF 100000000000000

int main(){
  int N,M;
  cin>>N>>M;
  vector<int> a(M),b(M),c(M);
  vector<vector<pair<int,int>>> G(N);
  for(int i=0;i<M;i++){
    cin>>a.at(i)>>b.at(i)>>c.at(i);
    a.at(i)--;
    b.at(i)--;
    G.at(a.at(i)).push_back(make_pair(b.at(i),i));
    G.at(b.at(i)).push_back(make_pair(a.at(i),i));
  }

  vector<bool> path(M,false);
  for(int i=0;i<N;i++){
    vector<int> dist(N,1000000000);
    dist.at(i)=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push(make_pair(0,i));
    while(!pq.empty()){
      int v=pq.top().second;
      for(auto p:G.at(v)){
        int nv=p.first;
        if(dist.at(v)+c.at(p.second)<dist.at(nv)){
          dist.at(nv)=dist.at(v)+c.at(p.second);
          pq.push(make_pair(dist.at(nv),nv));
        }
      }
      pq.pop();
    }

    pq.push(make_pair(0,i));
    while(!pq.empty()){
      int v=pq.top().second;
      for(auto p: G.at(v)){
        int nv=p.first;
        if(dist.at(v)+c.at(p.second)==dist.at(nv)){
          path.at(p.second)=true;
          pq.push(make_pair(dist.at(nv),nv));
        }
      }
      pq.pop();
    }
  }

  int ans=0;
  for(int i=0;i<M;i++){
    if(!path.at(i)){
      ans++;
    }
  }
  cout<<ans<<endl;

}
