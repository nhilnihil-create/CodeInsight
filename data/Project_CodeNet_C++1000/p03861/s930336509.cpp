#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  ll a, b, x;
  cin >> a >> b >> x;
  ll l, u;
  if(a == 0) l = -1;
  else l = (a-1)/x;
  u = b/x;
  cout << u - l <<endl;
}