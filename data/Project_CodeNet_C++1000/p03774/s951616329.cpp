#include<bits/stdc++.h>
#define rep(i,n)  for(ll i=0; i<n; i++)
#define vi vector<int>
#define all(x) (x).begin(),(x).end()
#define INF 1e9
using ll = long long;
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main(){
  int n,m; cin >> n >> m;
  vector<ll> a(n),b(n),c(m),d(m);
  rep(i,n) cin >> a[i] >> b[i];
  rep(i,m) cin >> c[i] >> d[i];
  rep(i,n){
    ll mn = INF;
    int ans = 0;
    rep(j,m) if(chmin(mn,abs(a[i]-c[j])+abs(b[i]-d[j]))) ans = j+1;
    cout << ans << endl;
  }
  cout << "\n";
  return 0;
}
