#include <vector>
#include <math.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
template <class T> using V = vector<T>;
template <class T> using VV = V<V<T>>;
#define rep(i, n) for(int i = 0; i<n; i++)
#define rep_s(i, start, n) for(int i= start;  i<n; i++)
string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
/*
using edge = struct {int to; ll cost;};
vector<edge> tree[limit];
ll depth[limit];

void dfs(int v, int p, ll d){
  depth[v] = d;
  //cout <<"v: " << v << endl;
  for (auto &e: tree[v]){
    //cout << "e.to: " << e.to << endl;
    if (e.to == p) continue;
    dfs(e.to, v, d+e.cost);
  }
}
*/
int main(void){
    int N;
    cin>>N;
    string s,t;
    cin>>s>>t;
    const ll MOD=1000000007;
    ll res=(s[0]==t[0]?3:6);
    s=s+'#';
    t=t+'#';
    rep(i, N-1){
      if (s[i+1] == s[i]) continue;
      else {
        if (s[i] != t[i] && s[i+1] == t[i+1]) continue;
        else if(s[i] != t[i] && s[i+1] != t[i+1]){res *= 3; res %= MOD;}
        else if(s[i] == t[i] && s[i+1] == t[i+1]){res*=2;res%=MOD;}
        else {res *=2; res %= MOD;}
      }
    }
    cout << res << endl;
  }
