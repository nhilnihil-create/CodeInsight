#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  int N,Ma,Mb;
  cin >> N >> Ma >> Mb;
  int a[N],b[N],c[N];
  for (int i = 0; i < N; i++) {
    cin >> a[i] >> b[i] >> c[i];
  }
  if (N <= 20) {
    int ans = 999999;
    for (int bit = 1; bit < (1 << N); bit++) {
      int a1 = 0;
      int b1 = 0;
      int money = 0;
      for (int i = 0; i < N; i++) {
        if (bit & (1 << i)) {
          a1 += a[i];
          b1 += b[i];
          money += c[i];
        }
      }
      int gc = __gcd(a1,b1);
      a1 /= gc;
      b1 /= gc;
      if (Ma == a1 && Mb == b1) {
        ans = min(ans,money);
      }
    }
    if (ans > 900000) {
      cout << -1 << endl;
    } else {
      cout << ans << endl;
    }
  } else {
    int DP[201][201];
    int ans = 999999;
    for (int i = 0; i <= 200; i++) {
      for (int j = 0; j <= 200; j++) {
        DP[i][j] = 999999;
      }
    }
    for (int bit = 0; bit < (1 << 20); bit++) {
      int a1 = 0;
      int b1 = 0;
      int money = 0;
      for (int i = 0; i < 20; i++) {
        if (bit & (1 << i)) {
          a1 += a[i];
          b1 += b[i];
          money += c[i];
        }
      }
      DP[a1][b1] = min(DP[a1][b1] , money);
    }
    for (int bit = 0; bit < (1 << 20); bit++) {
      int a2 = 0;
      int b2 = 0;
      int money2 = 0;
      for (int i = 0; i < N-20; i++) {
        if (bit & (1 << i)) {
          a2 += a[i+20];
          b2 += b[i+20];
          money2 += c[i+20];
        }
      }
      for (int i = 1; i <= 420; i++) {
        if (0 <= (Ma * i) - a2 && (Ma * i) - a2 <= 200 && 0 <= (Mb * i) - b2 && (Mb * i) - b2 <= 200) {
          ans = min(ans , DP[(Ma * i) - a2][(Mb * i) - b2] + money2);
        }
      }
    }
    if (ans > 900000) {
      cout << -1 << endl;
    } else {
      cout << ans << endl;
    }
  }
  return 0;
}