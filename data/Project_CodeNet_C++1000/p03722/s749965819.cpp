#include<bits/stdc++.h>
#define int long long
using namespace std;
const int INF=1000000000000000000;
signed main(){
  int N,M;
  cin>>N>>M;
  vector<pair<pair<int,int>,int>> A(M);
  vector<vector<int>> D(N);
  for(int i=0;i<M;i++){
    int a,b,c;
    cin>>a>>b>>c;
    A[i]=make_pair(make_pair(a-1,b-1),c);
    D[a-1].push_back(b-1);
  }
  vector<int> B(N,-INF);
  B[0]=0;
  vector<bool> C(N,false);
  queue<int> Q;
  for(int i=0;i<=N;i++){
    bool b=true;
    for(auto p:A){
      if(B[p.first.first]!=-INF && B[p.first.first]+p.second>B[p.first.second]){
        b=false;
        B[p.first.second]=B[p.first.first]+p.second;
        if(i==N-1){
          C[p.first.second]=true;
          Q.push(p.first.second);
        }
      }
    }
    if(b)break;
  }
  while(!Q.empty()){
    int I=Q.front();
    Q.pop();
    for(int i:D[I])
      if(!C[i]){
        C[i]=true;
        Q.push(i);
      }
  }
  if(C[N-1])puts("inf");
  else cout<<B[N-1]<<endl;
}