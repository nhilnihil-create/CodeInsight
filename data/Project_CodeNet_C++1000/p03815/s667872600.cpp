#include <iostream>
using namespace std;

void solve(){
  long long x; cin >> x;
  long long ans = x/11;
  ans *= 2;
  x%=11;
  if(x == 0)cout << ans << endl;
  else if(x <=6) cout << ans + 1 << endl;
  else cout << ans + 2 << endl;
  
}

int main(){
  solve();
  return 0; 
}