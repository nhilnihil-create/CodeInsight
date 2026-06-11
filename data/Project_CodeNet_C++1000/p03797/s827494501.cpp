#include <iostream>
using namespace std;

void solve(){
  long long n, m; cin >> n >> m;
  long long ans = 0;
  if(n*2 >= m) {
    cout << m/2 << endl;
    return;
  } else {
    ans += n;
    m -= 2 * n;
    ans += m/4;
    cout << ans << endl;
  }
}

int main(){
  solve();
  return 0;
}