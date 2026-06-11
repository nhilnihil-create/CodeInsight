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
  ll A, B, C;
  cin >> A >> B >> C;
  if(A%2==1||B%2==1||C%2==1){
    cout << 0 << endl;
    return 0;
  }
  if(A==B&&B==C){
    cout << -1 << endl;
    return 0;
  }
  ll ans = 0;
  while(A%2==0&&B%2==0&&C%2==0){
    ll a = A / 2, b = B / 2, c = C / 2;
    A =  b  + c ;
    B =  a  + c ;
    C =  a  + b ;
    ans++;
  }
  cout << ans << endl;
}