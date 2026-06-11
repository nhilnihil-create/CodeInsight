#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;
using lb = long double;
using P = pair<ll,ll>;
using graph = vector<vector<ll>>;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const ll INF = 1LL<<60;
const ll mod = 1000000007LL;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  ll N;
  cin>>N;
  vector<ll> v(N);
  rep(i,N) cin>>v[i];
  sort(v.begin(),v.end());
  vector<ll> s(N);
  rep(i,N) {
    if(i==0) s[i] = v[i];
    else s[i] = s[i-1]+v[i];
  }
  ll ans = 0;
  reverse(s.begin(),s.end());
  reverse(v.begin(),v.end());
  rep(i,N){
    if(i==0) ans++;
    else{
      if(v[i-1]<=s[i]*2LL) ans++;
      else break;
    }
  }
  cout<<ans<<endl;
}