#include<iostream>
#include<string>

using namespace std;

int main(){
   int count2, count4, n, a;
   string ans = "No";

   cin >> n;
   count2 = 0;
   count4 = 0;
   for(int i = 0; i < n; i++){
      cin >> a;
      if(a % 2 == 0){
         if(a % 4 == 0){
            count4++;
         }else{
            count2++;
         }
      }
   }

   if(count4 >= n / 2 || (n - count4 * 2 <= count2)) ans = "Yes";
   cout << ans << endl;
}