#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  
  vector<int> button(n);
  
  for (int i = 0; i < n; i++) {
    cin >> button.at(i);
  }
  
  int x = 1,num = 0;
  
  for (int i = 0; i < n; i++) {
    x = button.at(x - 1);
    num++;
    if (x == 2) {
      cout << num << endl;
      break;
    }
    else if (num == n - 1) {
      cout << -1 << endl;
    }
  }
}