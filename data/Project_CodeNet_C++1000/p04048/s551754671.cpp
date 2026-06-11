#include <bits/stdc++.h>
using namespace std;

// ループによる最大公約数
long gcd(long x, long y){
  long r;
  if(x < y) swap(x, y);
  
  while(y > 0){
    r = x % y;
    x = y;
    y = r;
  }
  return x;
}

int main() {
  long n, x;
  cin >> n >> x;
  
  cout << (n - gcd(n, x)) * 3 << endl;
}