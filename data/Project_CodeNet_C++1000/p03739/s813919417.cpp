#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef vector<vector<int>> Matrix;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define ALL(x) (x).begin(), (x).end()
static const int INF = 2000000000;



int main(){
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  ll ans = 0;
  ll wa;
  if (a[0] > 0) {
    ll ans1 = 0, ans2 = a[0] + 1;
    wa = a[0];
    for (int i = 1; i < n; i++){
      if (wa > 0){
        wa += a[i];
        if (wa < 0) continue;
        else {
          ans1 += wa + 1;
          wa = -1;
        }
      } else {
        wa += a[i];
        if (wa > 0) continue;
        else {
          ans1 += 1 - wa;
          wa = 1;
        }        
      }
    }
    wa = -1;
    for (int i = 1; i < n; i++){
      if (wa > 0){
        wa += a[i];
        if (wa < 0) continue;
        else {
          ans2 += wa + 1;
          wa = -1;
        }
      } else {
        wa += a[i];
        if (wa > 0) continue;
        else {
          ans2 += 1 - wa;
          wa = 1;
        }        
      }
    }
    if (ans1 < ans2) cout << ans1 << endl;  
    else cout << ans2 << endl;
  }
  else if (a[0] < 0) {
    ll ans1 = 0, ans2 = 1 - a[0];
    wa = a[0];
    for (int i = 1; i < n; i++){
      if (wa > 0){
        wa += a[i];
        if (wa < 0) continue;
        else {
          ans1 += wa + 1;
          wa = -1;
        }
      } else {
        wa += a[i];
        if (wa > 0) continue;
        else {
          ans1 += 1 - wa;
          wa = 1;
        }        
      }
    }
    wa = 1;
    for (int i = 1; i < n; i++){
      if (wa > 0){
        wa += a[i];
        if (wa < 0) continue;
        else {
          ans2 += wa + 1;
          wa = -1;
        }
      } else {
        wa += a[i];
        if (wa > 0) continue;
        else {
          ans2 += 1 - wa;
          wa = 1;
        }        
      }
    }
    if (ans1 < ans2) cout << ans1 << endl;  
    else cout << ans2 << endl;
  }
  else {
    ll ans1 = 1, ans2 = 1;
    wa = 1;
    for (int i = 1; i < n; i++){
      if (wa > 0){
        wa += a[i];
        if (wa < 0) continue;
        else {
          ans1 += wa + 1;
          wa = -1;
        }
      } else {
        wa += a[i];
        if (wa > 0) continue;
        else {
          ans1 += 1 - wa;
          wa = 1;
        }        
      }
    }
    wa = -1;
    for (int i = 1; i < n; i++){
      if (wa > 0){
        wa += a[i];
        if (wa < 0) continue;
        else {
          ans2 += wa + 1;
          wa = -1;
        }
      } else {
        wa += a[i];
        if (wa > 0) continue;
        else {
          ans2 += 1 - wa;
          wa = 1;
        }        
      }
    }
    
    if (ans1 < ans2) cout << ans1 << endl;
    else cout << ans2 << endl;
  }
}