#include<iostream>
using namespace std;
int main(){
  long long n,i,ans = 0;cin >> n;
  long long a[n+2];a[0] = a[n+1] = 0;
  for(i=1;i<=n;i++) cin >> a[i];
  for(i=1;i<=n;i++){
    if(a[i] != 0 && a[i-1] == 1){
      a[i]--;a[i-1]--;ans++;
    }
    if(a[i]%2==1 && a[i+1]!=0){
      a[i]--;a[i+1]--;ans++;
    }
    ans += a[i]/2;a[i] %= 2;
  }
  cout << ans << endl;
}