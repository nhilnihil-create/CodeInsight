#include <assert.h>
#include <limits.h>
#include <cmath>
#include <algorithm>
#include <bitset>
#include <cctype>
#include <complex>
#include <deque>
#include <iomanip>
#include <iostream>
#include <unordered_map>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using ll = long long;
using P = std::pair<ll, ll>;

#define rep(i, a, b) for (ll(i) = (a); i < (b); i++)
#define all(i) i.begin(), i.end()
#define debug(i) std::cerr <<"debug "<< i << std::endl;

//const ll MOD = 998244353;
const ll MOD = 1e9+7;
 
int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  //問題文中の添え字が0-indexか1-indexか確認!

  ll n;
  std::cin>>n;

  std::vector<ll> a(n),v(n,LLONG_MAX),sort;
  rep(i,0,n)std::cin>>a[i];

  std::vector<std::vector<ll>> graph(n);
  rep(i,0,n-1){
    ll x,y;
    std::cin>>x>>y;
    x--;y--;
    graph[x].push_back(y);
    graph[y].push_back(x);
  }

  if(n==2){
    std::cout<<((a[0]==a[1])?"YES":"NO");
    return 0;
  }

  ll root=-1;
  rep(i,0,n){
    if(graph[i].size()>=2)root=i;
  }

  std::vector<bool> used(n,false);
  std::queue<ll> que;

  que.push(root);

  while(!que.empty()){
    ll now=que.front();que.pop();
    sort.push_back(now);used[now]=true;
    for(ll next:graph[now]){
      if(!used[next])que.push(next);
    }    
  }

  for(ll i=n-1;i>=0;i--){
    ll now=sort[i];
    ll sum=0,max=-1;
    for(ll next:graph[now]){
      if(v[next]!=LLONG_MAX){
        sum+=v[next];
        max=std::max(max,v[next]);
      }
    }

    if(sum==0){
      v[now]=a[now];
    }else{
      v[now]=2*a[now]-sum;
      if(v[now]<0){
        std::cout<<"NO";
        return 0;
      }
      ll pair=(sum-v[now])/2;
      if(pair<0){
        std::cout<<"NO";
        return 0;
      }
      if(max>sum/2){
        if(sum-max<pair){
          std::cout<<"NO";
          return 0;
        }
      }else{
        if(sum/2<pair){
          std::cout<<"NO";
          return 0;
        }
      }
    }
  }

  if(v[root]!=0){
    std::cout<<"NO";
    return 0;
  }

  std::cout<<"YES";

  return 0;
}
