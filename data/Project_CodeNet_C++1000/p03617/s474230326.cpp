#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  ll Q, H, S, D;
  ll N;
  cin >> Q >> H >> S >> D >> N;
  ll a = min(2*Q,H);
  ll b = min(S,2*a);
  ll c = min(D,2*b);
  ll x = N/2;
  ll y = N%2;

  cout << c*x+b*y << endl;
  return 0;
}