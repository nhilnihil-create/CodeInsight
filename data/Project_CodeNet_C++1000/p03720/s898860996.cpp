#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,M;
  cin >> N >> M;
  
  vector<vector<int>> A(M,vector<int>(2));
  
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < 2; j++) cin >> A.at(i).at(j);
  }
  
  int count = 0;
  for (int k = 1; k <= N; k++) {
    for (int i = 0; i < M; i++) {
      for (int j = 0; j < 2; j++) {
          if (A.at(i).at(j) == k) count++;
      }
    }
    cout << count << endl;
    count = 0;
  }
}