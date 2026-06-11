#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n); for(ll i = 0; i < (ll)n; i++)

int main() {
  ll n; cin >> n;
  vector<int> p(n+1);
  for(int i=1; i<=n; i++) cin >> p[i];
  
  int a = 1;  int cnt = 0;
  vector<bool> v(n+1,false);
  rep(i, n){
    if(a == 2)  { cout << cnt << endl; return 0; }
    if(v[a] == true)  { cout << -1 << endl; return 0; }
    v[a] = true;
    a = p[a];
    cnt++;
  }
}