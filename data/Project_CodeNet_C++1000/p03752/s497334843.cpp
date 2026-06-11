#include <bits/stdc++.h>

using namespace std;

int main(){
  int n,k;
  cin >> n >> k;
  vector<long long> A(n);
  for(int i=0;i<n;i++){
    cin >> A[i];
  }
  long long ret = 1e18;
  for(int i=0;i<1<<(n-1);i++){
    int cnt = 0;
    for(int j=0;j<n-1;j++){
      cnt += (i>>j)&1;
    }
    if(cnt!=k-1)continue;
    long long tmp = 0;
    long long now = A[0];
    for(int j=0;j<n-1;j++){
      if(i>>j &1){
        if(now>=A[j+1]){
          tmp+=now+1-A[j+1];
        }
        now = max(now+1,A[j+1]);
      }
      now = max(now,A[j+1]);
    }
    ret = min(ret,tmp);
  }
  cout << ret << endl;
  return 0;
}
