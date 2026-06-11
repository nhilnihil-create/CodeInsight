#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> pll;
const ll mod=1e9+7;
//const ll mod=998244353;
const ll inf=1LL<<61;

int main() {
  ll n,m;
  cin >> n >> m;
  vec a(n);
  map<ll,ll> cnt;
  for(ll i=0;i<n;i++) {
    cin >> a[i];
    cnt[a[i]%m]++;
  }
  sort(a.begin(),a.end());
  ll ans=0;
  for(auto p:cnt) {
    if(p.first==(m-p.first)%m) {
      ans+=p.second/2;
      cnt[p.first]=p.second%2;
    }
    else {
      ll tmp=min(p.second,cnt[m-p.first]);
      ans+=tmp;
      cnt[p.first]-=tmp;
      cnt[m-p.first]-=tmp;
    }
  }
  for(ll i=0;i<n-1;i++) {
    if(a[i]==a[i+1]) {
      if(cnt[a[i]%m]>1) {
        ans++;
        cnt[a[i]%m]-=2;
        i++;
      }
    }
  }
  cout << ans << endl;
}