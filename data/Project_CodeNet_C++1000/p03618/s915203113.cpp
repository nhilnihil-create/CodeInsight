// review
#include <iostream>

using namespace std;
typedef long long ll;

string s;

ll cnt[26];

void solve() {
  for (int i=0;i<s.size();i++) {
    cnt[s[i] - 'a']++;
  }
  ll ans = 0;
  for (int i=0;i<26;i++) {
    ans += cnt[i] * (cnt[i]-1) / 2;
  }
  cout << (s.size() * (s.size() - 1) / 2 - ans + 1) << endl;
}

int main() {
  cin >> s;
  solve();
}
