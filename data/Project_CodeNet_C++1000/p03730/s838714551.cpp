#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 100100100;
const int MOD = (int)1e9 + 7;
const double EPS = 1e-9;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  vector<int> A(100);
  A[0] = a;
  REP(i, 99) { A[i + 1] = A[i] + a * (i+1); }
  REP(i, 99) for (int j = 1; j + i < 100;j++){
      if((A[i+j]-A[i])%b==c){
        puts("YES");
        return 0;
      }
  }
  puts("NO");
}