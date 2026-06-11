#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define all(vec) vec.begin(),vec.end()
using ll = long long;

int main() {
  ll A, B, X; cin >> A >> B >> X;
  ll ans;
//  if (X > B) ans = 0;
  ans = B/X - A/X;
  if(A%X == 0) ans++;  
  cout << ans << endl;
  return 0;
}