#include <bits/stdc++.h>
using namespace std; 

int main(){
  int N,M;
  cin >> N >> M;
  vector<vector<int>> G(N);
  for(int i=0;i<M;i++){
    int A,B;
    cin >> A >> B;
    G.at(A-1).push_back(B-1);
    G.at(B-1).push_back(A-1);
  }
  for(int i=0;i<N;i++){
    cout << G.at(i).size() << endl;
  }
}
  
    
    