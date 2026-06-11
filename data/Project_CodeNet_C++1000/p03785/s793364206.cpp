#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, c, k;
  cin >> n >> c >> k;
  int T[n];
  for(int i=0; i<n; ++i) cin >> T[i];
  sort(T, T+n);
  int ans = 0;
  for(int i=0; i<n;){
    ++ans;
    int st = i;
    while(i < n && T[i]-T[st] <= k && i-st < c) ++i;
  }
  cout << ans << endl;
}