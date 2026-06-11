#include <bits/stdc++.h>
using namespace std;

int mod(long long x) {
    return x % 1000000007;
}
 
int main() {
  int n;
  cin >> n;
  
  long long p = 1;
  
  for (int i = 1; i <= n; i++) {
    p *= i;
    p = mod(p);
  }
  
  cout << p;
}