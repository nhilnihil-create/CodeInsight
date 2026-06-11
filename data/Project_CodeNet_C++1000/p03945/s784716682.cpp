#include <bits/stdc++.h>
#define rep2(i,m,n) for (int i = (int)(m); i < (int)(n); i++)
#define rep(i,n) rep2(i,0,n)
#define all(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
using namespace std;
using ll = long long;
template <typename T>
T sq(T x){
  return x * x;
}

signed main (){
  string s;
  cin >> s;
  int pre = s.at(0);
  int ans = 0;
  for (int i = 0; i < SZ(s);i++) {
    int now = s.at(i);
    if (now != pre){
ans ++;
    }
    pre = s.at(i);
    }
  cout << ans << endl;
    return 0;
}
