#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;


int main(void){
  int n,i;
  ll a[100005],t[100005];
  const int mod=1e9+7;
  bool ak[100005]={false},tk[100005]={false};
  
  cin >> n;
  for (i=0;i<n;i++) cin >> a[i];
  for (i=0;i<n;i++) cin >> t[i];
  
  for (i=0;i<n;i++){
    if (i==0 || a[i]>a[i-1]) ak[i]=true;
    if (i==n-1 || t[i]>t[i+1]) tk[i]=true;
  }
  
  ll ans=1;
  for (i=0;i<n;i++){
    if ((ak[i] && tk[i] && a[i]!=t[i]) || (ak[i] && a[i]>t[i]) || (tk[i] && t[i]>a[i])){
      cout << 0 << endl;
      return 0;
    }
    if (ak[i] || tk[i]) continue;
    ans=ans*min(a[i],t[i])%mod;
  }
  
  cout << ans << endl;
  
  return 0;
}