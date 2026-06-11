#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n) ;i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
#define sz(x) ((int)(x).size())
using ll=long long;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define MOD  1000000007
const ll INF=1e18;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b){ a = b; return 1; } return 0; }



int main(int argc, char const *argv[]) {
  int n,k;
  cin >> n >> k;
  vector<ll> a(n);
  rep(i,n) cin >> a[i];
  ll ans=INF;

  for(int bit=0; bit< (1<<n); bit++){
    ll rec=0,tmp=0;
    int cnt=0;
    for(int i=0; i<n; i++){
      if(tmp>=a[i]){
         if(bit & (1<<i)){
          rec+=(tmp-a[i]+1);
          tmp=tmp+1;
          cnt++;
        }
      }
      else{
        cnt++;
        tmp=a[i];
      }
    }
    if(cnt>=k) chmin(ans,rec);
  }
  cout << ans << endl;
  return 0;
}
