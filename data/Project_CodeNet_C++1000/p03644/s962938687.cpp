#define _GLIBCXX_DEBUG //エラーを出すためのおまじない
#include <bits/stdc++.h>
using namespace std;
#define coYES cout << "YES" << endl
#define coNO cout << "NO" << endl
#define coYes cout << "Yes" << endl
#define coNo cout << "No" << endl
#define coyes cout << "yes" << endl
#define cono cout << "no" << endl
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int n;
  cin >> n;
  int max = -1;
  int max_num = -1;
  rep(i, n) {
    //cout << i << endl;
    int k = i+1;
    int count = 0;
    int kk = i+1;
    rep(j, 100000) {
      if (k % 2 == 1) {
        break;
      }
      k /= 2;
      count++;
    }
    //cout << count << endl;
    if (count > max) {
      max = count;
      max_num = kk;
    }
    //cout << max << " " << max_num << endl;
  }
  cout << max_num << endl;
}
