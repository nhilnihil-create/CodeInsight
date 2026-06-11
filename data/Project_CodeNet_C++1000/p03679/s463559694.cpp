#include <bits/stdc++.h>
#define rep(i,a,n) for(int i =a; i<n; i++) 
#define ll long long
using namespace std;

int main() {
  ll X,A,B; cin >> X >> A >> B;
  string ans;
  if (A - B >=0 ) ans = "delicious";
  else if (B - A > X) ans = "dangerous";
  else ans = "safe";
  cout << ans << endl;
}