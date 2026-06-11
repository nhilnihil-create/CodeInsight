#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int N,M;
  cin >> N >> M;
  
  vector<int> A(M);
  vector<int> B(M);
  
  for(int i=0; i<M; i++){
    cin >> A.at(i) >> B.at(i);
  }
    
  
  for(int i=1; i<N+1; i++){
    int cnt = 0;
    for(int j=0; j<M; j++){
      if(A.at(j) == i){
        cnt++;
      }
     
      if(B.at(j) == i){
        cnt++;
      }
       
    }
    
    cout << cnt << endl;
  }
  
}
