#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, a, count = 0;
  cin >> n;
  vector<int> vec(n);
  
  for (int i=0; i<n; i++) cin >> vec.at(i);
  
  int k = 1;
  for (int i=0; i<n; i++) {
    count++;
    k = vec.at(k-1);
    if (k == 2) break;
  }
  
  if (k != 2) count = -1;
  
  cout << count << endl;
}
