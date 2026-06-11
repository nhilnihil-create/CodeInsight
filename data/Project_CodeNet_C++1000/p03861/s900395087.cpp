#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1000000007;

int main() {
  ll a,b,x;
  cin >> a >> b >> x;
  ll c=a/x;
  ll d=b/x;
  if(a%x!=0)
  c=c+1;
  cout << d-c+1 << endl;
}

