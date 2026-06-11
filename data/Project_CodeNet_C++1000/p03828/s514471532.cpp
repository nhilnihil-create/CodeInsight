#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mod = 1000000007;
int main(){
  int n; cin >> n;
  vector<int> div(n+1, 0);
  for(int i = 2; i <= n; i++){
    int tmp = i;
    for(int j = 2; j*j <= n; j++){
      int cnt = 0;
      while(tmp % j == 0){
        tmp /= j;
        cnt++;
      }
      div[j] += cnt;
    }
    if(tmp != 1) div[tmp]++;
  }
  ll ans = 1;
  for(int i = 2; i <= n; i++){
    if(div[i] == 0) continue;
    ans = ans * (div[i]+1) % mod;
  }
  cout << ans << endl;
}