#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<string,int>;
const double PI = acos(-1);

int main() {
  int n;
  cin >> n;
   vector<ll> t(n);
   ll ans = 1;
   rep(i,n) cin >> t.at(i);

   rep(i,n){
     ans = lcm(t.at(i),ans);
   }
   cout << ans << endl;
}