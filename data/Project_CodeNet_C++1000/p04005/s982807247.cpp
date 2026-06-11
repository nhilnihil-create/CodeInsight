#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b, c;
  cin >> a >> b >> c;
  if(a%2==1 && b%2==1 && c%2==1){
    long long ans=0;
    ans = min (a*b, b*c);
    ans = min (ans, c*a);
    cout << ans << endl;
  }
  else cout << 0 << endl;
}

