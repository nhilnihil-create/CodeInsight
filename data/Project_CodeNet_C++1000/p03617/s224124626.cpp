#include<bits/stdc++.h>
#define PI 3.141592653589
using namespace std;
using ll = long long;

template<typename T_char>
T_char ToUpper(T_char cX){return toupper(cX);}

int main(){
  int q, h, s, d, n;
  cin >> q >> h >> s >> d >> n;

  ll cpq = q*8, cph = h*4, cps = s*2, cpd = d;
  ll mn;
  mn = min(cpd, min(cps, min(cpq, cph)));
  ll ans = (n/2) * mn + n%2 * min(4*q,min(2*h, s));
  cout << ans << endl;
}