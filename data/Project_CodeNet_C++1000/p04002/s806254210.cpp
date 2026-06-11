#include <iostream>
#include <map>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

#define rep(i,n) for(int i=0;i<(n);++i)
#define iter(it,v) for(auto it=v.begin();it!=v.end();++it)
#define in(v) cin>>v;
#define out(v) cout<<v<<"\n"

int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  int H, W, N;
  in(H); in(W); in(N);

  map<pii, int> m;
  rep(i, N) {
    int a; in(a);
    int b; in(b);
    rep(x, 3) {
      if (a - x <= 0 || a - x > H - 2)
        continue;
      rep(y, 3) {
        if (b - y <= 0 || b - y > W - 2)
          continue;
        ++m[pii(a - x, b - y)];
      }
    }
  }
  ll res[10];
  rep(i, 10) res[i] = 0;
  iter(it, m) {
    ++res[it->second];
  }
  res[0] = (ll)(W-2) * (H-2) - m.size();
  rep(i, 10) {
    out(res[i]);
  }

  return 0;
}
