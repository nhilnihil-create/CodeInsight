#include <bits/stdc++.h>
using namespace std;

int n, size;
int memo[5010][5010];

#define MOD 1000000007

long long pow_mod(long long n, long long m){
  int ans = 1;
  while(m > 0){
    if(m & 1) ans = (ans * n) % MOD;
    n = (n*n) % MOD;
    m >>= 1;
  }
  return ans;
}

long long dfs(int i, int s){
  if(memo[i][s] != -1) return memo[i][s];
  if(i == n){
    if(s == size){
      return 1;
    }else{
      return 0;
    }
  }

  return memo[i][s] = (dfs(i+1,min(s+1,5000))*2 + dfs(i+1,max(s-1,0))) % MOD;
}

int main(){
  cin >> n;
  string s;
  cin >> s;
  size = s.size();

  memset(memo,-1,sizeof(memo));
  cout << (dfs(0, 0) * pow_mod(pow_mod(2,size),MOD-2)) % MOD << endl;
  return 0;
}
