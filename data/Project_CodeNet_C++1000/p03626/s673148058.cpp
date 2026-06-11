#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const double PI = acos(-1);
const ll MOD = 1000000007;
using Graph = vector<vector<int>>;

int main() {
  int N; cin >> N;
  string u,d; cin >> u >> d;
  
  ll ans = 1;
  for (int i = 0; i < N;) {
    if (u[i] == d[i]) {
     if (i == 0) ans *= 3;
     else {
       if (u[i-1] == d[i-1]) ans = ans * 2 % MOD;
     }
     i++;
    } else {
      if (i == 0) ans *= 6;
      else {
        if (u[i-1] == d[i-1]) ans = ans * 2 % MOD;
        else ans = ans * 3 % MOD;
      }
      i += 2;
    }
  }

  cout << ans << endl;
}