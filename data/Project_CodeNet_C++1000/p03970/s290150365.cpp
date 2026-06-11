#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using ld = long double;
long double const pi = std::acos(-1.0L);
typedef pair<int,int> P;

int main() {
  string s; cin >> s;
  string a = "CODEFESTIVAL2016";
  int cnt = 0;
  rep(i,s.size()){
    if(s[i]!=a[i]) cnt++;
  }
  cout << cnt << endl;
  return 0;
}