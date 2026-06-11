#include <bits/stdc++.h>
using namespace std;

int main(){
  long long q, h, s, d, n;
  cin >> q >> h >> s >> d >> n;
  
  if(2*q < h) h = 2*q;
  if(2*h < s) s = 2*h;
  if(2*s < d) d = 2*s;
  
  long long ans = 0;
  ans += n/2 * d + n%2 * s;
  
  cout << ans << endl;
}