#include <bits/stdc++.h>
using namespace std;

#define ll long long

void chmin(ll& a, ll b) {
  if (a > b) a = b;
}

int main() {

  int N, K;
  cin >> N >> K;
  
  vector<ll> a(N);
  
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }
  
  // i番目までで最も高いもの
  vector<ll> height(N);
  height[0] = 0;
  
  ll SUBMAX = a[0];
  for (int i = 1; i < N; i++) {
    height[i] = SUBMAX;
    
    if (a[i] > SUBMAX) {
      SUBMAX = a[i];
    }
  }
  

  

  
  ll ans = 10000000000000;
  
  // bit 全探索
  for (int bit = 0; bit < (1 << N); bit++) {
    ll color = 0;
    ll cost = 0;
    
    ll temp = 0; 
    for (int i = 0; i < N; i++) {
      
      if (!(bit & 1)) continue;
          
      if (bit & (1 << i)) {
        color++;

        // 次の建物に必要な最低限の高さを temp で現す
        if (temp >= height[i]) {
          temp++;
        } else {
          temp = height[i]+1;
        }
        
        // cost の計算
        if (i == 0) {
          temp = a[0];
          continue;
        }
        if (a[i] > temp) {
           temp = a[i];
           continue;
        }
        cost += temp -a[i];
      }
    }
    
    
    if (color >= K) chmin(ans, cost);
    
  }  
  
  cout << ans << endl;

}