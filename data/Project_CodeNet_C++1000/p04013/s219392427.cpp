#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define REP(i,s,n) for(int i = s; i < n; i++)
typedef long long ll;
using namespace std;
using Graph = vector<vector<int>>;
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { return (a * b) / gcd(a,b); }
ll ceil(const ll a, const ll b) { return (a + b - 1) / b; }
int main(){
  int n,a;
  cin >> n >> a;
  vector<int>x(n);
  rep(i,n){
    cin >> x[i];
    x[i] -= a;
  }
  map<ll,ll>dp;
  dp[0] = 1;
  rep(i,n){
    map<ll,ll>tmp;
    for(auto j : dp){
      tmp[j.first + x[i]] += j.second;
      tmp[j.first] += j.second;
    }
    dp = tmp;
  }
  cout << dp[0] - 1 << endl;
  return 0;
}
