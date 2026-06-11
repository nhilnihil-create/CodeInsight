#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n = 0;
  cin >> n;
  
  vector<int> x(n);
  for (int i = 0; i < n; i++) {
    cin >> x.at(i);
  }

  int mincost = 100000000000;
  for (int y = -100; y < 101; y++) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
      sum += pow((x.at(i) - y), 2);
    }
    mincost = min(sum, mincost);
  }
  
  cout << mincost << endl;
}
 