// I SELL YOU...! 
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
signed main(){
  ll n,ans = 1;
  cin >> n;
  ll a[n],t[n];
  ll h[n];
  for(int i=0;i<n;i++){
    cin >> t[i];
    if(i==0||t[i]!=t[i-1]){
      h[i] = t[i];
    }else{
      h[i] = -1;
    }
  }
  for(int i=0;i<n;i++){
    cin >> a[i];
  }
  for(int i=n-1;i>=0;i--){
    if(i==n-1||a[i]!=a[i+1]){
      if(h[i]!=-1&&a[i]!=h[i]){
        ans = 0;
        break;
      }
      h[i] = a[i];
    }else if(h[i]!=-1){
      if(h[i]>a[i]){
        ans = 0;
        break;
      }
    }else{
      ans *= min(a[i],t[i]);
      ans %= MOD;
    }
  }
  cout << ans << endl;
}
