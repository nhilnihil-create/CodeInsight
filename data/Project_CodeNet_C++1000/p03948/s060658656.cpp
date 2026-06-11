#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, t;
  int a[100010];
  int amax[100010];
  cin >> n >> t;

  for(int i = 0;i < n;i++){
    cin >> a[i];
  }

  amax[n-1] = a[n-1];
  for(int i = n-2;i >= 0;i--){
    amax[i] = max(amax[i+1],a[i]);
  }

  int now_max = 0;
  int ans = 0;
  for(int i = 0;i < n;i++){
    if(now_max < amax[i]-a[i]){
      now_max = amax[i]-a[i];
      ans = 1;
    }else if(now_max == amax[i]-a[i]){
      ans++;
    }
  }

  cout << ans << endl;

  return 0;
}