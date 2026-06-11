#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
using namespace std;
#define ll long long
#define ALL(x) begin(x),end(x)
  
int main(){
  ll n,l; cin >> n >> l;
  vector<string> s(n);
  rep(i,n) cin >> s[i];
  sort(ALL(s));
  rep(i,n) cout << s[i];
  cout << endl;
}