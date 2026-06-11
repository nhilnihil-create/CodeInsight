#include <bits/stdc++.h>

using namespace std;

int n, a[100010];

int main(){
  cin >> n;
  for (int i=1; i <= n; i++) cin >> a[i];
  int ans = 0; 
  int ted = 0;
  for (int i = 1; i <= n; i++){
      if (a[i] == i) ted++;
    else ans += (ted / 2) + ted % 2, ted = 0;
  }
  ans += (ted / 2) + ted % 2;
  cout << ans;
  
  return 0;
  
}
