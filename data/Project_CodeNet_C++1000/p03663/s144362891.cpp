#include <iostream>
#define INF 10000000000LL
using namespace std;
typedef long long ll;

bool query(ll n) {
  cout << "? " << n << endl;
  string res;
  cin >> res;
  return res == "Y";
}

int main(void) {
  ll d = 1;

  while(d <= INF && query(d)) d *= 10;
  d /= 10;

  if(d == INF) {
    d = 1;
    while(!query(d * 10 - 1)) d *= 10;
    cout << "! " << d << endl;
  } else {
    ll l = d;
    ll r = d * 10;
    while(r - l > 1) {
      ll m = (r + l) / 2;
      if(query(m * 10)) r = m;
      else l = m;
    }
    cout << "! " << r << endl;
  }

  return 0;
}
