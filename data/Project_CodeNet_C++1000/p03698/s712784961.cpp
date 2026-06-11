#include <bits/stdc++.h>
#define rep(i, f, n) for (ll i = (f); i < (ll)(n); i++)
#define repe(i, f, n) for (ll i = (f); i <= (ll)(n); i++)
using namespace std;
using ll = long long;
using GraphI = vector<vector<int>>;
using GraphC = vector<vector<char>>;
using pint = pair<int, int>;

int main() {
  string S;
  cin >> S;
  int n = S.size();
  sort(S.begin(), S.end());
  char p = S[0];
  rep(i, 1, n) {
    if (p == S[i]) {
      cout << "no" << endl;
      return 0;
    }
    p = S[i];
  }

  cout << "yes" << endl;
  return 0;
}
