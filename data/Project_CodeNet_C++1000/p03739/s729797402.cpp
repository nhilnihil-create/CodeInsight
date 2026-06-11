
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define rep1(i, n) for(ll i = 1; i < n+1; i++)
#define sort(A) sort(A.begin(),A.end())
#define reverse(A) reverse(A.begin(),A.end());
#define vecmin(A) *min_element(A.begin(),A.end());
#define vecmax(A) *max_element(A.begin(),A.end());
typedef long long ll;

int main(){
  ll n;
  cin >> n;
  vector<ll> a(n);
  rep(i,n) cin >> a[i];
  ll now = 0;
  ll ans1 = 0;
  rep(i,n){
    now += a[i];
    if(i%2 == 0){
      if(now <= 0){
        ans1 += 1 - now;
        now = 1;
      }
    }
    if(i%2 == 1){
      if(now >= 0){
        ans1 += now + 1;
        now = -1;
      }
    }
  }//i
  
  now = 0;
  ll ans2 = 0;
  rep(i,n){
    now += a[i];
    if(i%2 == 1){
      if(now <= 0){
        ans2 += 1 - now;
        now = 1;
      }
    }
    if(i%2 == 0){
      if(now >= 0){
        ans2 += now + 1;
        now = -1;
      }
    }
  }//i
  
  cout << min(ans1,ans2) << endl;
}
