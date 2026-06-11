#include <bits/stdc++.h>
using namespace std;

int main(){
  long long n; cin >> n;
  long long ans = 2*(n/11);
  long long res = n - ans*11/2;
  if(0 < res && res <= 6) ans++;
  else if(res > 6) ans += 2;
  cout << ans << endl;
}
