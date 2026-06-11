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
  ll n,cnt=0;
  cin >> n;
  vl a(n);
  rep(i,n){
    cin >> a[i];
  }
  rep(i,n){
    ll j=a[i]-1;
    if(a[j]==i+1){
      cnt++;
    }
  }
  cout << cnt/2<< endl;
}