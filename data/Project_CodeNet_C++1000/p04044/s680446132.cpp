#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using p = pair<int, int>;
typedef vector<int> vi;

int main() {
  int N, L;
  string S[110];
  string tmp;

  cin >> N >> L;
  rep(i, N) cin >> S[i];

  sort(S, S+N);

  tmp = S[0];

  for(int i=1; i < N; i++) {
    tmp += S[i];
  }

  cout << tmp << endl;

  return 0;
}