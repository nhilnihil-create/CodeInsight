#include <bits/stdc++.h>
using namespace std;

int main(){
  long long n, p;
  cin >> n >> p;
  long long odd = 0;
  for(int i = 0; i < n; i++){
    int k;
    cin >> k;
    if(k%2) odd++;
  }
  
  long long ans = 0;
  if(odd == 0 && !p) ans = pow(2, n);
  if(odd > 0) ans = pow(2, n-1);
  
  cout << ans << endl;
}