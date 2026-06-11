#include <bits/stdc++.h>
using namespace std;
template <typename T> bool chmax(T &u, const T z) { if (u < z) {u = z; return true;} else return false; }
template <typename T> bool chmin(T &u, const T z) { if (u > z) {u = z; return true;} else return false; }
#define rep(i, n) for (long long i = 0; i < (long long)(n); i++)
#define ll long long
typedef pair<ll, ll> P;
const ll INF = 1LL << 60;
//const int MOD = 1000000007;
const ll MOD=998244353;
ll gcd(ll x, ll y) { return y ? gcd(y, x % y) : x; }

int main(){
  int k,t;
  cin>>k>>t;
  priority_queue<int>a;
  rep(i,t){
    int x;
    cin>>x;
    a.emplace(x);
  }
  int x=a.top();a.pop();
  if(x*2<=k)cout<<0<<endl;
  else cout<<x*2-k-1<<endl;
  return 0;
}