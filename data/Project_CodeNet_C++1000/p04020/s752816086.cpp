#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;} return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;} return 0;}
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define all(vec) vec.begin(),vec.end()
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
const ll mod=1e9+7;
const int inf=1<<30;

int main(){
  ll n; cin >> n;
  vector<ll> a(n);
  rep(i,n) cin >> a[i];
  ll ans=0;
  rep(i,n){
    if(i>0&&a[i-1]==1&&a[i]>0){
      ans++;
      a[i-1]=0; a[i]--;
    }
    ans+=a[i]/2;
    a[i]=a[i]-a[i]/2*2;
  }
  cout << ans << endl;
}