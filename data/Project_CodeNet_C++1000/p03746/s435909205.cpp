/*
* Welcome to my code!
*---------------------------------------------*
* author : lynmisakura(twitter : @andoreiji11)
*/
#include <iostream>
#include <limits.h>
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <cassert>

using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define repn for(int i = 0;i < n;i++)
#define ain(a) for(auto& i : a)cin >> i;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x.size()) 
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define cont continue

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using pi = pair<int,int>;
using vpi = vector<pi>;
using pl = pair<ll,ll>;
using vpl = vector<pl>;

template<class T> bool chmin(T& a,T b){if(a > b){a = b;return true;}else return false;}
template<class T> bool chmax(T& a,T b){if(a < b){a = b;return true;}else return false;}
template<class T> void print(std::vector<T> a)
{ int sz = a.size(); for(int i=0;i<a.size();i++)cout << a[i] << (i < sz-1 ? ' ' : '\n'); }
void ioboost(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}
///////////////////////////////////////////////////////////

int n,m;
vi g[200020];
int used[200020];
vi res;
bool dfs(int x,int y){
  used[x]++;
  int update = 0;
  for(int i : g[x]){
    if(i != y && !used[i]){
      update = 1;
      if(dfs(i,y)){
        res.pb(x + 1);
        return true;
      }
    }
  }
  if(!update){
    res.pb(x+1);
    return true;
  }else return false;
}
int main(void){
  ioboost();

  cin >> n >> m;
  rep(i,m){
    int a,b;cin >> a >> b;
    a--,b--;
    g[a].pb(b);
    g[b].pb(a);
  }

  used[0] = used[g[0][0]] = 1;

  dfs(0,g[0][0]);
  vi p1 = res;

  res.clear();

  dfs(g[0][0],0);
  vi p2 = res;
  reverse(all(p2));

  int sz1 = p1.size();
  int sz2 = p2.size();
  cout << sz1 + sz2 << '\n';
  rep(i,sz1)cout << p1[i] << ' ';
  rep(i,sz2)cout << p2[i] << (i < sz2 - 1 ? ' ' : '\n');
  return 0; 
}
