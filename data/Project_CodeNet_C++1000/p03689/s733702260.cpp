#include <bits/stdc++.h>

using namespace std;

#define SZ(x) (int)(x.size())

using ll = long long;
using ld = long double;
using P = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
const double eps = 1e-10;
const int MOD = 1000000007;
const int INF = 1000000000;
const ll LINF = 1ll<<50;

template<typename T>
void printv(const vector<T>& s) {
  for(int i=0;i<(int)(s.size());++i) {
    cout << s[i];
    if(i == (int)(s.size())-1) cout << endl;
    else cout << " ";
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);

  ll H, W, h, w; cin >> H >> W >> h >> w;
  ll tmp = INF / (h * w) - 1;
  vvll ans(H, vll(W, tmp));
  ll su = H * W * tmp;
  for(int i=h-1;i<H;i += h) {
    for(int j=w-1;j<W;j += w) {
      //cout << "A" << endl;
      ans[i][j] = - (h * w - 1) * tmp - 1;
      //ans[i][j] = -1;
      su -= (h * w - 1) * tmp + 1 + tmp;
    }
  }
  //cout << su << endl;

  if(su <= 0) {
    cout << "No" << endl;
  } else {
    cout << "Yes" << endl;
    for(int i=0;i<H;++i) {
      printv(ans[i]);
    }
  }
}
