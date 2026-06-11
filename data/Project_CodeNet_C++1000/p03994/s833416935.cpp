#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define SORT(c) sort((c).begin(), (c).end())
#define REVERSE(v) reverse((v).begin(), (v).end())
#define ANS(ans) cout << (ans) << endl;
#define UNIQUE(v) (v).erase(unique((v).begin(), (v).end()), (v).end());
typedef vector<int> VI;
typedef pair<int, int> P;

// repetition
//------------------------------------------
#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define REP(i, n) for (long long i = 0; i < (n); ++i)

bool can_change_a(char ch, int count) {
  int num = 26 - (ch - 'a');
  // cout << "num" << num << "k" << count << endl;
  if (num > count) {
    return false;
  } else {
    return true;
  }
}

int main() {
  string s;
  int k;

  cin >> s >> k;

  REP(i, s.size()) {
    if (s[i] == 'a') continue;
    if (can_change_a(s[i], k)) {
      k -= 26 - (s[i] - 'a');
      s[i] = 'a';
    }
  }

  k = k % 26;
  s[s.size() - 1] = s[s.size() - 1] + k;

  ANS(s);

  return 0;
}
