#include <bits/stdc++.h>
#define For(i, a, b) for(int (i)=(a); (i)<(b); (i)++)
#define rFor(i, a, b) for(int (i)=(a)-1; (i)>=(b); (i)--)
#define rep(i, n) For((i), 0, (n))
#define rrep(i, n) rFor((i), (n), 0)
using namespace std;

int main(){
  int n, k; cin >> n >> k;
  vector<int> a(n); rep(i, n) cin >> a[i];
  a.push_back(0); a.push_back(1000000010);
  sort(a.begin(), a.end());
  int low = 0; int high = n+1;
  while(high - low > 1){
    int mid = (high + low) / 2;
    bool dp[5010][5010];
    rep(i, 5010)rep(j, 5010) dp[i][j] = false;
    dp[0][0] = true;
    rep(i, n+2)rep(j, k){
      dp[i+1][j] = dp[i][j] || dp[i+1][j];
      if(i != mid && j+a[i] < k) dp[i+1][j+a[i]] = dp[i][j];
    }
    bool flag = false;
    if(a[mid] >= k) flag = true;
    else{
      For(j, k-a[mid], k)if(dp[n+2][j]){
        flag = true;
        break;
      }
    }
    if(flag) high = mid;
    else low = mid;
  }
  cout << high - 1 << endl;
}