#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  
  int color = K;
  if (N>=2){
    for (int i=0; i<N-1; i++){
      color *= K-1;
    }
  }
  cout << color << endl;
}