#include <bits/stdc++.h>
using namespace std;
 
int main(){
  long long int n;
  cin >> n;
  long long int mod = 1e9+7;
  long long int a[1050] = {};
  for(int i=2; i<=n; i++){
    int num = i;
    for(int j=2; j<=1000; j++){
      while(num%j==0){
        a[j]++;
        num /= j;
      }
    }
  }
  long long int ans = 1;
  for (int i = 2; i <= n; i++){
    ans *= a[i] + 1;
    ans %= mod;
  }
  cout << ans << endl;
  return 0;
}

