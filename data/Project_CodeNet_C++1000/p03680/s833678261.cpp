#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  
  for (int i = 0; i < n; i++) {
    cin >> a.at(i);
  }
  
  int count = 1, number = a.at(0);
  
  while (number != 2) {
    if (count != n) {
      count++;
      number = a.at(number - 1);
    }
    else {
      break;
    }
  }
  
  if (count != n) {
    cout << count << endl;
  }
  else {
    cout << -1 << endl;
  }
}