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
  set<char> s;
  rep(i, 0, n) s.insert(S[i]);

  if (n == s.size())
    cout << "yes" << endl;
  else
    cout << "no" << endl;

  return 0;
}
