#include <bits/stdc++.h>
using namespace std;


int main() {
  int N, K;
  cin >> N >> K;
  
  vector<int> x(N);
  for (int i=0; i<N; i++) {
    cin >> x.at(i);
  }
  
  int dist = 0;
  for (auto y : x) {
    if (abs(y-K) >= abs(y)) dist += abs(y)*2;
    else dist += abs(y-K)*2;
  }
  
  cout << dist << endl;

  return 0;
}
