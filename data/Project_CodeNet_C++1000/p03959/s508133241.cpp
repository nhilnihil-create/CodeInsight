#include <bits/stdc++.h>
using namespace std;
using lint = long long;
const lint MOD = 1e9+7;

signed main(){
  lint n; cin >> n ;
  vector<lint> a(n), b(n);
  for(int i = 0; i < n; i++) cin >> a[i];
  for(int i = 0; i < n; i++) cin >> b[i];
  vector<pair<bool, int> > data1(n), data2(n);
  data1[0] = make_pair(true, a[0]);
  data2[n - 1] = make_pair(true, b[n - 1]);
  for(int i = 1; i < n; i++){
    if(a[i] == a[i - 1]) data1[i] = make_pair(false, a[i]);
    else data1[i] = make_pair(true, a[i]);
  }
  for(int i = n -2; i >= 0; i--){
    if(b[i] == b[i + 1]) data2[i] = make_pair(false, b[i]);
    else data2[i] = make_pair(true, b[i]);
  }
  bool ok = true;
  lint ans = 1;
  if(a[n - 1] != b[0]) ok = false;
  for(int i = 0; i < n; i++){
    bool a = data1[i].first, b = data2[i].first;
    lint c = data1[i].second, d = data2[i].second;
    if(a && b) if(c != d) ok = false;
    if(a && !b) if(c > d) ok = false;  
    if(!a && b) if(c < d) ok = false;
    if(!a && !b) ans *= min(c, d), ans %= MOD;
  }
  //for(int i = 0; i < n; i++) cout << data1[i].first << " " << data1[i].second << endl;
  if(ok) cout << ans << endl;
  else cout << 0 << endl;
}