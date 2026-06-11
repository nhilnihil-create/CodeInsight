#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a; i< (int)(b); ++i)
#define ALL(x) (x).begin(),(x).end()
#define rALL(x) (x).rbegin(),(x).rend()
typedef long double ld;
using ll=long long;
using namespace std;
const int mod=1e9+7;
const ll inf = 1LL << 60;
const ld pi = (acos(-1));
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

ll func(pair<ll,ll> x){
  int le=0;
  int ri=0;
  while(x.first){
      x.first/=10;
      le++;
    }
  while(x.second){
    x.second/=10;
    ri++;
  }
  return max(le,ri);
}


int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(20);

  ll n; cin >> n;
  int ans=10000007;
  vector<pair<ll,ll>> A;
  for(ll i=1;i*i<=n;i++){
    if(n%i==0) A.push_back(make_pair(i,n/i));
  }
  for(auto& a:A){
    int res=func(a);
    ans=min(res,ans);
  }
  cout << ans << endl;
}