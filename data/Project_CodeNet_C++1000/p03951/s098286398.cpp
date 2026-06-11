#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
int main() {
  int a;
 string b,c;
      
  cin >> a;
    cin >>b;
    cin >>c;
  
   for(int i=0;i<a;i++){
     
       if(b.substr(i) ==c.substr(0,a-i)){
         
         cout << i+a << endl;
       
     return 0;
       }
     
   }
   
  
  cout << 2*a << endl;
}
