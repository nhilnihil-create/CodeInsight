#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int a, b, c;
  cin >> a >> b >> c;

  cout << min({(a+b), (b+c), (c+a)}) << endl;
  return 0;
}