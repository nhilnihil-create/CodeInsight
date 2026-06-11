#include <bits/stdc++.h>
using namespace std;

int main(){
  int N, M;
  cin>>N>>M;
  vector<vector<int>> data(M, vector<int>(2));
  for(int i=0;i<M;i++){
    for(int j=0;j<2;j++){
      cin>>data.at(i).at(j);
    }
  }
  vector<int> ans(N);
  for(int i=0;i<M;i++){
    for(int j=0;j<2;j++){
      ans.at(data.at(i).at(j)-1)+=1;
    }
  }
  for(int i=0;i<N;i++){
    cout<<ans.at(i)<<endl;
  }
}