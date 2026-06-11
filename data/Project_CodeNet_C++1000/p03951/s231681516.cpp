#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int N;
string s, t;

int solve() {
  for(int i = 0; i < N; i++) {
    if(s.substr(i) == t.substr(0, N-i)){
      return i+N;
    }
  }
  return N*2;
}

int main() {
  cin >> N;
  cin >> s >> t;
  cout << solve() << endl;
  return 0;
}
