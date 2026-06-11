#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); ++i)
using namespace std;
typedef long long ll;

int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  rep(i,n) a[i]--;
  set<int> s;
  vector<int> idx(n);
  rep(i,n) idx[a[i]] = i;
  ll ans = 0;
  rep(x,n){
    int i =idx[x];
    int l=-1;
    int r=n;
    ll c=0;
    s.insert(i);
    { // calc l
      auto it = s.find(i);
      if(it!=s.begin()){
        --it;
        l = *it;
      }
    }
    { // calc l
      auto it = s.find(i);
      ++it;
      if(it!=s.end()){
        r = *it;
      }
    }
    c += (ll)(i-l)*(ll)(r-i);
    ans += c*(x+1);
  }
  cout << ans << endl;
  return 0;
}