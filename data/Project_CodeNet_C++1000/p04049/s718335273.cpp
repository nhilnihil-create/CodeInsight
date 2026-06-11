#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back 
#define pf push_front 
#define pbp pop_back
#define pfp pop_front 
#define sz(x) x.size()
#define all(x) x.begin(),x.end() 
#define ios_base ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define open(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout)
#define F first
#define S second

using namespace std;

typedef unsigned long long ul;
typedef long long ll;
typedef long double ld;

const int mod = 1e9+7;
const int N = 3*1e3+123;
const int inf = 1e9+123;
const long long INF = 1e18;
const double eps = 1e-5;

int n, k, a[N], k1, k2, ans, mn = inf;
vector <int> v[N];
int x[N], y[N];
void dfs(int x, int p, int d){
 if(d > k1){
  ans ++;
 }
 for(int i = 0; i < sz(v[x]); i ++){
  int to = v[x][i];
  if(to != p) dfs(to, x,  d + 1);
 }
}

int main (){
 cin >> n >> k;
 for(int i = 1; i < n; i ++){
  cin >> x[i] >> y[i];
  v[x[i]].pb(y[i]);
  v[y[i]].pb(x[i]);
 }
 k1 = k / 2;
 if(k % 2 == 0){
  for(int i = 1; i <= n; i ++){
   dfs(i, i, 0);
   mn = min(ans, mn);
   ans = 0;
  }
 }else{
  for(int i = 1; i < n; i ++){
   dfs(x[i], y[i], 0);
   dfs(y[i], x[i], 0);
   mn = min(mn, ans);
   ans = 0;
  }
 }
 cout << mn;
 return  0;
}

