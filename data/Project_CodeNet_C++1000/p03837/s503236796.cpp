#include<bits/stdc++.h>
#define int long long
using namespace std;
const int INF=1000000000000000000;
int N,M;
vector<pair<int,int>> A[110];
int B[110];
signed main(){
  cin>>N>>M;
  set<pair<int,int>> S;
  for(int i=0;i<M;i++){
    int a,b,c;
    cin>>a>>b>>c;
    A[a-1].push_back({b-1,c});
    A[b-1].push_back({a-1,c});
  }
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++)B[j]=INF;
    B[i]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> Q;
    Q.push({0,i});
    while(!Q.empty()){
      pair<int,int> P=Q.top();
      Q.pop();
      if(B[P.second]<P.first)continue;
      for(pair<int,int> p:A[P.second])
        if(P.first+p.second<B[p.first]){
          B[p.first]=P.first+p.second;
          Q.push({P.first+p.second,p.first});
        }
    }
    queue<int> q;
    q.push(i);
    while(!q.empty()){
      int I=q.front();
      q.pop();
      for(pair<int,int> p:A[I])
        if(B[I]+p.second==B[p.first]){
          S.insert({min(p.first,I),max(p.first,I)});
          q.push(p.first);
        }
    }
  }
  cout<<M-S.size()<<endl;
}