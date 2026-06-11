#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N;
  ll INF = 1e15;
  cin >> N;
  vector< vector<ll> > a(N, vector<ll>(N, INF));
  vector< vector<ll> > need(N, vector<ll>(N, true));

  for(int i=0;i<N;i++) {
    for(int j=0;j<N;j++) {
      cin >> a[i][j];
    }
  }

  ll sub = 0;
  for(int k=0;k<N;k++) {
    for(int i=0;i<N;i++) {
      for(int j=0;j<N;j++) {
        if(a[i][j] > a[i][k] + a[k][j]) {
          cout << -1 << endl;
          return 0;
        }
        if(a[i][j] == a[i][k]+a[k][j] && a[i][k] > 0 && a[k][j] > 0) {
          sub += a[i][j];
          need[i][j] = false;

        }
      }
    }
  }
  ll ans = 0;
  for(int i=0;i<N;i++) {
    for(int j=0;j<N;j++) {
      if(need[i][j])
        ans += a[i][j];
    }
  }
  cout << ans / 2 << endl;


}
