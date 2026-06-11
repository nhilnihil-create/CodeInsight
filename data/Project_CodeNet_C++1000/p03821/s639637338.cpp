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
  vl a(n),b(n),g(n);
  rep(i,n){
    cin >> a[i] >> b[i];
    g[i]=(b[i]+(b[i]-a[i])%b[i])%b[i];
  }
  ll cnt=0;
  for(ll i=n-1;i>=0;i--){
    g[i]=((g[i]-cnt)%b[i]+b[i])%b[i];
    cnt +=g[i];
  }
  cout << cnt << endl;
}