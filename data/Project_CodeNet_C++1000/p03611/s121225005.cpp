#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;cin>>N;
  vector<int> A(100000,0);
  for(int i=0;i<N;i++){
    int D;cin>>D;
    A.at(D)++;
  }
  priority_queue<int> ans;
  for(int i=1;i<99999;i++){
    int L=A.at(i-1)+A.at(i)+A.at(i+1);
    ans.push(L);
  }
  cout<<ans.top()<<endl;
}
