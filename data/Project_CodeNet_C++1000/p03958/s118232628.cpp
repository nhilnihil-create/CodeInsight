#include <bits/stdc++.h>
using namespace std;

int main() {
  int K, T;
  cin >> K >> T;
  vector<int> c(T);
  for (int &e : c) cin >> e;
  sort(c.begin(), c.end(), greater<int>());
  
  int M = c[0];
  cout << max(2*M-K-1,0) << endl;
}