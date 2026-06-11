#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  string o, e;
  cin >> o >> e;
  string p = "";
  rep(i, e.size()) {
    p += o[i];
    p += e[i];
  }
  if (o.size() - e.size() == 1) p += o[o.size()-1];
  cout << p << endl;
  return 0;
}