#include <bits/stdc++.h>
#include <math.h>
#define rep(i, n) for(int i = 0; i < n; ++i)
using namespace std;

int main() {
  int n, m = 2000000000;
  cin >> n;
  rep(i, n){
    int a, b;
    cin >> a >> b;
    m = min(m, a+b);
  }
  cout << m << endl;
  return 0;
}