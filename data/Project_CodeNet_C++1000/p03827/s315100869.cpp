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
  int N;
  cin >> N;
  string S;
  cin >> S;
  int mx = 0;
  int num = 0;
  REP(i,S.size()){
    if(S[i]=='I'){
      num++;
    }else{
      num--;
    }
    mx = max(mx, num);
  }
  cout << mx << endl;
}