#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> pll;
const ll mod=1e9+7;
//const ll mod=998244353;
const ll inf=5e18;

int main() {
  ll n;
  cin >> n;
  vec a(n);
  for(ll i=0;i<n;i++) cin >> a[i];
  ll sum=0;
  ll ans1=0;
  for(ll i=0;i<n;i++) {
    sum+=a[i];
    if(i%2==0) {
      if(sum<=0) {
        ans1+=1-sum;
        sum=1;
      }
    }
    else {
      if(sum>=0) {
        ans1+=sum+1;
        sum=-1;
      }
    }
  }
  ll ans2=0;
  sum=0;
  for(ll i=0;i<n;i++) {
    sum+=a[i];
    if(i%2) {
      if(sum<=0) {
        ans2+=1-sum;
        sum=1;
      }
    }
    else {
      if(sum>=0) {
        ans2+=sum+1;
        sum=-1;
      }
    }
  }
  cout << min(ans1,ans2) << endl;
}