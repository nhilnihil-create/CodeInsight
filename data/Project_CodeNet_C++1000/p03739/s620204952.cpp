#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);

  ll n;
  cin >> n;
  vector < ll > a(n + 1), p(n + 1);
  for(int i = 1; i <= n; i++) cin >> a[i];
  p[0] = 0;

  ll cnt = 0;
  for(int i = 1; i <= n; i++){
    if(i % 2){
      if(p[i - 1] + a[i] > 0){
        p[i] = p[i - 1] + a[i];
        continue;
      }
      ll c = 1 - a[i] - p[i - 1];
      cnt += c;
      p[i] = c + a[i] + p[i - 1];
    }else{
      if(p[i - 1] + a[i] < 0){
        p[i] = p[i - 1] + a[i];
        continue;
      }
      ll c = 1 + a[i] + p[i - 1];
      cnt += c;
      p[i] = p[i - 1] + a[i] - c;
    }
  }
  ll ans = cnt;

  cnt = 0;
  for(int i = 1; i <= n; i++){
    if(i % 2 == 0){
      if(p[i - 1] + a[i] > 0){
        p[i] = p[i - 1] + a[i];
        continue;
      }
      ll c = 1 - a[i] - p[i - 1];
      cnt += c;
      p[i] = c + a[i] + p[i - 1];
    }else{
      if(p[i - 1] + a[i] < 0){
        p[i] = p[i - 1] + a[i];
        continue;
      }
      ll c = 1 + a[i] + p[i - 1];
      cnt += c;
      p[i] = p[i - 1] + a[i] - c;
    }
  }

  ans = min(ans, cnt);
  cout << ans << '\n';
}
