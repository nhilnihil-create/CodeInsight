#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i += 2)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i += 2)
int main() {
  string A;
  cin >> A;
  int N = A.size();
  string ans;
  rep(i, N) {
    ans.push_back(A.at(i));
  }
  cout << ans << endl;
}
