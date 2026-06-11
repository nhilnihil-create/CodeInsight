#include <iostream>
using namespace std;
using ll = long long;
int main(){
  ll x;
  cin >> x;
  ll ans = 0;
  ans = x/11 * 2;
  int r = x%11;
  if(r != 0){
    if(r <= 6) ans++;
    else ans += 2;
  }
  cout << ans << endl;
}
