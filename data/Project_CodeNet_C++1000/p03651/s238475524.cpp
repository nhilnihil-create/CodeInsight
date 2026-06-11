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

ll gcd(ll a,ll b){
  if(min(a,b)==0){
    return max(a,b);
  }
  else if(a%b==0){
    return b;
  }
  else
    return gcd(b,a%b);
}
int main() {
  ll n,k;
  cin >> n >> k;
  vl a(n);
  rep(i,n){
    cin >> a[i];
  }
  sort(a.begin(),a.end());
  ll min=a[0],max=a[n-1];
  ll GCD=a[1]-a[0];
  rep(i,n-1){
    GCD=gcd(a[i+1]-a[i],GCD);
  }
  if(GCD!=0){
    if(k<=max&&(k-min)%GCD==0){
      cout << "POSSIBLE" << endl;
    }
    else{
      cout << "IMPOSSIBLE" << endl;
    }
  }
  else if(GCD==0){
    if(k==0||k==a[0]){
      cout << "POSSIBLE" << endl;
    }
    else{
      cout << "IMPOSSIBLE" << endl;
    }
  }
}