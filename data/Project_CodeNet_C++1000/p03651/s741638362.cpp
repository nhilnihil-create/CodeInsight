#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i,s,n) for(int i = s; i < (int)(n); i++)

int GCD(int x,int y){
  if(y == 0) return x;
  return GCD(y,x%y);
}

int main() {
  int n,k;
  cin >> n >> k;
  vector<int>a(n);
  rep(i,0,n) cin >> a[i];
  sort(a.begin(),a.end());
  if(n == 1){
    if(k == 0 || k == a[0]) cout << "POSSIBLE" << endl;
    else cout << "IMPOSSIBLE" << endl;
    return 0;
  }
  int gcd = GCD(a[0],a[1]);
  rep(i,1,n) gcd = GCD(gcd,a[i]);
  if(a[n-1] >= k && k%gcd == 0) cout << "POSSIBLE" << endl;
  else cout << "IMPOSSIBLE" << endl;
}