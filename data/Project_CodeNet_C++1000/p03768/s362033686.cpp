#include<bits/stdc++.h>
using namespace std;
int64_t dist[200005];
int64_t color[200005];
int64_t N,M,Q;
using Graph=vector<vector<int64_t>>;
int main(){
  cin>>N>>M;
  Graph G(N);
  for(int i=0;i<N;i++)
  dist[i]=-1;
   
  for(int i=0;i<M;i++){
  int64_t a,b;cin>>a>>b;a--;b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }cin>>Q;
  vector<tuple<int64_t,int64_t,int64_t>>A(Q);
  for(int i=Q-1;0<=i;i--){
   int64_t v,d,c;cin>>v>>d>>c;v--;
    tuple<int64_t,int64_t,int64_t>t(v,d,c);
    A.at(i)=t;
   }
  for(int i=0;i<Q;i++){
  int64_t v=get<0>(A[i]);
    int64_t d=get<1>(A[i]);
    int64_t c=get<2>(A[i]);
    if(d<=dist[v])
      continue;
    else{
      dist[v]=d;
    queue<int64_t>que;que.push(v);
      while(!que.empty()){
      int64_t u=que.front();
        que.pop();
        if(color[u]==0)color[u]=c;
        for(auto k:G[u])
           if(dist[u]-1<=dist[k])
             continue;
        else{
        dist[k]=dist[u]-1;
          que.push(k);
        }
          
   }
    
    }
   }for(int i=0;i<N;i++)
    cout<<color[i]<<endl;
  return 0;
}