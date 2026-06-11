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
#include <bitset>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x) ((int)(x).size())
#define pb push_back
using ll = long long;
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
ll gcd(ll a, ll b) {return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) {return a/gcd(a,b)*b;}

void solve(){
  int N; cin >> N;
  vector<vector<int>> tree(N);
  vector<vector<ll>> cost(N);
  int a,b;
  ll c;
  rep(i,N-1){
    cin >> a >> b >> c; a--; b--;
    tree[a].pb(b); tree[b].pb(a);
    cost[a].pb(c); cost[b].pb(c);
  }


  int Q, K; cin >> Q >> K;
  K--;
  vector<ll> d(N,-1);
  d[K]=0;
  queue<int> qu;
  qu.push(K);
  while(!qu.empty()){
    int now = qu.front(); qu.pop();
    rep(i,sz(tree[now])){
      if(d[tree[now][i]]!=-1)continue;
      qu.push(tree[now][i]);
      d[tree[now][i]] = d[now]+cost[now][i];
    }
  }
  rep(q,Q){
    int x, y; cin >> x >> y;
    x--;y--;
    cout<<d[x]+d[y]<<'\n';
  }
}

int main(){
  solve();
  return 0;
}
