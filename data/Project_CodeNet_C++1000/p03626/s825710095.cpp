#include <cassert>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef long long ll;
const int EMPTY = 0;
const int VERT = 1;
const int HORI = 2;
const int MOD = 1000000007;

int main() {
  int n;
  cin >> n;
  string s1, s2;
  cin >> s1;
  cin >> s2;

  ll ans = 1;
  int type = EMPTY;
  int pos = 0;
  int pos_bef;
  while (pos < n) {
    pos_bef = pos;
    if (s1[pos] == s2[pos]) {
      ans *= (3-type);
      type = VERT;
      ++pos;
    }
    else {
      if (type == HORI) { 
        ans *= 3;
      }
      else {
        ans *= (3-type) * (2-type);
      }
      type = HORI;
      pos += 2;
    }
    // cout << s1[pos_bef] << " " << ans << endl;
    ans %= MOD;
  }
  cout << ans << endl;
}

