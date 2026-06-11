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
using db = long double;
using ii = pair<int, int>;
const int N = 300 * 4, MX = 2e6, LG = 19, MOD = 1e9 + 7;
const int SQ =225;
const long double EPS = 1e-7;
vector<int> solve(ll n){
  if(n == 2)
    return vector<int>({1});
  if(n&1){
    vector<int> x = solve(n-1);
    int val = *max_element(x.begin(),x.end());
    x.insert(x.begin(), val + 1);
    return x;
  } else {
    vector<int> x = solve(n>>1);
    int val = *max_element(x.begin(),x.end());
    x.pb(val + 1);
    return x;
  }
}
int32_t main(){
#ifdef ONLINE_JUDGE
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif
  ll n;
  cin >> n;
  auto out = solve(n+1);
  cout<<out.size()*2<<'\n';
  for(auto x : out)cout << x << " ";
  f(i,0,out.size())cout << i + 1 << " ";

  return 0;
}
