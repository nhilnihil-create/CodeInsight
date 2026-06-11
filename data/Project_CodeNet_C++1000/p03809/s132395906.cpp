#include <bits/stdc++.h>
using namespace std;
typedef long long kaage;
#define int kaage
signed main() {
  int N;
  cin >> N;
  vector<int>A(N);
  for(int i = 0; i < N; i++){
    cin >> A[i];
  }
  vector<vector<int>>ki(N);
  for(int i = 0; i < N-1; i++) {
    int a,b;
    cin >> a >> b;
    a--;b--;
    ki[a].push_back(b);
    ki[b].push_back(a);
  }
  queue<int>que;
  que.push(0);
  vector<int>cnt(N,-1);
  cnt[0] = 0;
  while(!que.empty()) {
    int x = que.front();
    que.pop();
    for(int i = 0; i < ki[x].size(); i++) {
      if(cnt[ki[x][i]] == -1) {
        cnt[ki[x][i]] = cnt[x]+1;
        que.push(ki[x][i]);
      }
    }
  }
  vector<vector<int>>cnt2(N);
  vector<int>res(N);
  int mx = 0;
  for(int i = 0; i < N; i++) {
    if(ki[i].size() == 1){
      res[i] = A[i];
    }
    mx = max(mx,cnt[i]);
    cnt2[cnt[i]].push_back(i);
  }
  for(int i = mx-1; i >= 1; i--) {
    for(int j = 0; j < cnt2[i].size(); j++){
      if(ki[cnt2[i][j]].size() == 1){
        continue;
      }
      int sum = 0,MX = 0;
      for(int k = 0; k < ki[cnt2[i][j]].size(); k++) {
        if(cnt[ki[cnt2[i][j]][k]]-1 == cnt[cnt2[i][j]]) {
          sum += res[ki[cnt2[i][j]][k]];
          MX = max(MX,res[ki[cnt2[i][j]][k]]);
        }
      }
      if(A[cnt2[i][j]] >= MX && A[cnt2[i][j]]*2 >= sum && A[cnt2[i][j]] <= sum){
        res[cnt2[i][j]] = A[cnt2[i][j]]*2-sum;
      }
      else {
        cout << "NO" << endl;
        return 0;
      }
    }
  }
  int sum = 0;
  for(int i = 0; i < ki[0].size(); i++) {
    sum += res[ki[0][i]];
  }
  if(ki[0].size() == 1) {
    if(sum != A[0]) {
      cout << "NO" << endl;
      return 0;
    }
  }
  else if(sum != A[0]*2) {
    cout << "NO" << endl;
    return 0;
  }
  cout << "YES" << endl;
}