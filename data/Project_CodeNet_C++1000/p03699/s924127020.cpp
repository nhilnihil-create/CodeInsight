#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
using vi  = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vi s(n);
  int sum=0;
  rep(i, n) {
    cin >> s[i];
    sum += s[i];
  }
  if (sum % 10 != 0) {
    cout << sum << endl;
    return 0;
  }
  sort(all(s));
  rep(i, n) {
    if (s[i] % 10 != 0) {
      cout << sum - s[i] << endl;
      return 0;
    }
  }
  cout << 0 << endl;
}
