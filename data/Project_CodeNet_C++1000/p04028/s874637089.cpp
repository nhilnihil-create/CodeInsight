#include <iostream>
#include <stdio.h>
#include <fstream>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <limits.h>
#include <math.h>
#include <functional>
#include <bitset>

#define repeat(i,n) for (long long i = 0; (i) < (n); ++ (i))
#define debug(x) cerr << #x << ": " << x << '\n'
#define debugArray(x,n) for(long long i = 0; (i) < (n); ++ (i)) cerr << #x << "[" << i << "]: " << x[i] << '\n'
#define debugArrayP(x,n) for(long long i = 0; (i) < (n); ++ (i)) cerr << #x << "[" << i << "]: " << x[i].first<< " " << x[i].second << '\n'

using namespace std;

typedef long long ll;
typedef pair<int,int> Pii;
typedef vector<int> vint;
typedef vector<ll> vll;
const ll INF = INT_MAX;
const ll MOD = 1e9+7;

ll dp[5001][5001];

ll dfs(int n,int s){
  if(n<0||n<s||s<0)return 0;
  if(dp[n][s]) return dp[n][s];
  if(n==s) return dp[n][s]= 1;
  return dp[n][s] = (dfs(n-1,max(0,s-1))+2*dfs(n-1,s+1))%MOD;
}

int main() {
  int N;cin >> N;
  string s;cin >> s;
  cout << dfs(N,s.length()) << endl;
  return 0;
}
