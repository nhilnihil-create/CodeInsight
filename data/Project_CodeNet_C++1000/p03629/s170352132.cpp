#include <iostream>
#include <stdio.h>
#include <fstream>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <limits.h>
#include <math.h>
#include <functional>

#define repeat(i,n) for (long long i = 0; (i) < (n); ++ (i))
#define debug(x) cerr << #x << ": " << x << '\n'
#define debugArray(x,n) for(long long i = 0; (i) < (n); ++ (i)) cerr << #x << "[" << i << "]: " << x[i] << '\n'

using namespace std;

typedef long long ll;
typedef pair<int,int> Pii;
typedef vector<int> vint;
typedef vector<ll> vll;
const ll INF = INT_MAX;
const ll MOD = 1e9+7;

int dp[2*112345];
int main() {
  string A;
  cin >> A;
  vector<vint> pos(26);
  repeat(i,A.length()){
    pos[A[i]-'a'].push_back(i);
  }
  repeat(c,26){
    pos[c].push_back(A.length());
  }
  dp[A.length()-1]=1;
  int flag=0;
  for(int i=A.length()-1;i>=0;i--){
    //debug(bitset<26>(flag));
    dp[i] += dp[i+1];
    flag |= 1<<(A[i]-'a');
    if(flag == (1<<26)-1){
      flag = 0;
      dp[i]++;
    }
  }
  debugArray(dp,A.length()+1);
  string ans="";
  int idx=0;
  while(idx < A.length()){
    //debug(idx);
    //debug(ans);
    repeat(c,26){
      int nidx = *lower_bound(pos[c].begin(),pos[c].end(),idx)+1;
      if(dp[idx] == dp[nidx]+1){
        ans += c+'a';
        idx = nidx;
        break;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
