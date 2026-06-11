#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
  string A, B;
  cin >> A >> B;
  int X = A.size();
  int Y = B.size();
  int co = 0;
  if(X > Y) {
    cout << "GREATER" << endl;
  }
  else if(X < Y) {
    cout << "LESS" << endl;
  }
  else {
    rep(i, X) {
      if(A.at(i) > B.at(i)) {
        cout << "GREATER" << endl;
        break;
      }
      else if(A.at(i) < B.at(i)) {
        cout << "LESS" << endl;
        break;
      }
      else {
        co++;
      }
    }
  }
  if(co == X) {
    cout << "EQUAL" << endl;
  }
}
