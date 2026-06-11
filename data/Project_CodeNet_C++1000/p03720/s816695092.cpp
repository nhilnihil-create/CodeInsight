#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  int C;  
  vector<int> counts(N);
  
  for (int i = 0; i < M * 2; i++) {
    cin >> C;
    counts.at(C-1)++;
  }
  
  for (int i = 0; i < N; i++) {
    cout << counts.at(i) << endl;
  }
}
