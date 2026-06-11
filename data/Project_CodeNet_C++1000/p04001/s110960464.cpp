#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
using vi  = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;

int main() {
  string s;
  cin >> s;
  const int n = s.size()-1;
  int64_t sum = 0;

  rep(i, 1<<n) {
    bitset<10> bit(i);
    int64_t curr = s[0] - '0';
    rep(j, n) {
      if (bit[j] == 1) {
        sum += curr;
        curr = s[j+1] - '0';
      }
      else {
        curr *= 10;
        curr += s[j+1] - '0';
      }
    }
    sum += curr;
  }
  cout << sum << endl;
}
