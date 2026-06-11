#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using P = pair<i64, i64>;

#define overload3(_1, _2, _3, name, ...) name
#define rep1(i, n) for(i64 i = 0LL; i < (n); ++i)
#define rep2(i, a, b) for(i64 i = (a); i < (b); ++i)
#define rep(...) overload3(__VA_ARGS__, rep2, rep1)(__VA_ARGS__)
#define all(v) v.begin(), v.end()

struct IoSetup {
    IoSetup() {
        // cin.tie(nullptr);
        // ios::sync_with_stdio(false);
        cout << fixed << setprecision(10);
        cerr << fixed << setprecision(10);
    }
} iosetup;

vector< vector< int64_t > > get_combination(int N)
{
  vector< vector< int64_t > > mat(N + 1, vector< int64_t >(N + 1));
  for(int i = 0; i <= N; i++) {
    for(int j = 0; j <= i; j++) {
      if(j == 0 || j == i) mat[i][j] = 1;
      else mat[i][j] = mat[i - 1][j - 1] + mat[i - 1][j];
    }
  }
  return (mat);
}

using int64 = long long;

int64 mod_pow(int64 x, int64 n)
{
  int64 ret = 1;
  while(n > 0) {
    if(n & 1) (ret *= x);
    (x *= x);
    n >>= 1;
  }
  return ret;
}


int main(){
    i64 n, p;
    cin >> n >> p;
    vector<i64> a(n);
    rep(i, n) cin >> a[i];
    i64 d = 0, b = 0;
    rep(i, n){
        if(a[i] % 2 == 1) d++;
        else b++;
    }
    auto comb = get_combination(n);
    i64 ans;
    if(p == 1){
        ans = 0;
        for(int i = 1; i <= d; i += 2) ans += comb[d][i];
        ans *= mod_pow(2, b);
    }else{
        ans = 0;
        for(int i = 0; i <= d; i += 2) ans += comb[d][i];
        ans *= mod_pow(2, b);
    }
    cout << ans << endl;
}
