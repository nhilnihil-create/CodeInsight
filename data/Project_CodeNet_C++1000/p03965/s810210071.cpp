#include <bits/stdc++.h>
       
using namespace std;
typedef long long ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main() {
  string s;
  cin >> s;

  const int N = s.size();
  int ans = 0;
  for (int i = 0; i < (int)N; ++i) {
    if (i % 2) {
      ans += (s[i] == 'g' ? 1 : 0);
    } else {
      ans += (s[i] == 'g' ? 0 : -1);
    }
  }

  cout << ans << endl;

  return 0;
}
