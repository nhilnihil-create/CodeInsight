#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep1(i,n) for(ll i=1;i<n+1;i++)
#define sort(A) sort(A.begin(),A.end())
#define reverse(A) reverse(A.begin(),A.end())
typedef long long ll;
typedef pair<ll,ll> P;

int main(){
  ll n,a,b;
  cin >> n >> a >> b;
  vector<ll> x(n);
  rep(i,n) cin >> x[i];
  ll ans = 0;
  rep(i,n){
    if(i == 0) continue;
    ans += min(b,(x[i]-x[i-1])*a);
  }
  cout << ans << endl;
}
