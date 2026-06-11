#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  
  vector<int> S(M*2);
  vector<int> C(N);
  
  for(int i=0;i<M*2;i++) {
    cin >> S.at(i);
    
    for(int j=0;j<N;j++) {
      if(S.at(i)==j+1) C.at(j)++;
    }
    
  }
  
  for(int i=0;i<N;i++) cout << C.at(i) << endl;

}



