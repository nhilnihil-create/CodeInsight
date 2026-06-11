#include <iostream>
#include <string>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main(int argc, char const *argv[]) {
  int n, m;
  cin >> n >> m;
  string a[n];
  string b[m];
  rep(i, n) cin >> a[i];
  rep(i, m) cin >> b[i];

  bool flag = false;
  if (n != m) {
    rep(i, n - m) {   //マスクを縦方向に動かす
      rep(j, n - m) { //マスクを横方向に動かす
        rep(k, m) {   // check
          string tmp;
          tmp = a[i + k].substr(j, m);
          if (tmp == b[k])
            flag = true;
          else {
            flag = false;
            break;
          }
        }
        if (flag) {
          cout << "Yes" << endl;
          return 0;
        }
      }
    }
  } else {
    rep(i, n) {
      if (a[i] == b[i])
        flag = true;
      else {
        flag = false;
        break;
      }
    }
    if (flag) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}
