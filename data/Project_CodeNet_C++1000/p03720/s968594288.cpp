#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> vec(n);
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    vec.at(a)++;
    vec.at(b)++;
  }
  rep(i, n) cout << vec.at(i) << endl;
}
