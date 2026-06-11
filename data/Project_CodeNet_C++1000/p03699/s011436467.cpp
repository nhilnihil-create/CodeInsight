#include <bits/stdc++.h>
#define rep(i,a,n) for (int i =a; i<n; i++) 
using namespace std;

int main() {
  int N; cin >> N;
  int s[N], total =0, a =100, ans; 
  rep(i,0,N) {
    cin >> s[i]; total += s[i];
    if (s[i] % 10 != 0) a = min(a,s[i]);
  }
  
  if (total % 10 == 0) {
    if (a % 10 == 0) ans = 0;
    else ans = total - a;
  } else {
    ans = total;
  }
  cout << ans << endl;
}