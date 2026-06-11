#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main(){
  fastIO;
  ll a[7];
  for(int i = 0 ; i < 7; i ++ ){
    cin >> a[i];
  }
  ll res = a[1];
  ll A = a[0], B = a[3], C = a[4];
  ll bes = 0;
  ll fa, fb, fc;
  for(ll x = min({A,B,C}); x >= max(0ll, min({A,B,C}) - 500); x -- ){
    fa = A - x;
    fb = B - x;
    fc = C - x;
    fa -= fa % 2;
    fb -= fb % 2;
    fc -= fc % 2;
    bes = max(bes, fa + fb + fc + x * 3ll);
  }
  cout << res + bes << "\n";
  return 0;
}
