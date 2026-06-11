#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> swc(N);
  for (int i = 0; i < N; i++) {
    cin >> swc.at(i);
  }
  int x = 0;
  for (int i = 0; i < N; i++) {
    int x = swc.at(x) - 1;
    if (x == 1) {
      cout << i+1 << endl;
      break;
    }
    if (i == N-1) {
      cout << -1 << endl;
    }
  }    
}