#include<bits/stdc++.h>
using namespace std;
static const int64_t INF=10000000000000;
struct edge{int64_t from,to,cost;};
int main(){
int64_t N,M;cin>>N>>M;
  vector<edge>es(M);
  for(int i=0;i<M;i++){
  int64_t a,b,c;cin>>a>>b>>c;
    a--;b--;
    es[i].from=a;
    es[i].to=b;
    es[i].cost=-c;
  }vector<int64_t>d(N,INF);
  d[0]=0;
  for(int i=0;i<N-1;i++){
  for(int j=0;j<M;j++){
  if(d[es[j].from]!=INF && d[es[j].to]>d[es[j].from]+es[j].cost)
    d[es[j].to]=d[es[j].from]+es[j].cost;
   }
   } for(int i=0;i<N;i++){
  for(int j=0;j<M;j++){
  if(d[es[j].from]!=INF && d[es[j].to]>d[es[j].from]+es[j].cost)
    d[es[j].to]=-INF;
   }
   }if(d[N-1]<=-INF)
    cout<<"inf"<<endl;
  else
    cout<<-d[N-1]<<endl;
  
  return 0;
}