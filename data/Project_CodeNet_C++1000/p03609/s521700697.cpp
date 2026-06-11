#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
const double PI = 3.14159265358979323846;

int main() {
  int x, t;
  cin >> x >> t;
  int ans = 0;
  if(t>= x) ans = 0;
  
  else ans = x-t;
  cout << ans << endl;
}