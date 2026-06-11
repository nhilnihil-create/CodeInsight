#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <iomanip>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int inf = 1<<30;
const int mod = 1e9+7;

int main() {
  int N; cin >> N;
  string s[2]; cin >> s[0] >> s[1];
  long long ans = 0LL;
  if(s[0][0] == s[1][0]) ans = 3;
  else ans = 6;
  for(int i = 1; i < N; i++) {
    if(s[0][i-1] == s[0][i]) continue;
    if(s[0][i] == s[1][i]) {
      if(s[0][i-1] == s[1][i-1]) ans *= 2;
      ans %= mod;
      continue;
    }
    if(s[0][i-1] == s[1][i-1]) ans *= 2;
    else{
      ans *= 3;
      ans %= mod;
    }
  }
  cout << ans << endl;
  return 0;
}
