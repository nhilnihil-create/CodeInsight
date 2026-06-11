#include <bits/stdc++.h>
using namespace std;

int main(){
  long long int a, b, c;
  cin >> a >> b >> c;
  
  if(a * b * c % 2 == 0) cout << 0 << endl;
  else{
    long long int ans = min(a * b, min(b * c, c * a));
    cout << ans << endl;
  }
  return 0;
}