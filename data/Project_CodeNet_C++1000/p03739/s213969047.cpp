#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0;i < n;++i){
    cin >> a[i];
  }
  long long ans = LLONG_MAX, cum = 0, tmp = 0;
  for (int i = 0; i < n; ++i){
    cum += a[i];
    if (i % 2 == 0){
      if (cum <= 0){
        tmp += -cum + 1;
        cum = 1;
      }
    }else{
      if (cum >=0){
        tmp += cum + 1;
        cum = -1;
      }
    }
  }
  ans = min(ans,tmp);
  cum = tmp = 0;
  for (int i = 0; i < n; ++i){
    cum += a[i];
    if (i % 2 == 1){
      if (cum <= 0){
        tmp += -cum + 1;
        cum = 1;
      }
    }else{
      if (cum >=0){
        tmp += cum + 1;
        cum = -1;
      }
    }
  }
  ans = min(ans, tmp);
  cout << ans << endl;
}