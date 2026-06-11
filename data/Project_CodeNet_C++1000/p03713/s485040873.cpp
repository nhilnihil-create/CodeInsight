#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll ans = 1000000000;

void search1(ll tate, ll yoko) {
  for (ll i = 1; i < yoko; i++) {
    vector<ll> S(3);
    S[0] = tate*i;
    if (tate % 2 == 0) {
      S[1] = tate*(yoko-i)/2;
      S[2] = tate*(yoko-i)/2;
    }
    else {
      S[1] = tate/2*(yoko-i);
      S[2] = (tate+1)/2*(yoko-i);
    }
    sort(S.begin(), S.end());
    if (S[2]-S[0] < ans) ans = S[2]-S[0];
  }
}

void search2(ll tate, ll yoko) {
  vector<ll> S(3);
  S[0] = yoko*(tate/3);
  S[1] = yoko*((tate+1)/3);
  S[2] = yoko*((tate+2)/3);
  if (S[2]-S[0] < ans) ans = S[2]-S[0];
}

int main() {
  ll H, W;
  cin >> H >> W;
  if (H % 3 == 0 || W % 3 == 0) ans = 0;
  else {
    search1(H, W);
    search1(W, H);
    search2(H, W);
    search2(W, H);
  }
  cout << ans << endl;
}
