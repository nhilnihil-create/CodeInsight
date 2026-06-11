#include <iostream>

using namespace std;

int main(int argc, char const *argv[]){
   int a,b,p;
   cin >> a >> b;
   if(a <= 0 && b >= 0){
      cout << "Zero" << endl;
      return 0;
   }
   p = 1;
   for(int i = a;i <= b;i++){
      if(i<0){
         p *= -1;
      }
   }
   if(p < 0){
      cout << "Negative" << endl;
   }else{
      cout << "Positive" << endl;
   }
   return 0;
}