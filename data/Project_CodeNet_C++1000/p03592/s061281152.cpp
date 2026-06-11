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
  ll h,w,k; cin >> h >> w >> k;
  bool f=false;
  for(int i=0; i<=h; i++){
    for(int j=0; j<=w; j++){
      if(i*(w-j)+j*(h-i)==k){
        f=true; break;
      }
    }
  }
  if(f) puts("Yes");
  else puts("No");
  return 0;
}
