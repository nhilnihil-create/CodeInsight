#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
  ll a, b, x;
  cin >> a >> b >> x;
  ll ans = b/x-(a+(x-1))/x+1;
  cout << ans <<endl;
}