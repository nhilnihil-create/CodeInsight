#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
vector<int> dt[26];
int dp[200001][26];
int nx[200001][26];
int n;
string s;
int solve(int in, int c){
  if(in == n)
    return 1;
  if(dp[in][c] != -1)
    return dp[in][c];
  auto it = lower_bound(dt[c].begin(), dt[c].end(), in);
  if(it == dt[c].end())
    return 1;
  int mn = 1000000;
  for(int i = 0;i < 26;i++){
    if(1 + solve(*it + 1, i) < mn){
      mn = 1 + solve(*it + 1, i);
      nx[in][c] = i;
    }
  }
  return dp[in][c] = mn;
}
void recon(int in, int c){
  cout << char(c + 'a');
  auto it = lower_bound(dt[c].begin(), dt[c].end(), in);
  if(it == dt[c].end())
    return;
  recon(*it + 1, nx[in][c]);
}
signed main()
{
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  memset(dp, -1, sizeof(dp));
  memset(nx, -1, sizeof(nx));
  cin >> s;
  n = s.size();
  for(int i = 0;i < n;i++)
    dt[s[i] - 'a'].push_back(i);
  int ans = 10000000;
  int ain = 0;
  for(int i = 0;i < 26;i++){
    int x = solve(0, i);
    if(x < ans){
      ans = x;
      ain = i;
    }
  }
  recon(0, ain);
}
