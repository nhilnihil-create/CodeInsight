#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  string S;
  cin >> S;
  ll num[26];
  for (int i = 0; i < 26; i++) num[i] = 0; 
  int N = (int)S.size();
  for (int i = 0; i < N; i++) {
    num[S[i] - 'a']++;
  }
  ll ans = 1;
  ans += (N * (N-1LL)) / 2LL;
  for (int i = 0; i < 26; i++) {
    if (num[i] <= 1) {
      continue;
    }
    ans -= (num[i] * (num[i]-1LL)) / 2LL;
  }
  cout << ans << endl;
  return 0;
}