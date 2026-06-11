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
  ll n,m;
  cin >> n >> m;
  vl cnt(n,0);
  rep(i,m){
    ll a,b;
    cin >> a >> b;
    cnt[a-1]++;
    cnt[b-1]++;
  }
  bool B=true;
  rep(i,n){
    if(cnt[i]%2!=0){
      B=false;
    }
  }
  if(B){
    cout << "YES" << endl;
  }
  else{
    cout << "NO" << endl;
  }
}