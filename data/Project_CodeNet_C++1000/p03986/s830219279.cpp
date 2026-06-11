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

int main() {
  string x;
  cin >> x;
  ll n=x.size();
  string k="";
  rep(i,n){
    k+=x[i];
    ll a=k.size();
    if(a>=2&&k[a-1]=='T'&&k[a-2]=='S'){
      k.pop_back();
      k.pop_back();
    }
  }
  cout << k.size() << endl;
}