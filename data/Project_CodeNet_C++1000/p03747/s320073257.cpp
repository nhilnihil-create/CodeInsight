#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<queue>
#include<stack>
#include<cassert>
#include<numeric>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
using namespace std;
const int INF = 1001001001;
const long long LINF = 1001002003004005006ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
typedef long long ll;
typedef pair<int,int> P;

int main(){
  int n;
  ll l,t;
  cin >> n >> l >> t;
  ll x[n];int w[n];
  rep(i,n)cin >> x[i] >> w[i];
  int p[n];
  rep(i,n){
    if(w[i]==1)p[i]=(x[i]+t)%l;
    else p[i]=((x[i]-t)%l+l)%l;
  }
  int id=-1;
  int p0=p[0];
  sort(p,p+n);
  if(w[0]==1){
    rep(i,n)if(p[i]==p0)id=i;
  }else{
    rep(i,n)if(p[n-1-i]==p0)id=n-1-i;
  }
  auto calc_count = [&] (ll dif){
    if(t*2 < dif) return 0LL;
    ll remain = t*2 - dif;
    return 1+remain/l;
  };
  ll c = 0;
  for(int i=1;i<n;i++){
    if(w[0]==1){
      if(w[i]==2)c+=calc_count(x[i]-x[0]);
    }
    if(w[0]==2){
      if(w[i]==1)c-=calc_count(x[0]+l-x[i]);
    }
  }
  int res[n];
  rep(i,n)res[i]=p[((i+id-c)%n+n)%n];
  rep(i,n)cout << res[i] << endl;
}
