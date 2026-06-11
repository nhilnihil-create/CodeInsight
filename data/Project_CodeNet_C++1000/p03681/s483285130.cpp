#include<iostream>

#define ll long long

using namespace std;

int main(){
   int n, m, dif;
   ll b, s, ans = 1;

   cin >> n >> m;
   b = max(n, m);
   s = min(n, m);
   dif = b - s;

   if(dif >= 2){
      ans = 0;
   }else if(dif == 1){
      while(s > 0){
         ans *= s--;
         ans %= 1000000007;
      }
      ans *= ans;
      ans %= 1000000007;
      ans *= b;
      ans %= 1000000007;

   }else{
      while(s > 0){
         ans *= s--;
         ans %= 1000000007;
      }
      ans *= ans;
      ans %= 1000000007;
      ans *= 2;
      ans %= 1000000007;
   }

   cout << ans << endl;
}