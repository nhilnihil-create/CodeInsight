#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPS(I, a, b) for (int i = (a); i < (b); ++i)
using namespace std;
using ll = long long;

int main() {
  int n,l;
  cin >> n >> l;
  vector<string> s(n);
  REP(i,n) cin >> s[i];
  sort(s.begin(),s.end());
  REP(i,n) cout << s[i];
  cout << endl;
}
