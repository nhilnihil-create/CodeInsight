#include<iostream>

using namespace std;

int main(){
   int x, a, b;
   cin >> x >> a >> b;
   if(a >= b){
      cout << "delicious" << endl;
   }else{
      if(a + x >= b){
         cout << "safe" << endl;
      }else{
         cout << "dangerous" << endl;
      }
   }
}