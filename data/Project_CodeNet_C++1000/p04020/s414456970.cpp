#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MOD=1000000007;
const double PI=3.14159265358979;
const ll INF= pow(10,18);
typedef pair<ll,ll> P;
typedef vector<ll> vl;
typedef vector<vl> vvl;
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define rep(i,n) FOR(i,0,n)
string abc="abcdefghijklmnopqrstuvwxyz";
string ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main() {
  ll n;
  cin >> n;
  vl a(n);
  rep(i,n){
    cin >> a[i];
  }
  ll ans=0;
  rep(i,n){
    if(i==0){
      ans+=a[i]/2;
      a[i]=a[i]%2;
    }
    else{
      if(a[i-1]==1&&a[i]>=1){
        a[i-1]--;
        a[i]--;
        ans++;
      }
      ans+=a[i]/2;
      a[i]=a[i]%2;
    }
  }
  cout << ans << endl;
}