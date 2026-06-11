#include <bits/stdc++.h>
#include <math.h>
#define _GLIBCXX_DEBUG
#define _LIBCPP_DEBUG 0

using namespace std;
#define ll long long
#define rep(i,n) for (int i = 0; i < n; i++)
#define MOD (1000000007)
#define vi vector<int>
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

ll dp[60][2];

int main(){
  int n; cin >> n;
  string s1,s2; cin >> s1 >> s2;

  if(s1[0] == s2[0]){
    dp[0][0] = 3LL;
    dp[0][1] = 0LL;
  }
  else{
    dp[0][0] = 0LL;
    dp[0][1] = 6LL;
  }

  for(int i = 1; i < n; i++){
    // dp[i][0] の決定
    if(s1[i] == s2[i]){
      if(s1[i-1] == s2[i-1]) dp[i][0] += dp[i-1][0]*2;
      else dp[i][0] += dp[i-1][1];
      dp[i][0] %= MOD;
    }
    else{
      if(s1[i-1] == s1[i]) dp[i][1] = dp[i-1][1];
      else{
        if(s1[i-1] == s2[i-1]) dp[i][1] += dp[i-1][0]*2;
        else dp[i][1] += dp[i-1][1]*3;
      }
      dp[i][1] %= MOD;
    }
  }
  if(s1[n-1] == s2[n-1]) std::cout << dp[n-1][0] << '\n';
  else std::cout << dp[n-1][1] << '\n';
}
