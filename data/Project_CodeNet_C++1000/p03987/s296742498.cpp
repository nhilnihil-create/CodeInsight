#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef long int li;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
typedef pair<ll, ll>P;
#define PI 3.14159265358979
#define MOD 998244353
const int MAX = 510000;

int main() {
  ll N;cin>>N;
  vector<ll>a(N);
  vector<ll>b(N);
  rep(i,N){
  	cin>>a[i];
  	b[a[i]-1ll]=i;
  }
  set<ll> s;
  s.insert(-1ll);
  s.insert(N);
  ll ans=0;
  rep(i,N){
    s.insert(b[i]);
    auto t=s.lower_bound(b[i]);
    t--;
    auto mi=*t;
    t++;t++;
    auto ma=*t;
    ans+=(i+1ll)*(ma-b[i])*(b[i]-mi);
  }
  cout<<ans;
}