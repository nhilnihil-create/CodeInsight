#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n;
  cin >> n;
  
  int m = 1000000007;
  long long p = 1;
  
  for (int i = 1; i <= n; i++) {
    p *= i;
    p = p % m;
  }
  
  cout << p;
}