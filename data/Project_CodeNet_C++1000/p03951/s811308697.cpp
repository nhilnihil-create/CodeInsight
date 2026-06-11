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
  string s,t;
  cin >> n >> s >> t;
  ll ans=2*n;
  ll k=0;
  FOR(i,1,n+1){
    bool a=true;
    FOR(j,0,i){
      if(t[j]!=s[j+n-i]){
        a=false;
      }
    }
    if(a){
      k=i;
    }
  }
  cout << ans -k << endl;
}