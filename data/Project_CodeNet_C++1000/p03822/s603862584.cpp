#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define repe(i,n) rep(i,(n)+1)
#define per(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define pere(i,n) rep(i,(n)+1)
#define all(x) (x).begin(),(x).end()
#define SP <<" "<<
#define MOD 1000000007
#define IINF 1000000000
#define LINF 1000000000000000000

typedef long long LL;
typedef long double LD;

int main(){
  int n;
  cin >> n;
  vector<int> deg(n,0);
  vector<int> a(n);
  vector<vector<int>> dp(n);
  for(int i=1;i<n;i++){
    cin >> a[i];
    a[i]--;
    deg[a[i]]++;
  }
  queue<int> que;
  for(int i=0;i<n;i++){
    if(deg[i]==0){
      dp[a[i]].push_back(0);
      deg[a[i]]--;
      // cout << i+1 SP 0 << endl;
      if(deg[a[i]]==0) que.push(a[i]);
    }
  }
  int now;
  int ans=0;
  while(!que.empty()){
    now=que.front();
    que.pop();
    int ans=0;
    sort(all(dp[now]));
    for(int i=0;i<dp[now].size();i++){
      ans=max(ans,dp[now][i]-i);
    }
    ans+=dp[now].size();
    // cout << now+1 SP ans << endl;
    if(now==0){
      cout << ans << endl;
      return 0;
    }
    dp[a[now]].push_back(ans);
    deg[a[now]]--;
    if(deg[a[now]]==0) que.push(a[now]);
  }
  return 0;
}