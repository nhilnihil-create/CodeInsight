#include <bits/stdc++.h>
using namespace std;

//repetition
#define FOR(i,a,b) for(ll i=(a);i<(b);++i)
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)

//container util
#define all(x) (x).begin(),(x).end()

//typedef
typedef long long ll;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<ll> VLL;
typedef vector<VLL> VVLL;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;


//conversion
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
inline ll toLL(string s) {ll v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}


string s;
int n;

bool check(string ans){
  vector<vector<bool>> dp(101010,vector<bool>(2,false));

  if(ans[0] == 'S'){
    dp[0][0] = true;
  }else{
    dp[0][1] = true;
  }

  if(ans[1] == 'S'){
    dp[1][0] = true;
  }else{
    dp[1][1] = true;
  }

  FOR(i,1,n){

    if('o' == s[i]){
      //両方 Seep
      if(dp[i-1][0] && dp[i][0]){
        dp[i+1][0] = true;
        ans += 'S';
        continue;
      }
      if(dp[i-1][1] && dp[i][0]){
        dp[i+1][1] = true;
        ans += 'W';
        continue;
      }
      //片方はSeep
      if(dp[i-1][0] && dp[i][1]){
        dp[i+1][1] = true;
        ans += 'W';
        continue;
      }
      if(dp[i-1][1] && dp[i][1]){
        dp[i+1][0] = true;
        ans += 'S';
        continue;
      }
    }
    if('x' == s[i]){
      //片方はwolf
      if(dp[i-1][0] && dp[i][0]){
        dp[i+1][1] = true;
        ans += 'W';
        continue;
      }
      if(dp[i-1][1] && dp[i][0]){
        dp[i+1][0] = true;
        ans += 'S';
        continue;
      }
      //両方同じ
      if(dp[i-1][0] && dp[i][1]){
        dp[i+1][0] = true;
        ans += 'S';
        continue;
      }
      if(dp[i-1][1] && dp[i][1]){
        dp[i+1][1] = true;
        ans += 'W';
        continue;
      }
    }


  }

  bool flag = false;
  if(dp[n][0] && dp[0][0]){//Sheep
    if(s[0] == 'o'){//Sheep
      if(ans[1] == ans[n-1]) flag = true;
    }
    else{
      if(ans[1] != ans[n-1]) flag = true;
    }
  }

  if(dp[n][1] && dp[0][1]){
    if(s[0] == 'o'){//wolf
      if(ans[1] != ans[n-1]) flag = true;
    }
    else{
      if(ans[1] == ans[n-1]) flag = true;
    }
  }
  if(flag){
    cout << ans.substr(0,n) << endl;
  }
  return flag;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    cin >> s;
    if(check("SS")) return 0;
    if(check("SW")) return 0;
    if(check("WS")) return 0;
    if(check("WW")) return 0;

    cout << -1 << endl;

    return 0;
}
