#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;
typedef pair<ll, ll> P;
ll Mod = 1000000007;
ll H,W;

ll Cal(ll x,ll y) {
  ll res = (x * W) + y;
  return res;
}

int main() {
  int N;
  cin >> H >> W;
  cin >> N;
  ll a[N],b[N];
  ll ans[10];
  for (int i = 0; i < 10; i++) ans[i] = 0;
  ans[0] = (H-2) * (W-2);
  unordered_map<ll,bool> mat; 
  unordered_map<ll,ll> res;
  for (int i = 0; i < N; i++) {
    cin >> a[i] >> b[i];
    a[i]--; b[i]--;
    mat[Cal(a[i],b[i])] = true;
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
            if (mat[Cal(xx,yy)]) {
              cnt++;
            }
          }
        }
        if (inside) {
          if (res[Cal(a[i]+x,b[i]+y)] == 0) {
            res[Cal(a[i]+x,b[i]+y)] = cnt;
            ans[cnt]++;
            ans[0]--;
          }
        }
      }
    }
  }

  for (int i = 0; i < 10; i++) {
    cout << ans[i] << endl;
  }
  return 0;
}