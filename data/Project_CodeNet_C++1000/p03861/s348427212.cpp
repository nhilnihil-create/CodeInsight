#include <bits/stdc++.h>

using namespace std;
using ll = long long;


// count 0...n divisible by x
ll f(ll n, ll x) {
  if (n<0) return 0;
  return  n/x + 1;
}

int main() {
  ll a,b,x;
  cin>>a>>b>>x;
  cout<<f(b,x)-f(a-1,x);
  return 0;
}