#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
int main(void){
  int n,i;
  ll t[100010],a[100010],ans=1;
  const int mod=1e9+7;
  cin >> n;
  for (i=0;i<n;i++) cin >> t[i];
  for (i=0;i<n;i++) cin >> a[i];
  if (t[0]>a[0] || t[n-1]<a[n-1]){
    cout << 0 << endl;
    return 0;
  }
  for (i=1;i<n-1;i++){
    if ((t[i]!=t[i-1] && t[i]>a[i]) || (a[i]!=a[i+1] && a[i]>t[i])){
      cout << 0 << endl;
      return 0;
    }
    if (t[i]==t[i-1] && a[i]==a[i+1]) ans=(ans*min(t[i],a[i]))%mod;
  }
  cout << ans << endl;
  return 0;
}