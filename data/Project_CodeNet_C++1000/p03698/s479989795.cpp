#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 100100100;
const int MOD = (int)1e9 + 7;
const double EPS = 1e-9;
struct Edge {
  ll to;
  ll cost;
};
int main() {
  string S;
  cin >> S;
  map<char, int> mp{};
  REP(i, S.size()) { mp[S[i]]++; }
  bool t = true;
  for(auto s : mp){
    if (mp[s.first] != 1) t = false;
  }
  if (t) cout << "yes" << endl;
  else
    cout << "no" << endl;
}