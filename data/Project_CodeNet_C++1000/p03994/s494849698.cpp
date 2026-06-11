#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
int main() {
  string s;
  ll K;
  cin >> s >> K;
  REP(i, s.size()) {
    if (K == 0) break;
    if (s[i] == 'a') continue;
    if ('z' - s[i] + 1 <= K) {
      K -= 'z' - s[i] + 1;
      s[i] = 'a';
    }
  }
  K %= 26;
  s[s.size() - 1] += K;
  K = 0;
  if ('z' < s[s.size() - 1]) s[s.size() - 1] -= 26;
  REP(i, s.size()) cout << s[i];
  cout << endl;
}