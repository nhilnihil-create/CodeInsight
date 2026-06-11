#include <bits/stdc++.h>
using namespace std;
#define rep(i, a) for(int i=0; i<(a); i++)
typedef long long ll;

int main()
{
  ll q,h,s,d; cin>>q>>h>>s>>d;
  ll n; cin >> n;

  ll t = 8*q;
  t = min(t, 4*h);
  t = min(t, 2*s);
  t = min(t, d);
  ll u = min(4*q, 2*h);
  u = min(u, s);

  cout << (n/2)*t + (n%2)*u << endl;

  return 0;
}
