#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; ++i)
#define FOR(i, b, n) for (int i = b; i < n; ++i)

using namespace std;
using ll = long long;
using P = pair<int, int>;

void solve(int N, string S) {
  auto itr = S.begin();
  int l(0), r(0);
  REP(i, N) {
    if (S[i] == '(')
      l++;
    else
      r++;

    if (l < r) {
      S.insert(S.begin(), '(');
      i++;
      N++;
      l++;
     }
  }
  REP(i, l - r)
    S.insert(S.end(), ')');
 
  cout << S << endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N;
  string S;
  cin >> N >> S;

  solve(N, S);

  return 0;
}
