#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#pragma comment(linker, "/STACK:2000000")

#include "bits/stdc++.h"

using namespace std;

#define pb push_back
#define F first
#define S second
#define f(i,a,b)  for(int i = a; i < b; i++)
// #define endl '\n'
using ll = long long;
using db = long double;
using ii = pair<int, int>;

const int N = 2e5 + 5, LG = 19, MOD = 998244353;
const int SQ =320;
const long double EPS = 1e-7;
vector<ll> sum;
int n, k, x;
int bit[N];
void upd(int x){for(++x;x<N;x+=x&-x)bit[x]++;}
int get(int x, int res = 0){for(;x;x-=x&-x)res+=bit[x];  return res;}
int32_t main(){
#ifdef ONLINE_JUDGE
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif

  cin >> n >> k;
  sum.push_back(0);
  f(i,0,n){
    cin >> x;
    sum.push_back(sum.back()+x-k);
  }

  auto ord=sum;
  sort(ord.begin(),ord.end());
  ord.resize(unique(ord.begin(),ord.end())-ord.begin());

  ll ans = 0;

  upd(lower_bound(ord.begin(),ord.end(),0)-ord.begin());
  ////sum-x>=0
  f(i,1,n+1){
    ans+=get(upper_bound(ord.begin(),ord.end(),sum[i])-ord.begin());
    upd(lower_bound(ord.begin(),ord.end(),sum[i])-ord.begin());
  }

  cout << ans << '\n';


  return 0;
}
