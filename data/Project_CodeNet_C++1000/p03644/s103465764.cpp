#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int N;
  cin >> N;
  
  int cnt=0;
  
  vector<int> A(N);
  for(int i=0; i<N; i++){
    A.at(i) = i+1;
  }
  
  while(true){
    bool tf = false;
    for(int i=0; i<N; i++){
      if(A.at(i) % 2 == 0){
        tf = true;
        A.at(i) /= 2;
        cnt = i;
      }
    }
    
    if(tf == false){
      break;
    }

  }
  
  cout << cnt + 1 << endl;
  
}
