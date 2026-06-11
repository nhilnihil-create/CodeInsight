#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
using st=string;
using ch=char;
typedef pair<ll,ll> P;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<P> vP;
typedef vector<ch> vc;
typedef vector<vc> vvc;
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define rep(i,n) FOR(i,0,n)
#define ROF(i,a,b) for(ll i=a;i>=b;i--)
#define per(i,a) ROF(i,a,0)
const ll MOD=1000000007;
const ll MOD2=998244353;
const ld PI=acos(-1);
const ll INF=1e18;
st abc="abcdefghijklmnopqrstuvwxyz";
st ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
struct edge{ll to,cost;};

int main() {
  ll x,y;
  cin >> x >> y;
  if(x==4||x==6||x==9||x==11){
    x=11;
  }
  else if(x==2){
    x=2;
  }
  else{
    x=1;
  }
  if(y==4||y==6||y==9||y==11){
    y=11;
  }
  else if(y==2){
    y=2;
  }
  else{
    y=1;
  }
  if(x==y){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
}