#include <bits/stdc++.h>
using namespace std;



int main() {
 int a,b,c; cin >> a >> b >> c;
 if(a == b && b == c && a % 2 == 0) {
   cout << -1 << endl;
   return 0;
 }

 int ans = 0;
 while(true) { 
   int tempA = a;
   int tempB = b;
   int tempC = c;
   if(a % 2 != 0 || b % 2 != 0 || c % 2 != 0) {
     break;
   } 
   ans ++;
   
   a = (tempB/2) + (tempC/2);
   b = (tempA/2) + (tempC/2);
   c = (tempA/2) + (tempB/2);   
 }
  
  cout << ans << endl;
  
  return 0;
}