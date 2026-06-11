#include<bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;

int main() {
  int n;
  cin >> n;
  
  int ans = 0;
  vector<int> t(n);
  rep(i,n) cin >> t[i];
  
  int m;
  cin >> m;
  vector<pair<int,int>> px(m);
  rep(i,m) {
    cin >> px[i].first >> px[i].second;
    px[i].first--;
  }
  
  for (auto g : px) {
    int k = t[g.first];
    t[g.first] = g.second;
    
    int ans = 0;
    rep(i,n) ans += t[i];
    cout << ans << endl;
    
    t[g.first] = k;
  }
}