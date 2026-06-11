#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;


int main() {
  int n, l, r;
  cin >> n;
  int sum = 0;
  rep(i,n){
    cin >> l >> r;
    sum += r-l+1;
  }
  cout << sum << endl;
  return 0;
}