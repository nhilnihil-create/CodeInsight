#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int n;
  cin >> n;
  int a[n];
  int s = 0;
  for (int i=0; i<n; i++){
    cin >> a[i];
    s += a[i];
  }
  
  int ans = 0;
    
  if (s % n == 0) {
      int x = s/n;
      for (int i: a){
        ans += (x - i)*(x - i);
      }
  }
  else {
      int x1 = ceil((double) s/n);
      int x2 = floor((double) s/n);
      int ans1 = 0;
      int ans2 = 0;
      for (int i: a){
          ans1 += (x1 - i)*(x1 - i);
          ans2 += (x2 - i)*(x2 - i);
      }
      if (ans1 > ans2){
          ans = ans2;
      }
      else{
          ans = ans1;
      }
  }
      
  
  
  cout << ans;
}