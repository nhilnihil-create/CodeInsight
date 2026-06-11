#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, counts;
  int B = 1;
  cin >> N;
  vector<int> V(N);
  
  for (int i = 0; i < N; i++) {
    cin >> V.at(i);
  }
  
  for (int i = 0; i < N; i++) {
    B = V.at(B-1);
    counts++;
    if (B == 2) {
      break;
    }
  }
  
  if (counts == N) {
    cout << -1 << endl;
  }
  else {
    cout << counts << endl;
  }
}
