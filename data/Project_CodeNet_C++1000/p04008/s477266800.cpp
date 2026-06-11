#include <iostream>
#include <stdio.h>
#include <fstream>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <limits.h>
#include <math.h>
#include <functional>
#include <bitset>
#include <iomanip>

#define repeat(i,n) for (long long i = 0; (i) < (n); ++ (i))
#define debug(x) cerr << #x << ": " << x << '\n'
#define debugArray(x,n) for(long long i = 0; (i) < (n); ++ (i)) cerr << #x << "[" << i << "]: " << x[i] << '\n'
#define debugArrayP(x,n) for(long long i = 0; (i) < (n); ++ (i)) cerr << #x << "[" << i << "]: " << x[i].first<< " " << x[i].second << '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> Pii;
typedef vector<int> vint;
typedef vector<ll> vll;
const ll INF = LLONG_MAX;
const ll MOD = 1e9+7;

int K;
int a[112345];
ll ans;
ll dfs(const vector<vint>& g,int p,int v){
  ll h=1;
  for(int u:g[v])if(u!=p){
    h = max(h,dfs(g,v,u)+1);
  }
  if(h==K&&a[v]!=0){
    a[v]=0;
    ans++;
    h=0;
  }
  return h;
}
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N;cin>>N>>K;
  vector<vint> g(N);
  repeat(i,N){
    cin>>a[i];a[i]--;
    if(i==0){
      ans=a[i]!=0;
      a[i]=0;
      continue;
    }
    g[a[i]].push_back(i);
  }
  //debug(ans);
  //debugArray(a,N);
  dfs(g,-1,0);
  //debugArray(a,N);
  cout << ans << endl;
  return 0;
}
