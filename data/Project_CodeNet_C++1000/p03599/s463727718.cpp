#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;


int main() {
  int a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;
  int ans_ws = 100*a, ans_s = 0;
  rep(i, 31){
    rep(j, 31){
      int w = 100*a*i + 100*b*j;
      if(w == 0) continue;
      rep(ii, f/c+1){
        rep(jj, f/c+1){
          int s = c*ii + d*jj;
          if(s*100 <= e*w && s+w <=f 
            && s*ans_ws > ans_s*(w+s)){
            ans_ws = w+s;
            ans_s = s;
          }
        }
      }
    }
  }
  cout << ans_ws << " " << ans_s << endl;
}
