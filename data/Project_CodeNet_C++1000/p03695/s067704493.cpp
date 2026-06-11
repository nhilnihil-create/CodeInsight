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
  vector<int> A(8);
  int over3200 = 0;
  bool t = false;
  REP(i, N) {
    int a;
    cin >> a;
    if(a<3200){
      A[a / 400]++;
      t = true;
    }else{
      over3200++;
    }
  }
  if(!t){
    over3200--;
    A[0]++;
  }
  int ans = 0;
  REP(i, 8) ans += A[i] != 0 ? 1 : 0;
  cout << ans << " " << ans + over3200 << endl;
}