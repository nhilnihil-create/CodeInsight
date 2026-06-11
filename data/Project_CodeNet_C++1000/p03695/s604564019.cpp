#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a.at(i);
  }
  
  for (int &x : a) {
    x /= 400;
  }
  
  int max_count = 0;
  int min_count = 0;
  vector<int> already(8);
  for (int i = 0; i < n; i++) {
    if (a.at(i) >= 8) {
      max_count++;
    }
    for (int j = 0; j < 8; j++) {
      if (already.at(j) == 1) continue;
      if (a.at(i) == j) {
        max_count++;
        min_count++;
        already.at(j) = 1;
      }
    } 
  }
  
  if (max_count != 0 && min_count == 0) {
    min_count = 1;
  }
  
  cout << min_count << endl;
  cout << max_count << endl;
}
