#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define vi vector<int>
#define all(x) (x).begin(),(x).end()
#define INF (1<<30)-1
using ll = long long;
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(b<a) { a=b; return 1; } return 0; }

int main(){
  int n; cin >> n;
  vector<ll> a(n),b(n);
  rep(i,n) cin >> a[i] >> b[i];

  ll ans = 0;
  for(ll i = n-1; 0 <= i; i--){
    ll cnt = (a[i]+ans)%b[i];
    if(cnt) ans += b[i]-cnt;
  }
  cout << ans;
  cout << "\n";
  return 0;
}
