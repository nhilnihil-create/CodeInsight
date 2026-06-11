#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n;
  cin >> n;
  int a = 1;
  while (a * 2 <= n) {
    a *= 2;
  }
  cout << a << endl;
  return 0;
}