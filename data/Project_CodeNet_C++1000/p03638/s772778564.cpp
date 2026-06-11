#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int h,w,n;
  cin >> h >> w >> n;

  int T[110][110];
  
  int curh = 0, curw = 0;
  rep(i, n) {
    int a; cin >> a;

    while(a > 0) {
      if(curh % 2 == 0) {
        T[curh][curw] = i + 1;
        curw++;
        a--;
  
        if(curw == w) {
          curh++;
          curw--;
        }
      } else {
        T[curh][curw] = i + 1;
        curw--;
        a--;
  
        if(curw == -1) {
          curh++;
          curw++;
        }
      }
    }
  }

  rep(i, h) {
    rep(j, w) {
      cout << T[i][j];
      if(j != w - 1) cout << " ";
    }
    cout << endl;
  }

  return 0;
}
