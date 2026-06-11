#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main () {
  ll a, b, x, ans = 0;
  cin >> a >> b >> x;
  
  ans = b/x-a/x;
  if (a%x == 0) {
    ans ++;
  }
  
  cout << ans << endl;
}