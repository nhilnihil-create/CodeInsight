#include <bits/stdc++.h>
using namespace std;
#define N 1000000007
int main() {
  int n, m;
  cin >> n >> m;
  if(n==m){
    int64_t ans=2;
    for(int i=1; i<=n; i++)
      ans=ans*i%N;
    for(int i=1; i<=m; i++)
      ans=ans*i%N;
    cout << ans;
    return 0;
  }
  if(abs(n-m)==1){
    int64_t ans=1;
    for(int i=1; i<=n; i++)
      ans=ans*i%N;
    for(int i=1; i<=m; i++)
      ans=ans*i%N;
    cout << ans;
    return 0;
  }
  cout << 0;
  return 0;
}