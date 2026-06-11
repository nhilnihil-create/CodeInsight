#include<bits/stdc++.h>
using namespace std;
int main(){
  int N; cin>>N;
  vector<int> Q(N);
  int T=0;
  for(int i=0; i<N; i++){
    cin>>Q.at(i);
    T+=Q.at(i);
  }
  int M; cin>>M;
  vector<vector<int>> D(M,vector<int>(2));
  for(int i=0 ;i<M; i++){
    for(int j=0; j<2; j++){
      cin>>D.at(i).at(j);
    }
  }
  for(int i=0 ;i<M; i++){
    T-=Q.at(D.at(i).at(0)-1);
    cout<<T+D.at(i).at(1)<<endl;
     T+=Q.at(D.at(i).at(0)-1);
  }
}
