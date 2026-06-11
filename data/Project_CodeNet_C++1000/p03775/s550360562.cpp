#include <bits/stdc++.h>
using namespace std;
#define int long long

int countDigits(int x){
   int cnt = 0;
   while(x){
      cnt++;
      x /= 10;
   }
   return cnt;
}

int32_t main() 
{
  ios::sync_with_stdio(0); 
  cin.tie(0); cout.tie(0);
 

  int n;
  cin >> n;
   
  int ans = 12;

  for(int i = 1; i * i <= n; i++){
      if(n % i) continue;
      
      int temp = countDigits(i);
      temp = max(temp, countDigits(n / i));
      ans = min(ans, temp);
  }

  cout << ans;

  return 0;
}