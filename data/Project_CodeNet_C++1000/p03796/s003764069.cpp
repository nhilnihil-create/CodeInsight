#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
 
int main() {
  int x;
  long long int y = 1;
  cin >> x;
  for (int i = 1; i <= x; i++) {
    y *= i;
    y %= mod;
  }
  cout << y;
}