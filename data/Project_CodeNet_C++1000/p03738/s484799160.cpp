#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  string a, b;
  cin >> a >> b;
  if (a.size() > b.size()) cout << "GREATER" << endl;
  else if (a.size() < b.size()) cout << "LESS" << endl;
  else {
    bool finished = false;
    rep(i, a.size()) {
      if (a[i] > b[i]) {
        cout << "GREATER" << endl;
        finished = true;
        break;
      } else if (a[i] < b[i]) {
        cout << "LESS" << endl;
        finished = true;
        break;
      }
    }
    if (!finished) cout << "EQUAL" << endl; 
  }
  return 0;
}