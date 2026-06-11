#include <iostream>
using namespace std; 

#define ll long long

int main(){
   ll n , a , b; 
   cin >> n >> a >> b; 

   ll max = a + (n-1)*b;
   ll min = b + (n-1)*a;
   ll ans = max - min + 1;

   if(ans < 0){
     ans = 0;
   }

    cout << ans << endl;
}