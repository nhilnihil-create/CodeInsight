#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){

  ll x;
  cin >> x;
  ll cnt  = 0;

  if (x >= 11) {
    cnt = (x/11)*2;
    x %= 11;
  }
  if ( 6 < x ) {
    cnt++;
    x -= 6;
  }

  if ( 0 < x && x <= 6 ) {
    cnt++;
    x = 0;
  }

  cout << cnt << endl;



}
