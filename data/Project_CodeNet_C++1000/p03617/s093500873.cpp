#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  ll Q, H, S, D;
  long double N;
  cin >> Q >> H >> S >> D >> N;
  ll a = min(2*Q,H);//0.5l最安
  ll b = min(S,2*a);//1l最安
  ll c = min(D,2*b);//2l最安
  ll x = N/2;
  ll y = (ll)N%2;
  ll z = (ll)(N*100)%100/50;
  ll xx = (ll)(N*100)%50/25;

  cout << c*x+b*y+a*z+Q*xx << endl;
  return 0;
}