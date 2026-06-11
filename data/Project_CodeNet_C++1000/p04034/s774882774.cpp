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
  ll n,m;
  cin >> n >> m;
  vl a(m),b(m);
  rep(i,m){
    cin >> a[i] >> b[i];
    a[i]--;
    b[i]--;
  }
  vl x(n,0),y(n,1);
  x[0]=1;
  rep(i,m){
    y[b[i]]++;
    y[a[i]]--;
    if(x[a[i]]==1){
      x[b[i]]=1;
    }
    if(y[a[i]]==0){
      x[a[i]]=0;
    }
  }
  ll sum=0;
  rep(i,n){
    sum +=x[i];
  }
  cout << sum << endl;
}