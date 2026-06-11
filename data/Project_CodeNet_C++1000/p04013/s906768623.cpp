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

ll dp[51][51][2501];
int main(){
  //dp[i][j][k]
  //i番目までj個使って合計k
  int N, A; cin >> N >> A;
  vector<int> x(N); rep(i,N) cin >> x[i];
  dp[0][0][0]=1;
  for(int i=1;i<=N;i++){
    for(int j=0;j<=i;j++){
      for(int k=0;k<=2500;k++){
        dp[i][j][k] += dp[i-1][j][k];
        if(k-x[i-1]>=0 && j) dp[i][j][k] += dp[i-1][j-1][k-x[i-1]];
      }
    }
  }
  ll ans = 0;
  for(int j=1;j<=N;j++){
    ans += dp[N][j][A*j];
  }
  cout << ans << endl;
  return 0;
}
