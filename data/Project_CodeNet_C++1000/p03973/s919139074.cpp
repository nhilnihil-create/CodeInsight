#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MOD=1000000007;
const ll MOD2=998244353;
const double PI=acos(-1);
const ll INF=1e15;
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
  rep(i,n){
    cin >> a[i];
  }
  ll cnt=a[0]-1;
  ll D=2;
  FOR(i,1,n){
    if(a[i]==D){
      D++;
    }
    else{
      cnt +=(a[i]-1)/D;
    }
  }
  cout << cnt << endl;
}
