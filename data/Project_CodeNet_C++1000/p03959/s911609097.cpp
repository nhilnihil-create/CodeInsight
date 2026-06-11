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
  int n; cin >> n;
  vector<ll> a(n);
  rep(i,n) cin >> a[i];
  vector<ll> b(n);
  rep(i,n) cin >> b[i];
  vector<ll> f(n,0);
  f[0]=a[0]; f[n-1]=b[n-1];
  ll ans=1;
  for(int i=1;i<n-1;i++){
    if(a[i-1]==a[i]&&b[i]==b[i+1]){
      ans*=min(a[i],b[i]);
      ans%=mod;
    }
    else if(a[i-1]<a[i]&&b[i]>b[i+1]&&a[i]!=b[i]){
      cout << 0 << endl;
      return 0;
    }
    else if(a[i-1]<a[i]){
      f[i]=a[i];
    }
    else if(b[i]>b[i+1]){
      f[i]=b[i];
    }
  }
  vector<ll> aa=f;
  vector<ll> bb=f;
  rep(i,n-1){
    chmax(aa[i+1],aa[i]);
  }
  for(int i=n-2;i>=0;i--){
    chmax(bb[i],bb[i+1]);
  }
  if(a==aa&&b==bb){
    cout << ans << endl;
  }
  else cout << 0 << endl;
}