#include <bits/stdc++.h>
using namespace std;

int main(){
  long long int n, a, b;
  cin >> n >> a >> b;
  if(a > b) cout << 0 << endl;
  else if(n == 1){
    if(a == b) cout << 1 << endl;
    else cout << 0 << endl;
  }
  else {
    long long int ans = (n - 2) * b - (n - 2) * a + 1;
    cout << ans << endl;
  }
  return 0;
}
