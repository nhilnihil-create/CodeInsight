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
struct edge{ll to,cost;};

int main() {
  ll n;
  cin >> n;
  vl a(n);
  bool b=true;
  rep(i,n){
    cin >> a[i];
  }
  sort(a.begin(),a.end());
  if(a[n-1]-a[0]>=2){
    b=false;
  }
  else if(a[n-1]>=n){
    b=false;
  }
  else if(a[n-1]==a[0]){
    if(n<2*a[0]&&n!=a[0]+1){
      b=false;
    }
  }
  else{
    ll x=0;
    rep(i,n){
      if(a[n-1]==a[i]){
        x++;
      }
    }
    if(a[0]==a[a[0]]){
      b=false;
    }
    if(a[n-1]!=a[n-2]){
      b=false;
    }
    if(x/2+(n-x)<a[n-1]){
      b=false;
    }
  }
  if(b){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
}