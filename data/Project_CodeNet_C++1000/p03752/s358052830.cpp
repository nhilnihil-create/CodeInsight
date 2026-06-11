#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int inf = 1LL << 60;
signed main(void){
  int n,k; cin >> n >> k;
  vector<int>a(n);
  for(int i = 0; i < n; i++){ cin >> a[i];}
  int ans = inf;
  for(int bit = 0; bit < (1<<n); bit++){
    vector<bool> vec(n,false); int cnt = 0;
    for(int i = 0; i < n; i++){ 
      if( bit >> i & 1 ){ vec[i] = true; cnt++;}
    }
    if( cnt < k ){ continue;}
    int M = 0; int sum = 0;
    for(int i = 0; i < n; i++){
      if( vec[i] ){
        if( M >= a[i] ){ sum += M-a[i]+1;}
      }
      if( vec[i] ){ M = max(M+1,a[i]);}
      else{ M = max(M,a[i]);}
    }
    ans = min(ans,sum);
  }
  cout << ans << endl;
  return 0;
}
      