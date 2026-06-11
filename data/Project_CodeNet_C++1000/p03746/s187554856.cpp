#include<bits/stdc++.h>
using namespace std;
signed main(){
  int N,M;
  cin>>N>>M;
  vector<set<int>> A(N);
  vector<vector<int>> B(N);
  deque<int> D;
  while(M--){
    int a,b;
    cin>>a>>b;
    if(D.size()==0)D.push_front(a-1),D.push_back(b-1);
    else A[a-1].insert(b-1),A[b-1].insert(a-1);
    B[a-1].push_back(b-1);
    B[b-1].push_back(a-1);
  }
  for(int i:A[D.front()])A[i].erase(D.front());
  for(int i:A[D.back()])A[i].erase(D.back());
  while(true){
    if(A[D.front()].size()){
      D.push_front(*(A[D.front()].begin()));
      for(int i:B[D.front()])A[i].erase(D.front());
    }else if(A[D.back()].size()){
      D.push_back(*(A[D.back()].begin()));
      for(int i:B[D.back()])A[i].erase(D.back());
    }else break;

  }
  cout<<D.size()<<endl;
  for(int i=0;i<D.size();i++)cout<<D[i]+1<<(i+1==D.size()?'\n':' ');
}