#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <set>
#include <map>
#define REP(i,n) for(ll i = 0; i < (ll)n; i++)
#define INF 1000000000000000
using namespace std;
typedef long long ll;
typedef double db;
typedef string str;

int main(){
  ll n,l,t;
  cin >> n >> l >> t;
  ll x[n], w[n];
  REP(i,n) cin >> x[i] >> w[i];
  ll x_t[n];
  REP(i,n){
    if(w[i]==1){
      x_t[i] = (x[i] + t)%l;
    }else{
      x_t[i] = (x[i] - t + t * l)%l;
    }
  }
  ll zero_pos = x_t[0];
  sort(x_t,x_t+n);
  ll cross_cnt = 0;
  for(ll i = 1; i < n; i++){
    if(w[0]==1&&w[i]==2){
      cross_cnt += floor((t-(x[i]-x[0]+l)%l/2.0)/(l/2.0))+1;
    }else if(w[0]==2&&w[i]==1){
      cross_cnt -= floor((t-(x[0]-x[i]+l)%l/2.0)/(l/2.0))+1;
    }
  }
  //cout << cross_cnt << endl;
  ll zero_ind = cross_cnt>=0 ? cross_cnt%n : n+cross_cnt%n ;
  ll zero_ord = lower_bound(x_t,x_t+n,zero_pos) - x_t;
  if(x_t[zero_ord]==x_t[(zero_ord+1)%n]){
    if(w[0]==1){
      zero_ord++;
      zero_ord%=n;
    }
  }
  vector<pair<ll,ll> > ants;
  ants.push_back(pair<ll,ll>(zero_ind,zero_pos));
  REP(i,n-1){
    zero_ord++;
    zero_ord%=n;
    zero_ind++;
    zero_ind%=n;
    ants.push_back(pair<ll,ll>(zero_ind,x_t[zero_ord]));
  }
  sort(ants.begin(),ants.end());
  REP(i,n){
    cout << ants[i].second << endl;
  }
  return 0;
}
