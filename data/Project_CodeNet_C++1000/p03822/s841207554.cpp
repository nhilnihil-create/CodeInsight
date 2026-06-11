#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

vector<int>to[100010];
int dp[100010];

int rec(int v){
  if(dp[v]!=0)return dp[v];
  vector<int>num;
  for(int u:to[v]){
    num.push_back(rec(u));
  }
  sort(num.begin(),num.end());
  int cnt=0;
  rep(i,num.size()){
    cnt=max(cnt,num[i]);
    cnt++;
  }
  dp[v]=cnt;
  return dp[v];
}

int main(){
  int n;
  cin>>n;
  for(int i=2; i<=n; ++i){
    int a; cin>>a;
    to[a].push_back(i);
  }
  rec(1);
  cout<<dp[1]<<endl;
}