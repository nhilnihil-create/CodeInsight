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
  for(int i = 'a'; i <= 'z'; i++) {
    if(mp[i]==0){
      char c = i;
      cout << c << endl;
      return 0;
    }
  }
  cout << "None" << endl;
}