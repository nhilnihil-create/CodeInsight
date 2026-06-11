#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using Graph=vector<vector<int>>;
#define MAX 1000000
#define MOD 1000000007
#define INF 100000000000000

int solve(int k,vector<int> r,vector<bool> visit,const vector<vector<int>> &dist){
  int N=r.size();
  int ans=1000000000;
  bool flag=false;
  visit.at(k)=true;
  for(int i=0;i<N;i++){
    flag=flag||!visit.at(i);
  }
  if(!flag){
    return 0;
  }

  for(int i=0;i<N;i++){
    if(visit.at(i)){
      continue;
    }
    ans=min(ans,dist.at(k).at(r.at(i))+solve(i,r,visit,dist));
  }
  return ans;
}

int main(){
  int N,M,R;
  cin>>N>>M>>R;
  vector<int> r(R);
  for(int i=0;i<R;i++){
    cin>>r.at(i);
    r.at(i)--;
  }
  vector<vector<pair<int,int>>> G(N);
  for(int i=0;i<M;i++){
    int A,B,C;
    cin>>A>>B>>C;
    A--;
    B--;
    G.at(A).push_back(make_pair(B,C));
    G.at(B).push_back(make_pair(A,C));
  }

  vector<vector<int>> dist(R,vector<int>(N,1000000000));
  for(int i=0;i<R;i++){
    dist.at(i).at(r.at(i))=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push(make_pair(0,r.at(i)));
    while(!pq.empty()){
      int v=pq.top().second;
      for(auto p:G.at(v)){
        int nv=p.first;
        if(dist.at(i).at(v)+p.second<dist.at(i).at(nv)){
          dist.at(i).at(nv)=dist.at(i).at(v)+p.second;
          pq.push(make_pair(dist.at(i).at(nv),nv));
        }
      }
      pq.pop();
    }
  }

  int ans=1000000000;
  vector<bool> visit(R,false);
  for(int i=0;i<R;i++){
    ans=min(ans,solve(i,r,visit,dist));
  }
  cout<<ans<<endl;
}
