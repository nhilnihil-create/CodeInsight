#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,M;
  cin >> N;
  vector<int> T(N);
  for(int i=0;i<N;i++){
    cin >> T.at(i);
  }
  cin >> M;
  vector<int> P(M),X(M);
  for(int i=0;i<M;i++){
    cin >> P.at(i) >> X.at(i);
  }
  for(int i=0;i<M;i++){
    long long time=0;
    for(int j=0;j<N;j++){
      if(j!=P.at(i)-1){
        time+=T.at(j);
      }
      else{
        time+=X.at(i);
      }
    }
    cout << time << endl;
  }
}