#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
  int n;
  cin >> n;
  ll cnt = 0;
  rep(i, n) {
    int x;
    cin >> x;
    cnt += x;
  }
  if (cnt % 2 == 0)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}