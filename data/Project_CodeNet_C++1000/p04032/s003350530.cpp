#include <bits/stdc++.h>
       
using namespace std;
typedef long long ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main() {
  string s;
  cin >> s;

  int N = s.size();
  for (int i = 0; i < (int)N; ++i) {
    if (i + 1 < N && s[i] == s[i + 1]) {
      cout << i + 1 << " " << i + 2 << endl;
      return 0;
    }

    if (i + 2 < N && s[i] == s[i + 2]) {
      cout << i + 1 << " " << i + 3 << endl;
      return 0;
    }
  }

  cout << -1 << " " << -1 << endl;
  return 0;
}
