#include<bits/stdc++.h>
using namespace std;

int main() {
  long long N,x,M;
  cin >> N >> x;
  M = N * 2 - 1;
  if (x == 1 || x == M) {
    cout << "No" << endl;
    return 0;
  }
  else {
    cout << "Yes" << endl;
  }
  
  if (N == 2) {
    cout << 1 << endl << 2 << endl << 3 << endl;
    return 0;
  }
  
  vector<long long> ans (M,-1);
  vector<bool> used (M+1,false);
  used[x] = true;
  
  if (x < N) {
    ans[N-1] = x;
    ans[N] = x+1;
    ans[N-2] = 1;
    ans[N-3] = x+2;
    used[x+1] = true;
    used[x+2] = true;
    used[1] = true;
  }
  else {
    ans[N-1] = x;
    ans[N] = x-1;
    ans[N-2] = M;
    ans[N-3] = x-2;
    used[x-1] = true;
    used[x-2] = true;
    used[M] = true;
  }
  
  long long now = 1;
  
  for (int i=0; i<M; i++) {
    while (used[now]) {
      now++;
    }
    if (ans[i] != -1) continue;
    ans[i] = now;
    used[now] = true;
  }
  
  for (int i=0; i<M; i++) {
    cout << ans[i] << endl;
  }
  
}