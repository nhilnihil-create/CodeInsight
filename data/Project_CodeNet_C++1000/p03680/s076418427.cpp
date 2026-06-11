#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  
  for (int i = 0; i < N; i++){
    cin >> A.at(i);
  }
  
  int here = 1;
  
  for (int i = 0; i < N + 10; i++){
    if (here == 2){
      cout << i << endl;
      break;
    }
    else{
      here = A.at(here - 1);
    }
    
    if (i > N){
      cout << -1 << endl;
      break;
    }
  }
}
