#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")

#include "bits/stdc++.h"

using namespace std;

#define pb push_back
#define F first
#define S second
#define f(i,a,b)  for(int i = a; i < b; i++)
#define endl '\n'
using ll = long long;
#define int ll
using db = long double;
using ii = pair<int, int>;

const int N = 1e5 + 5, LG = 19, MOD = 998244353;
const int SQ =320;
const long double EPS = 1e-7;
int a[N],n;
vector<int> adj[N];
int solve(int node){
  vector<int> v;
  for(auto x : adj[node]){
    v.push_back(1 + solve(x));
  }
  sort(v.rbegin(),v.rend());
  int mx = 0;
  for(int i = 0; i < v.size(); i++)mx=max(mx,i+v[i]);
  return mx;
}
int32_t main(){
#ifdef ONLINE_JUDGE
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif

  cin >> n;

  f(i,2,n+1){
    cin >> a[i];
    adj[a[i]].push_back(i);
  }

  cout << solve(1) << '\n';


  return 0;
}
