#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  vector<int> botan(N);
 
  for (int i = 0; i < N; i++) {
    cin >> botan.at(i);
  }
  
  int current = 0;
  int res = -1;
  
  for (int i = 0; i < N; i++) {
    if (current == 1) {
      res = i;
      break;
    }
    current = botan.at(current)-1;
  }
  cout << res << endl;
}
