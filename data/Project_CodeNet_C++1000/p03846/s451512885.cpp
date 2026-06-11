#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef vector<vector<int>> Matrix;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define ALL(x) (x).begin(), (x).end()
static const int INF = 2000000000;

const int mod = 1000000007;

ll mypow(int x){
  ll ret = 1;
  rep(i, x) ret = ret * 2 % mod;
  return ret;
}

int main(){
  int n;
  cin >> n;
  map<int, int> d;
  rep(i, n){
    int s;
    cin >> s;
    d[s]++;
  }

  bool ok = true;
  if (n % 2) {
    if (d[0] != 1) ok = false;
    for (int i = 2; i < n; i+=2) {
      if (d[i] != 2) ok = false;
    }
  } else {
    if (d[0] != 0) ok = false;
    for (int i = 1; i < n; i+=2){
      if (d[i] != 2) ok = false;
    }
  }

  if (ok) {
    ll ans = mypow(n/2);
    cout << ans << endl;
  } else {
    cout << 0 << endl;
  }
}