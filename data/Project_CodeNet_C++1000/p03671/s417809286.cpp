#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int a, b, c;
  cin >> a >> b >> c;

  vector<int> v = {a, b, c};
  sort(v.begin(), v.end());

  cout << v.at(0) + v.at(1) << endl;
}