#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
  int x, a, b;
  cin >> x >> a >> b;
  string ans = "safe";
  if(a >= b) ans = "delicious";
  if(b - a > x) ans = "dangerous";
  cout << ans << endl;
}
