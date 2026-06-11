#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int,string>;

int main() {
  string s;
  cin >> s;
  string ans = s.front() + to_string(s.size()-2) + s.back();
  cout << ans << endl;
 }
