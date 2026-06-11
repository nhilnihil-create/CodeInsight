#include <bits/stdc++.h>
#include <math.h>
#define _GLIBCXX_DEBUG
#define _LIBCPP_DEBUG 0

using namespace std;
#define ll long long
#define rep(i,n) for (int i = 0; i < n; i++)
#define MOD (1000000007)
#define vi vector<int>
#define vl vector<ll>
#define vvi vector<vi>
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(),(a).end()

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int gcd(int a, int b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}

const ll INF = 1LL << 60;

const int dh[4] = {1,0,-1,0};
const int dw[4] = {0,1,0,-1};


int main(){
  int n; string s1,s2;
  cin >> n >> s1 >> s2;

  ll dp[n] = {};
  if(s1[0] == s2[0]) dp[0] = 3;
  else dp[0] = 6;
  for (int i = 1; i < n; i++) {
    if(s1[i] == s2[i]){
      if(s1[i-1] == s2[i-1]) dp[i] = dp[i-1]*2;
      else dp[i] = dp[i-1];
    }
    else{
      if(s1[i] == s1[i-1]) dp[i] = dp[i-1];
      else if(s1[i-1] == s2[i-1]) dp[i] = dp[i-1]*2;
      else if(s1[i-1] != s2[i-1]) dp[i] = dp[i-1]*3;
    }
    dp[i] %= MOD;
  }

  std::cout << dp[n-1] << '\n';
}
