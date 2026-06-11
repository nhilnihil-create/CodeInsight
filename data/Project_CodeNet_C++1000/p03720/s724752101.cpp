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
    
  vector<int> road(N,0);
  for(int i=0; i<M; i++){
    road.at((A.at(i)-1))++;
    road.at((B.at(i)-1))++;
  }
    
  for(int i=0; i<N; i++){  
    cout << road.at(i) << endl;
  }
   
}
