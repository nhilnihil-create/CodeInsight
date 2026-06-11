#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int h, w;
  cin >> h >> w;
  rep(j, w+2) cout << "#";
  cout << endl;
  rep(i, h) {
    string a;
    cin >> a;
    cout << "#" << a << "#" << endl;
  }
  rep(j, w+2) cout << "#";
  cout << endl;
}
