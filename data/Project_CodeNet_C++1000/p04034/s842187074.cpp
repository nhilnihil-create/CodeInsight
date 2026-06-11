#include <bits/stdc++.h>

using ll = long long;
using namespace std;
const int INFint = 2e9+1;
const ll INFll = 2e18+1;
ll MOD=1e9+7;

int main(){
  int N,M;
  cin>>N>>M;
  vector<int> x(M),y(M);
  for(int i(0);i<M;i++){
    cin>>x[i]>>y[i];
  }
  vector<int> ans(N+1,0);
  ans[1] = 1;
  vector<int> cnt(N+1,1);
  for(int i(0);i<M;i++){
    if(ans[x[i]] == 1){
      if(cnt[x[i]] > 1){
        ans[y[i]] = 1;
      }else{
        ans[y[i]] = 1;
        ans[x[i]] = 0;
      }
    }
    cnt[x[i]]--;
    cnt[y[i]]++;
  }
  int cnti(0);
  for(int i(1);i<=N;i++){
    //cout << i << " " << ans[i] << endl;
    if(ans[i]) cnti++;
  }
  cout << cnti << endl;
  return 0;
}
