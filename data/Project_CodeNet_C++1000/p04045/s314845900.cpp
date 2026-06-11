#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define mp(x,y) make_pair(x,y)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
using ll = long long;
using vin=vector<int>;
using vll=vector<ll>;
using P = pair<int, int>;
const int inf=1e9+7;
const ll INF=1e18;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }

int main() {
  int n,k;
  cin>>n>>k;
  vin d(k);
  rep(i,0,k)cin>>d[i];
  //////
  int ans=0;
  rep(i,n,100000){
    bool ok=true;
    string t;
    t=to_string(i);
    int g=t.size();
    rep(j,0,g){
      rep(h,0,k){
        if(t[j]==d[h]+'0') ok=false;        
      }   
    }
    
    if(ok){
     ans=i;
      break;
    }
  }
  cout<<ans<<endl;
}