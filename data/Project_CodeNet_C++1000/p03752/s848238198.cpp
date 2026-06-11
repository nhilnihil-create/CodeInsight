#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, k; cin >> n >> k;
  vector<long long> h(n);
  for(int i = 0; i < n; i++){
    cin >> h.at(i);
  }
  long long ans = 1001001001001001;
  for(int i = 0; i < (1<<n); i++){
    long long sum = 0, tmp = 0;
    int can_see = 0;
    for(int j = 0; j < n; j++){
      if(tmp < h.at(j)){
        tmp = h.at(j);
        can_see++;
      }
      else{
        if(i & (1 << j)){
          sum += tmp - h.at(j) + 1;
          tmp++;
          can_see++;
        }
      }
      if(can_see >=k) ans = min(ans, sum);
    }
  }
  cout << ans << endl;
}

