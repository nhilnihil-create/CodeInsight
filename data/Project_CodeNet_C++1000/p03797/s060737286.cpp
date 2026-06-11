#include<bits/stdc++.h>
using namespace std;
#define INFTY 10000000000
typedef long long int ll;
const int MOD=1000000007;
using Graph = vector<vector<int>>;
using ipair = pair<ll,ll>;
bool operator< (const ipair a, const ipair b){return a.first < b.first;};
#define rep(i,n) for (int i = 0; i < (n); ++i)
ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}

int main(){
  ll n,m;
  cin>>n>>m;
  if(m/2<n){
    cout<<m/2<<endl;
    return 0;
  }
  ll ans = 0;
  ans += n;
  m -= 2*n;
  ans += m/4;
  cout<<ans<<endl;
  return 0;
}