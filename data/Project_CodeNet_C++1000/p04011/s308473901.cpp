#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n, k ,x, y;
  cin >> n >> k >> x >> y;
  
  int sum = 0;
  if (n <= k) {
    sum = n * x;
  }
  
  if (n > k) {
    sum = (k * x) + ((n - k) * y);
  }
  
  cout << sum << endl;
  
}
 