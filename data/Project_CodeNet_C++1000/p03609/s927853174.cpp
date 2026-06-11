#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int,string>;

int main() {
  int x,t;
  cin >> x >>t;
  if(t >= x) cout << 0 << endl;
  else cout << x-t << endl;
}