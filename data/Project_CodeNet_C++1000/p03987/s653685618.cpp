#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <iomanip>
#include <utility>
#include <tuple>
#include <functional>
#include <bitset>
#include <cassert>
#include <complex>
#include <stdio.h>
#include <time.h>
#include <numeric>
#include <random>
#include <unordered_map>
#include <unordered_set>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
#define rep(i,n) for(ll i = 0;i < (ll)n;i++)
#define ALL(x) (x).begin(),(x).end()
#define MOD 1000000007

int bs(ll n,vector<pair<ll,ll>> &v){
  int l = -1,r = v.size();
  while(r-l > 1){
    int mid = (l+r)/2;
    if(v[mid].first < n)l = mid;
    else r = mid;
  }
  return r;
}

int main(){
  
  #define mk make_pair
  ll n;
  cin >> n;
  vector<ll> v(n);
  rep(i,n)cin >> v[i];
  ll res = 0,pre = v[0];
  vector<pair<ll,ll>> mem;
  mem.push_back(mk(v[0],0));
  rep(i,n){
    ll pos = bs(v[i],mem);
    for(ll j = pos;j < mem.size();j++){
      if(j-1 >= 0){
        pre -= mem[j].first*(mem[j].second-mem[j-1].second);
      }else{
        pre -= mem[j].first*(mem[j].second+1);
      }
    }
    if(pos-1 >= 0)pre += v[i]*(i-mem[pos-1].second);
    else pre += v[i]*(i+1);
    {
      ll k = mem.size();
      for(ll j = pos;j < k;j++)mem.pop_back();
    }
    mem.push_back(mk(v[i],i));
    res += pre;
  }
  cout << res << "\n";


  

  return 0;
}