#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int N, K; cin >> N >> K;
  vector<long long> a(N);
  for(int i = 0; i < N; i++){
    cin >> a[i];
  }
  long long ans = 1e18;
  for(int i = 0; i <1<<(N - 1); i++){
    int cnt = 0;
    for(int j=0;j < N-1;j++){
      cnt += (i>>j)&1;
    }
    if(cnt != K-1)continue;
    long long tmp = 0;
    long long now = a[0];
    for(int j = 0; j < N - 1; j++){
      if(i>>j &1){
        if(now >= a[j + 1]){
          tmp += now - a[j + 1] + 1;
        }
        now = max(now + 1, a[j + 1]);
      }
      now = max(now, a[j + 1]);
    }
    ans = min(ans, tmp);
  }
  cout << ans << endl;
  return 0;
}