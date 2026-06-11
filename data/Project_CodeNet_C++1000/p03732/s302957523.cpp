#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <iomanip>
#include <stack>
#include <queue>
#include <numeric>
#include <map>
#include <unordered_map>
#include <set>
#include <fstream>
#include <chrono>
#include <random>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x) ((int)(x).size())
#define pb push_back
#define mod 1000000007
using ll = long long;
using namespace std;

int main(){
  ll N; ll W; cin >> N >> W;
  ll ans = 0;
  vector<vector<ll>> V(4);
  ll w,v;
  ll ww;
  rep(i,N){
    if(i==0){
      cin >> ww >> v;
      V[0].pb(v);
    }
    else{
      cin >> w >> v;
      V[w-ww].pb(v);
    }
  }
  rep(i,4) sort(rall(V[i]));
  vector<vector<ll>> sums(4);
  rep(i,4) {
    sums[i].pb(0);
    rep(j,sz(V[i])){
      sums[i].pb(sums[i].back()+V[i][j]);
    }
  }
  rep(w0,sz(V[0])+1){
    rep(w1,sz(V[1])+1){
      rep(w2,sz(V[2])+1){
        rep(w3,sz(V[3])+1){
          ll sumw = ww*w0+(ww+1)*w1+(ww+2)*w2+(ww+3)*w3;
          ll sumv = sums[0][w0]+sums[1][w1]+sums[2][w2]+sums[3][w3];
          if(sumw <= W){
            ans = max(ans, sumv);
          }
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}
