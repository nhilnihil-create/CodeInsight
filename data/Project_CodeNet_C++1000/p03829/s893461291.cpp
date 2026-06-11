// I SELL YOU...! 
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
signed main(){
  ll n,a,b,ans=0;
  cin >> n >> a >> b;
  ll x[n];
  for(int i=0;i<n;i++){
    cin >> x[i];
  }
  for(int i=1;i<n;i++){
    ans += min(b,(x[i]-x[i-1])*a);
  }
  cout << ans << endl;
}
