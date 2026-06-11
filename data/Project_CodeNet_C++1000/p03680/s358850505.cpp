#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) {
    cin >> a.at(i);
    a.at(i)--;
  }
  int x = 0, j = -1;
  rep(i, n) {
    x = a.at(x);
    if (x == 1) {
      j = i + 1;
      break;
    }
  };
  cout << j << endl;
}
