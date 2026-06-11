#include <iostream>
using namespace std;
typedef long long ll;

int main() {
  ll x; cin >> x;
  ll ng=-1, ok=100000;
  while(ok - ng > 1) {
    ll md = (ng + ok) / 2;
    if (md * (md+1) / 2 >= x) ok = md;
    else ng = md;
  }
  cout << ok << endl;
}