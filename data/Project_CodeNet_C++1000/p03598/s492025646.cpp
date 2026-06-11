#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;

  int dis = 0;
  
  for ( int i = 0; i < N; i++){
    int x;
    cin >> x;
    
    if (x >= K - x){
      dis += 2*(K -x);
    }
    else {
      dis += 2*x;
    }
  }
    cout << dis << endl;
  }
  