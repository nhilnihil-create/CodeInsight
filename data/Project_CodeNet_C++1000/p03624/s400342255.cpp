#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main()
{
  string s; cin >> s;

  int bucket[26] = {0};
  char ans;
  bool is_all = true;
  bool is_fetched = false;

  rep(i, s.size()) {
    bucket[s[i]-'a'] += 1;
  }
  rep(i, 26) {
    if (!bucket[i] && !is_fetched) {
      ans = i+97;
      is_all = false;
      break;
    }
  }

  if (is_all) {
    cout << "None" << endl;
  } else {
    cout << ans << endl;
  }
  return 0;
}