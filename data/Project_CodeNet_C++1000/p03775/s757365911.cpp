#include <bits/stdc++.h>
using namespace std;

int c(long a, long b){
  int r = 0, cnt = 0;
  while(a){
    r++;
    a /= 10;
  }
  while(b){
    cnt++;
    b /= 10;
  }
  return max(r, cnt);
}

int main(){
  long n;  cin >> n;
  int ans = 1e9;
  long start = 1;
  while(start*start <= n)  start++;

  while(start--){
    if(n % start == 0){
      ans = min(ans, c(start, n/start));
      break;
    }
  }
  cout << ans << endl;

  return 0;
}
