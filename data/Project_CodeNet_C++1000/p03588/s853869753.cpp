#include<bits/stdc++.h>
using namespace std;
int main(){
  int N; cin>>N;
  vector<vector<int>> S(N,vector<int>(2));
  for(int i=0; i<N; i++){
    for(int j=0; j<2; j++){
      cin>>S.at(i).at(j);
    }
  }
  int K=S.at(0).at(0); int L=S.at(0).at(1);
  for(int i=0; i<N; i++){
    if(S.at(i).at(1)<L){
      K=S.at(i).at(0);
    L=S.at(i).at(1);
    }
    else continue;
  }
  cout<<L+K<<endl;
}
    
