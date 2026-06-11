#include <bits/stdc++.h>
#include <math.h>
#define rep(i, n) for(int i = 0; i < n; ++i)
using namespace std;

int main() {
  int n, a, x = 0;
  cin >> n;
  rep(i, n){
    x += i+1;
    if(x >= n){
      a = i+1;
      break;
    }
  }
  cout << a << endl;
  return 0;
}