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
  int t,k;
  cin>>k>>t;
  vin a(t);
  rep(i,0,k) cin>>a[i];
  //////////
  if(k>1){
  rep(i,0,k){
          sort(all(a));
    //cout<<a[0]<<a[1]<<a[2]<<endl;
    reverse(all(a));
		  if(a[0]==0) break;
          if(a[1]==0) break;
          a[0]--;a[1]--;
  }
  }
  if(a[0]==0) a[0]++;
  cout<<a[0]-1<<endl;
}