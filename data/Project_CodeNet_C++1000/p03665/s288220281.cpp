#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MOD=1000000007;
const ll MOD2=998244353;
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

ll choose(ll n,ll k){
  ll x=n,y=1,ans=1;
  rep(i,k){
    ans=ans*x/y;
    x--;
    y++;
  }
  return ans;
}

int main() {
  ll n,p;
  cin >> n >> p;
  vl a(n);
  ll Z=0,O=0;
  rep(i,n){
    cin >> a[i];
    if(a[i]%2==0){
      Z++;
    }
    else{
      O++;
    }
  }
  ll X=0;
  ll i=0;
  while(i<=O){
    if(i%2==0){
      X+=choose(O,i);
    }
    i++;
  }
  if(p==0){
    cout << (ll)pow(2,Z)*X << endl;
  }
  else{
    cout << (ll)pow(2,Z)*((ll)pow(2,O)-X) << endl;
  }
}
