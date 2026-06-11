#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  vector<vector<int>> map(N,vector<int>(2));
  
  for (int i = 0; i < N; i++) {
    map.at(i).at(0) = i + 1;
    cin >> map.at(i).at(1);
  }
  
  int count = 0;
  int k = 1;
  
  bool judge = false;
  
  for (int i = 0; i < N; i++) {
    if (map.at(k - 1).at(1) == 2) {
      judge = true;
      break;
    }
    k = map.at(k - 1).at(1);
    count++;
  }
  
  if (judge) {
    cout << count + 1 << endl;
  } else {
    cout << -1 << endl;
  }
}