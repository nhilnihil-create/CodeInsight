#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 1; i <= (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main(){
  int a, b, c;
  cin >> a >> b >> c;
  bool ans = false;
  rep (i, b){
    if ((a * i) % b == c) ans = true;
  }
  if (ans) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}