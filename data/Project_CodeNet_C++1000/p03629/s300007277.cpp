#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
#include <iomanip>
#include <limits>
#include <list>
#include <queue>
#include <tuple>
#include <map>
#include <stack>
#include <set>
using namespace std;
#define MOD (long long int)(1e9+7)
#define ll long long int
#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define reps(i,n) for(int i=1; i<=(int)(n); i++)
#define REP(i,n) for(int i=n-1; i>=0; i--)
#define REPS(i,n) for(int i=n; i>0; i--)
#define INF (int)(1123456789)
#define LINF (long long int)(112345678901234567)
#define chmax(a, b) a = (((a)<(b)) ? (b) : (a))
#define chmin(a, b) a = (((a)>(b)) ? (b) : (a))
#define all(v) v.begin(), v.end()

const int N = (int)3e5;

ll mpow(ll a, ll b){
  if(b==0) return 1;
  else if(b%2==0){ll memo = mpow(a,b/2); return memo*memo%MOD;}
  else return mpow(a,b-1) * a % MOD;
}
ll gcd(ll a, ll b){
  if(b==0) return a;
  else return gcd(b, a%b);
}
vector<ll> kaijo_memo;
ll kaijo(ll n){
  if(kaijo_memo.size() > n) return kaijo_memo[n];
  if(kaijo_memo.size() == 0) kaijo_memo.push_back(1);
  while(kaijo_memo.size() <= n) kaijo_memo.push_back(kaijo_memo[kaijo_memo.size()-1] * kaijo_memo.size() % MOD);
  return kaijo_memo[n];
}
ll nCr(ll n, ll r){
  if(n < r || r < 0) return 0;
  ll ret = 1;
  ret *= kaijo(n); ret %= MOD;
  ret *= mpow(kaijo(r), MOD-2); ret %= MOD;
  ret *= mpow(kaijo(n-r), MOD-2); ret %= MOD;
  return ret;
}

string A;
//dp[i] i番目の要素にとって最速である(手数, 次のidx)
vector<pair<int,int>> dp;
vector<char> memo;
vector<vector<int>> nex;

int saiki(int now){
  //cerr<<now<<endl;
  if(dp[now].second != -1){
    return dp[now].first;
  }
  int mini = INF;
  rep(j,26){
    int ret = saiki(nex[now][j]);
    if(mini > ret){
      dp[now].first = ret + 1;
      dp[now].second = nex[now][j];
      mini = ret;
      memo[now] = j;
    }
  }
  return dp[now].first;
}

int main(void){
  cin>>A;
  int n = A.size();
  vector<vector<int>> next;
  A = "0" + A + "0";
  rep(i, n+2){
    next.push_back(vector<int>());
    rep(j,26){
      next[i].push_back(n+1);
    }
  }
  rep(i,n+2){
    dp.push_back({INF,-1});
    memo.push_back(-1);
  }
  dp[n+1].first = 0;
  dp[n+1].second = 0;
  cerr<<"mo"<<endl;
  rep(j,26){
    int idx = n+1;
    REP(i, n+2){
      next[i][j] = idx;
      if(A[i]-'a' == j){
        idx = i;
      }
    }
  }
  /*rep(i,n+2){
    rep(j,26){
      cerr<<next[i][j]<<" ";
    }
    cerr<<endl;
  }*/
  cerr<<"Hoge"<<endl;
  nex = next;
  saiki(0);
  cerr<<"unya"<<endl;
  /*rep(i,n+2){
    cerr<<i<<" "<<dp[i].first<<" "<<dp[i].second<<" "<<(char)(memo[i]+'a')<<endl;
  }*/
  int now = 0;
  while(now != n+1){
    cout<<(char)(memo[now]+'a');
    now = dp[now].second;
  }
  cout<<endl;
  return 0;
}
