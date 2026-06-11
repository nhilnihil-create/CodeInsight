#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;
typedef pair<ll, ll> P;
ll Mod = 1000000007;
int main() {
  ll H,W;
  int N;
  cin >> H >> W;
  cin >> N;
  ll a[N],b[N];
  ll ans[10];
  for (int i = 0; i < 10; i++) ans[i] = 0;
  ans[0] = (H-2) * (W-2);
  map<P,bool> mat; 
  map<P,ll> res;
  for (int i = 0; i < N; i++) {
    cin >> a[i] >> b[i];
    a[i]--; b[i]--;
    mat[make_pair(a[i],b[i])] = true;
  }
  for (int i = 0; i < N; i++) {
    for (int x = -2; x <= 0; x++) {
      for (int y = -2; y <= 0; y++) {
        bool inside = true;
        int cnt = 0;
        for (int j = 0; j < 3; j++) {
          for (int k = 0; k < 3; k++) {
            ll xx = a[i] + x + j;
            ll yy = b[i] + y + k;
            if (0 <= xx && xx < H && 0 <= yy && yy < W) {
              
            } else {
              inside = false;
            }
            if (mat[make_pair(xx,yy)]) {
              cnt++;
            }
          }
        }
        if (inside) {
          res[make_pair(a[i]+x,b[i]+y)] = cnt;
        }
      }
    }
  }

  for (auto p : res) {
    ans[p.S]++;
    ans[0]--;
  }

  for (int i = 0; i < 10; i++) {
    cout << ans[i] << endl;
  }
  return 0;
}