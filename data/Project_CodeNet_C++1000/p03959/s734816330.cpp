#include<bits/stdc++.h>
using namespace std;
long mod = 1e9+7;
int main(){
  long n;
  cin >> n;
  vector<long> a(n),t(n);
  for(long i = 0; i < n; i++) cin >> t[i];
  for(long i = 0; i < n; i++) cin >> a[i];
  if(a[0] != t[n-1]){
    cout << 0 << endl;
  }else{
    long ans = 1;
    for(long i = 1; i < n-1; i++){
      if(t[i] == t[i-1] && a[i] == a[i+1]){
        ans*=min(t[i],a[i]);
        ans%=mod;
      }else if(t[i] > t[i-1] && a[i] == a[i+1] && a[i] < t[i]){  //h[i] == t[i]
        ans = 0;
        break;
      }else if(t[i] == t[i-1] && a[i] > a[i+1] && a[i] > t[i]){  //h[i] == a[i]
        ans = 0;
        break;
      }else if(t[i] > t[i-1] && a[i] > a[i+1] && a[i] != t[i]){   //h[i] == t[i] == a[i]
        ans = 0;
        break;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
