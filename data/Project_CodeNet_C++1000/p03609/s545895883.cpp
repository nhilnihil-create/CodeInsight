#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define ll long long
#define rep(i, a, b) for(ll i = (ll)a; i < (ll)b; i++)
using namespace std;

int main() {
  int x, t;
  cin >> x >> t;
  if(x > t) cout << x -t << "\n";
  else cout << 0 << "\n";
}
