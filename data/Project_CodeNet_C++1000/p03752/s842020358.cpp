#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int N, K; cin >> N >> K;
  vector<ll> a(N);
  for(int i = 0; i < N; i++){
    cin >> a[i];
  }
  ll ans = 1e18;
  for(int i = 0; i <1<<(N - 1); i++){
    bitset<18> bit(i);
    if(bit.count() != K-1)continue;
    ll ans1 = 0;
    ll bound = a[0];
    for(int j = 0; j < N - 1; j++){
      if(bit[j]){
        if(bound >= a[j + 1]){
          ans1 += bound - a[j + 1] + 1;
        }
        bound++;
      }
      bound = max(bound, a[j + 1]);
    }
    ans = min(ans, ans1);
  }
  cout << ans << endl;
  return 0;
}