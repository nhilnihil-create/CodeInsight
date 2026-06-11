#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, a, b) for (int i= (a); i < (b); ++i)
typedef long long ll;
typedef pair<int,int> P;
const int INF = 100100100;
const int MOD = (int)1e9 + 7;
const double EPS = 1e-9;
int main() { int ans = 0;
  map<int, int> A{};
  REP(i, 3) { int t;
    cin >> t;
    if(A[t]==0){
      ans++;
    }
    A[t] = 1;
 }
 cout << ans << endl;
}