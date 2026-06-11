#include <bits/stdc++.h>

using namespace std;

bool binary_search(vector<int> list, int v) {
  int l = 0, r = list.size();
  
  while (abs(r - l) >= 1) {
    int m = (l + r) / 2;
    
    if (list[m] == v) {
      return true;
    } else if (list[m] < v) {
      l = m + 1;
    } else {
      r = m;
    }
  }
  
  return false;
}

int main() {
  int K, S, ans = 0;
  
  
  vector<int> possible;
  
  cin >> K >> S;
  
  for (int i = 0; i <= K; i++) {
    possible.push_back(S - i);
  }
  
  sort(possible.begin(), possible.end());
  
  for (int x = 0; x <= K; x++) {
    for (int y = 0; y <= K; y++) {
      if (binary_search(possible, x + y)) {
        ans++;
      }
    }
  }
  
  cout << ans << endl;
  
  return 0;
}