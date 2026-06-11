#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, sum = 1, ans = 0;
  cin >> n;
  if(n == 1){ cout << 1 << endl; return 0; }
  long long a[n];
  for(int i=0; i<n; ++i) cin >> a[i];
  sort(a, a+n);
  for(int i=0; i<n; ++i){
    if(i < n && a[i] == a[i+1]){
      ++sum;
    }else{
      if(sum%2 != 0 || (i == n-1 && a[i-1] != a[i])) ++ans;
      sum = 1;
    }
  }
  cout << ans << endl;
}