#include <bits/stdc++.h>

using namespace std;
const long long MOD=1e9+7;

int main(){
  long long n, t[100009], a[100009], check[100009];
  cin >> n;
  for(int i=0;i<n;i++)cin >> t[i];
  for(int i=0;i<n;i++)cin >> a[i];
  if(n==1 && t[0] != a[0]){
    cout << 0 << endl;
    return 0;
  }
  memset(check, -1, sizeof(check));
  check[0] = t[0];
  check[n-1] = a[n-1];
  for(int i=1;i<n;i++){
    if(t[i]!=t[i-1]){
      check[i]=t[i];
      if(check[i]>a[i]){
        cout << 0 << endl;
        return 0;
      }
    }
  }
  for(int i=n-2;i>=0;i--){
    if(a[i]!=a[i+1]){
      check[i]=a[i];
      if(check[i]>t[i]){
        cout << 0 << endl;
        return 0;
      }
    }
  }
  long long ans=1LL;
  for(int i=0;i<n;i++){
    if(check[i]==-1){
      ans = (ans * min(t[i] , a[i]))%MOD;
    }
  }
  cout << ans << endl;
}

