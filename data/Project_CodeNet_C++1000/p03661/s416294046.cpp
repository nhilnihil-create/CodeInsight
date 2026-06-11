#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;} return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;} return 0;}
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define all(vec) vec.begin(),vec.end()
typedef long long ll;
typedef pair<ll,ll> l_l;
typedef pair<int,int> i_i;
const ll mod=1e9+7;
const int inf=1<<30;

int main(){
  int n; cin >> n;
  vector<ll> a(n);
  rep(i,n) cin >> a[i];
  vector<ll> s(n+1);
  s[0]=0;
  rep(i,n){
    s[i+1]=s[i]+a[i];
  }
  ll ans=1e18;
  for(int i=1;i<=n-1;i++){
    chmin(ans,abs(s[i]-(s[n]-s[i])));
  }
  cout << ans << endl;
}