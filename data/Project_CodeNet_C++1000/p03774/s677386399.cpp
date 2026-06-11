#include <bits/stdc++.h>
#define rep(i,a,n) for (int i = a; i < (int)(n); i++)
#define ll long long
#define INF 1e17
using namespace std;

int main() {
  int N,M; cin >> N >> M;
  ll a[N],b[N],c[M],d[M]; 
  rep(i,0,N) cin >> a[i] >> b[i];
  rep(i,0,M) cin >> c[i] >> d[i];
  
  rep(i,0,N) {
    ll ans =INF;
    int num;
    rep(j,0,M) {
      ans = min(ans,abs(a[i]-c[j])+abs(b[i]-d[j]));
    }
    rep(j,0,M) {
      if(ans == abs(a[i]-c[j])+abs(b[i]-d[j])) {
        num = j; break;
      }
    }
    cout << num + 1 << endl;
  }
}