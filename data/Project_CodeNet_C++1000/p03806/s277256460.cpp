#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<cstdio>
#include<cmath>
#include<deque>
#include<numeric>
#include<queue>
#include<stack>
#include<cstring>
#include<limits>
#include<functional>
#include<unordered_set>
#include<iomanip>
#include<cassert>
#include<regex>
#include<bitset>
#include<complex>
#include<chrono>
#define rep(i,a) for(int i=(int)0;i<(int)a;++i)
#define pb push_back
#define eb emplace_back
using ll=long long;
constexpr ll mod = 1e9 + 7;
constexpr ll INF = 1LL << 60;
 
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
 
using namespace std;


void solve(){
  int n,ma,mb;
  cin>>n>>ma>>mb;
  vector<int>a(n),b(n),c(n);
  int ans=1e5;
  rep(i,n){
    cin>>a[i]>>b[i]>>c[i];
  }
  int x=(n+1)/2;
  vector<pair<int,int>>v;
  for(int bit=0;bit<(1<<x);++bit){
    int suma=0,sumb=0,sumc=0;
    rep(i,x){
      if(bit&(1<<i)){
        suma+=a[i];
        sumb+=b[i];
        sumc+=c[i];
      }
    }
    v.eb(ma*sumb-mb*suma,sumc);
  }
  sort(v.begin(),v.end());
  //for(auto e:v)cout<<e.first<<" "<<e.second<<"\n";
  int y=n-x;
  for(int bit=0;bit<(1<<y);++bit){
    int suma=0,sumb=0,sumc=0;
    rep(i,y){
      if(bit&(1<<i)){
        suma+=a[x+i];
        sumb+=b[x+i];
        sumc+=c[x+i];
      }
    }
    int lb=lower_bound(v.begin(),v.end(),make_pair(mb*suma-ma*sumb,-1))-v.begin();
    int ub=upper_bound(v.begin(),v.end(),make_pair(mb*suma-ma*sumb,100000))-v.begin();
    for(int i=lb;i<ub;++i){
      //cout<<v[i].second<<"\n";
      if(sumc+v[i].second!=0){
        chmin(ans,sumc+v[i].second);
        break;
      }
    }
  }
  if(ans!=1e5)cout<<ans;
  else cout<<-1;
}

int main(){
	ios::sync_with_stdio(false);
  cin.tie(0);
	cout<<fixed<<setprecision(15);
  solve();
	return 0;
}
