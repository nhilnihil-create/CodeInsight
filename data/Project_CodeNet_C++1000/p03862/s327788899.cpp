#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
const ll p=1000000007;
int main(){
  ll n,x;
  cin >> n >> x;
  ll ans=0;
  ll a[n];
  rep(i,n){
    cin >> a[i];
  }
  if(a[0]>x){
    ans+=a[0]-x;
    a[0]=x;
  }
  rep(i,n-1){
    if(a[i]+a[i+1]>x){
      ans+=a[i]+a[i+1]-x;
      a[i+1]=x-a[i];
    }
  }
  cout << ans << endl;
}
