#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  int N,M;
  cin>>N>>M;
  vector<queue<int>> A(N);
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      int a;
      cin>>a;
      A[i].push(a-1);
    }
  }
  int ans=N;
  vector<bool> B(M,true);
  for(int i=0;i<M;i++){
    map<int,int> D;
    for(int j=0;j<N;j++)
      if(!A[j].empty())
        D[A[j].front()]++;
    if(D.size()==0)
      break;
    vector<pair<int,int>> C(0);
    for(pair<int,int> p:D)
      C.push_back({p.second,p.first});
    sort(C.begin(),C.end());
    reverse(C.begin(),C.end());
    for(int i=0;i<C.size() && C[0].first==C[i].first;i++)
      B[C[i].second]=false;
    for(int j=0;j<N;j++)
      while(!A[j].empty() && !B[A[j].front()])
        A[j].pop();
    ans=min(ans,C[0].first);
  }
  cout<<ans<<endl;
}